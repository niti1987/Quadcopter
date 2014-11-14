/*
 *  main.cpp
 *  HW 1
 *
 *  Created by Carl Schissler on 9/9/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "QuadcopterDemo.h"


using namespace rim::gui;




void mainThread( Application& application )
{
	QuadcopterDemo demo;
	
	demo.run();
}




int main (int argc, char * const argv[])
{
	Application::start( mainThread );
	
    return 0;
}
