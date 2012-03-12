#ifndef _MORPHY_CONFIG_H
#define _MORPHY_CONFIG_H

#define MORPHY_VERSION_MAJOR 0
#define MORPHY_VERSION_MINOR 3
#define MORPHY_VERSION_PATCH 1
#define MORPHY_VERSION "0.3.1"

// headers
#ifndef HAVE_STDINT_H
/* #undef HAVE_STDINT_H */
#endif

#ifndef HAVE_SYS_TYPES_H
#define HAVE_SYS_TYPES_H 1
#endif

#ifndef HAVE_STDDEF_H
#define HAVE_STDDEF_H 1
#endif

#ifndef HAVE_INTTYPES_H
/* #undef HAVE_INTTYPES_H */
#endif

#ifndef HAVE_STRINGS_H
/* #undef HAVE_STRINGS_H */
#endif

#ifndef HAVE_SYS_IO_H
/* #undef HAVE_SYS_IO_H */
#endif

#ifndef HAVE_IO_H
#define HAVE_IO_H 1
#endif

/* #undef HAVE_TEMPLATE_TEMPLATE_ARGS */

// other defines
/* #undef __MORPHY_HAVE_GCC_VISIBILITY */

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#   define MORPHY_WIN_CONST_DEFINED 1
#else
#   undef MORPHY_WIN_CONST_DEFINED
#endif

// actual stuff
#ifdef MORPHY_WIN_CONST_DEFINED
#   define MORPHY_EXPORT __declspec(dllexport)
#   define MORPHY_IMPORT __declspec(dllimport)
#elif defined(__MORPHY_HAVE_GCC_VISIBILITY)
#   define MORPHY_EXPORT __attribute__ ((visibility("default")))
#   define MORPHY_IMPORT
#else
#   define MORPHY_EXPORT
#   define MORPHY_IMPORT
#endif


#ifdef _MSC_VER
#   define MORPHY_CALLCONV __cdecl
#else
#   define MORPHY_CALLCONV
#endif

#ifdef _MSC_VER
#   define FORCEINLINE __forceinline
#else
#   define FORCEINLINE inline
#endif

#define __STDC_CONSTANT_MACROS
#define __STDC_LIMIT_MACROS
#define __STDC_FORMAT_MACROS

#ifdef HAVE_INTTYPES_H
#   include <inttypes.h>
#else
#   include "win_compat/pinttypes.h"
#endif

#ifdef HAVE_SYS_TYPES_H
#   include <sys/types.h>
#endif

#ifdef HAVE_STDDEF_H
#   include <stddef.h>
#endif

#endif // _MORPHY_CONFIG_H
