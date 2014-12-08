#pragma once

/*
Global planner
A* path optimization

Author: Niti Madhugiri

*/

#include "VehicleState.h"
#include "AngularVelocity.h"
#include "Orientation.h"
#include "VehicleAttitudeHelpers.h"

#include <vector>
#include <map>


#include "rim/rimEngine.h"

#include "Roadmap.h"

//using namespace std;
using namespace rim;
using namespace rim::math;


/// Define a less-than comparison operator for the Vector3f.
namespace rim { namespace math {
inline bool operator < ( const Vector3f& a, const Vector3f& b )
{
	return a.x < b.x && a.y < b.y && a.z < b.z;
}
}; };



typedef std::vector<Vector3f> vertices;

class Global_planner
{
public:

	//path cost to landmark
	float cost(Vector3f landmark, Vector3f start, std::map<Vector3f,Vector3f> parent )
	{
		
		if(landmark == start)
		{
			return 0;
		}
		else
		{
			return (landmark.getDistanceTo(parent[landmark]) + cost(parent[landmark],start,parent));

		}

	}

	//f_score for a landmark
	float costheur(Vector3f landmark, Vector3f start, Vector3f goal, std::map<Vector3f,Vector3f> parent)
	{
		return (cost(landmark, start, parent) + landmark.getDistanceTo(goal));
	}

	//path reconstruction
	vertices reconstructpath(std::map<Vector3f,Vector3f> came,Vector3f current_node)
{
	vertices pp;

	std::map<Vector3f,Vector3f>::iterator i1 = came.find(current_node);
	
	if (i1==came.end())
	{ 
		pp.push_back(current_node);
		return pp;
	}
	else
	{
		pp = reconstructpath(came,came[current_node]);
		pp.push_back(current_node);
		return pp;
	}

}

	//astar
	vertices astar(Vector3f start, Vector3f goal, std::map<Vector3f,vertices> rmap, vertices samples)
	{
		vertices openlist, closedlist;
		std::map<Vector3f,Vector3f> parent;
		std::map<Vector3f,float> tent_cost, tent_f;

		openlist.push_back(start);

		tent_cost[start] = 0;
		tent_f[start] = tent_cost[start] + start.getDistanceTo(goal);
		
		for(size_t a = 0; a < samples.size(); a++)
		{
			if(samples[a] != start)
			{
				tent_cost[samples[a]] = 50000000;
				tent_f[samples[a]] = tent_cost[samples[a]] + samples[a].getDistanceTo(goal);
			}

		}

		while(!openlist.empty())
		{
			Vector3f current;
			float mincost = 50000000;
			size_t minid;

			for(size_t b = 0; b < openlist.size(); b++)
			{
				if(tent_f[openlist[b]] < mincost)
				{
					mincost = tent_f[openlist[b]];
					current = openlist[b];
					minid = b;
				}
			}

			if(current == goal)
			{
				float pathcost = cost(current,start,parent);
				return (reconstructpath(parent,current));
			}

			openlist.erase(openlist.begin() + minid);
			closedlist.push_back(current);

			for(size_t c = 0; c < rmap[current].size(); c++)
			{
				bool alreadychecked, openchecked;
				for(size_t d = 0; d < closedlist.size(); d++)
				{
					if(rmap[current][c] == closedlist[d])
						{
							alreadychecked = true;
							break;
					    }
				}

				if(alreadychecked)
					continue;

				for(size_t e = 0; e < openlist.size(); e++)
				{
					if(rmap[current][c] == openlist[e])
						{
							openchecked = true;
							break;
					    }
				}


				float tentativecost = tent_cost[current] + current.getDistanceTo(rmap[current][c]);

				if((!openchecked) || (tentativecost < tent_cost[rmap[current][c]]))
				{
					parent[rmap[current][c]] = current;
					tent_cost[rmap[current][c]] = tentativecost;
					tent_f[rmap[current][c]] = tent_cost[rmap[current][c]] + rmap[current][c].getDistanceTo(goal);

					if(!openchecked)
						openlist.push_back(rmap[current][c]);

				}		


			}

		}

		perror("path not found!\n ");
		return vertices();
	}


	vertices prm(const Vector3f start, const Vector3f goal,Pointer<Roadmap> rmap) 
	{

		std::map<Vector3f,vertices> roadmp;
		vertices sample;

		sample.push_back(start);

		vertices nbr1;

		for ( Index i = 0; i < rmap->getNodeCount(); i++ )
	{
		const Vector3f& p11 = rmap->getNode(i).position;

		if ( p11.getDistanceToSquared(start) < 10000.0 && rmap->link( p11, start) )
			{
				nbr1.push_back(rmap->getNode(i).position);
				//rmap->getNode(i).neighbors. add( );
				
			}

	}

		roadmp[start] = nbr1;


		for ( Index i = 0; i < rmap->getNodeCount(); i++ )
	{
		
		sample.push_back(rmap->getNode(i).position);

		const ArrayList<Index>& neighbors = rmap->getNode(i).neighbors;
		const Size numNeighbors = neighbors.getSize();
		vertices nbr;

		for ( Index n = 0; n < numNeighbors; n++ )
		{
			nbr.push_back(rmap->getNode(neighbors[n]).position );
		}

		roadmp[rmap->getNode(i).position] = nbr;

	}

		sample.push_back(goal);

		vertices nbr2;

		for ( Index i = 0; i < rmap->getNodeCount(); i++ )
	{
		const Vector3f& p12 = rmap->getNode(i).position;

		if ( p12.getDistanceToSquared(goal) < 10000.0 && rmap->link( p12, goal) )
			{
				nbr2.push_back(rmap->getNode(i).position);
				//rmap->getNode(i).neighbors. add( );
				
				
			}

	}

		roadmp[goal] = nbr2;


		return astar(start,goal,roadmp,sample);


	}



	Global_planner(){
	};
	

};

