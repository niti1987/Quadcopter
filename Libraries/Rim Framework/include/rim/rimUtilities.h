/*
 *  rimUtilities.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_UTILITIES_H
#define INCLUDE_RIM_UTILITIES_H


#include "util/rimUtilitiesConfig.h"


#include "util/rimAllocator.h"
#include "util/rimCopy.h"

// Array classes
#include "util/rimArray.h"
#include "util/rimAlignedArray.h"
#include "util/rimShortArray.h"
#include "util/rimStaticArray.h"

// Array-based list classes
#include "util/rimArrayList.h"
#include "util/rimStaticArrayList.h"
#include "util/rimShortArrayList.h"

// Linked list class
#include "util/rimLinkedList.h"

#include "util/rimHashMap.h"
#include "util/rimHashSet.h"

#include "util/rimQueue.h"
#include "util/rimStack.h"

#include "util/rimPriorityQueue.h"



#ifdef RIM_UTILITIES_NAMESPACE_START
	#undef RIM_UTILITIES_NAMESPACE_START
#endif




#ifdef RIM_UTILITIES_NAMESPACE_END
	#undef RIM_UTILITIES_NAMESPACE_END
#endif



#endif // INCLUDE_RIM_UTILITIES_H
