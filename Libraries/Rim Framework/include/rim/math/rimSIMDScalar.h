

#ifndef INCLUDE_RIM_SIMD_SCALAR_H
#define INCLUDE_RIM_SIMD_SCALAR_H


#include "rimMathConfig.h"


#include "rimScalarMath.h"
#include "rimSIMDConfig.h"
#include "rimSIMDTypes.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// The prototype for the SIMDScalar class.
/**
  * Since only certain types and widths are supported on SIMD hardware, this class,
  * forward-declared here is specialized for different types and widths that are
  * hardware compliant. Using another type or width will produce an error because
  * a class with those invalid arguments will not be defined.
  */
template < typename T, Size width >
class SIMDScalar;




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_SCALAR_H
