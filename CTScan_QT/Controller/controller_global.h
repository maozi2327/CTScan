#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CONTROLLER_LIB)
#  define CONTROLLER_EXPORT Q_DECL_EXPORT
# else
#  define CONTROLLER_EXPORT Q_DECL_IMPORT
# endif
#else
# define CONTROLLER_EXPORT
#endif
