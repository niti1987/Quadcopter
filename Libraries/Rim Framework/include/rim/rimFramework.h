/*
 *  rimFramework.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FRAMEWORK_H
#define INCLUDE_RIM_FRAMEWORK_H


#include "rimConfig.h"

#include "rimUtilities.h"
#include "rimLanguage.h"
#include "rimExceptions.h"
#include "rimData.h"
#include "rimIO.h"
#include "rimMath.h"
#include "rimThreads.h"
#include "rimTime.h"
#include "rimResources.h"
#include "rimAssetsBase.h"


//##########################################################################################
//********************************  Start Rim Namespace  ***********************************
RIM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Utilities:


using rim::util::Array;
using rim::util::AlignedArray;
using rim::util::StaticArray;
using rim::util::ShortArray;
using rim::util::ArrayList;
using rim::util::ShortArrayList;
using rim::util::StaticArrayList;
using rim::util::LinkedList;
using rim::util::HashMap;
using rim::util::HashSet;
using rim::util::Queue;
using rim::util::Stack;
using rim::util::PriorityQueue;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Language:


using rim::lang::Function;
using rim::lang::bind;
using rim::lang::FunctionCall;
using rim::lang::bindCall;
using rim::lang::Pointer;
using rim::lang::Any;
using rim::lang::Type;
using rim::lang::Optional;
using rim::lang::Tuple;
using rim::lang::HalfFloat;
using rim::lang::BigFloat;
using rim::lang::PrimitiveType;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Exceptions:


using rim::exceptions::Exception;
using rim::exceptions::IOException;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Data:


using rim::data::Buffer;


using rim::data::String;
using rim::data::UTF8String;
using rim::data::UTF16String;
using rim::data::UTF32String;


using rim::data::StringIterator;
using rim::data::UTF8StringIterator;
using rim::data::UTF16StringIterator;
using rim::data::UTF32StringIterator;

using rim::data::StringBuffer;
using rim::data::UTF8StringBuffer;
using rim::data::UTF16StringBuffer;
using rim::data::UTF32StringBuffer;

using rim::data::Data;
using rim::data::DataBuffer;
using rim::data::DataStore;

using rim::data::HashCode;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// File System:


using rim::fs::Path;
using rim::fs::File;
using rim::fs::Directory;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Input and Output:


using rim::io::DataInputStream;
using rim::io::DataOutputStream;
using rim::io::StringInputStream;
using rim::io::StringOutputStream;

using rim::io::FileReader;
using rim::io::FileWriter;
using rim::io::PrintStream;
using rim::io::Log;


using rim::io::Console;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Resources:


using rim::resources::ResourceType;
using rim::resources::ResourceFormat;
using rim::resources::ResourceID;
using rim::resources::ResourceLocalID;
using rim::resources::Resource;
using rim::resources::ResourceTranscoder;
using rim::resources::ResourceManager;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Time:


using rim::time::Time;
using rim::time::Timer;
using rim::time::Date;


//********************************************************************************
//********************************************************************************
//********************************************************************************
// Threads:


using namespace rim::threads;
using rim::threads::atomic::Atomic;


//##########################################################################################
//********************************  End Rim Namespace  *************************************
RIM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_FRAMEWORK_H
