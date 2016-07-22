/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Mupen64plus-core - osal/preproc.h                                     *
 *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
 *   Copyright (C) 2009 Richard Goedeken                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       * 
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
                       
/* this header file is for system-dependent #defines, #includes, and typedefs */

#if !defined (OSAL_PREPROC_H)
#define OSAL_PREPROC_H

#if defined(WIN32) && !defined(__MINGW32__)

  /* macros */
  #define ALIGN(BYTES,DATA) __declspec(align(BYTES)) DATA

  /* string functions */
  #define osal_insensitive_strcmp(x, y) _stricmp(x, y)
  #define snprintf _snprintf
  #define strdup _strdup

  /* for isnan() */
  #include <float.h>
  #define isnan _isnan

  #define OSAL_DIR_SEPARATORS           "\\/"
  #define PATH_MAX _MAX_PATH

#else  /* Not WIN32 */

  // macros
  #define ALIGN(BYTES,DATA) DATA __attribute__((aligned(BYTES)))

  // string functions
  #define osal_insensitive_strcmp(x, y) strcasecmp(x, y)

  #include <limits.h>  // for PATH_MAX

  #define OSAL_DIR_SEPARATORS           "/"

  /* PATH_MAX only may be defined by limits.h */
  #ifndef PATH_MAX
    #define PATH_MAX 4096
  #endif

#endif

#endif /* OSAL_PREPROC_H */

