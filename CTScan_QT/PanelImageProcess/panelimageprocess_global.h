#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PANELIMAGEPROCESS_LIB)
#  define PANELIMAGEPROCESS_EXPORT Q_DECL_EXPORT
# else
#  define PANELIMAGEPROCESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define PANELIMAGEPROCESS_EXPORT
#endif
