#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PANELDLL_LIB)
#  define PANELDLL_EXPORT Q_DECL_EXPORT
# else
#  define PANELDLL_EXPORT Q_DECL_IMPORT
# endif
#else
# define PANELDLL_EXPORT
#endif

