// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#ifdef _WIN32
	#ifndef __WINT_MIN__ 
		#define __WINT_MIN__  1
	#endif
#endif
#ifdef __WINT_MIN__ 
	#if __WINT_MIN__ > 0
		// include header files specific to the Windows operating system here
	#endif
#endif	

#ifdef __linux__
	// 	include header files specific to the linux operating system here
#endif

#ifdef _MSC_VER
	// include header files specific to Visual Studio here
#endif

#ifdef __GNUC__
	// include header files specific to the GNU compiler here
#endif

#include <stdio.h>
#include <climits>
#include <iostream>
#include <string>
