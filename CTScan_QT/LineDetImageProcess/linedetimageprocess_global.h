#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LINEDETIMAGEPROCESS_LIB)
#  define LINEDETIMAGEPROCESS_EXPORT Q_DECL_EXPORT
# else
#  define LINEDETIMAGEPROCESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define LINEDETIMAGEPROCESS_EXPORT
#endif
