#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PANELDETIMAGEPROCESS_LIB)
#  define PANELDETIMAGEPROCESS_EXPORT Q_DECL_EXPORT
# else
#  define PANELDETIMAGEPROCESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define PANELDETIMAGEPROCESS_EXPORT
#endif
