#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TCPCLIENT_LIB)
#  define TCPCLIENT_EXPORT Q_DECL_EXPORT
# else
#  define TCPCLIENT_EXPORT Q_DECL_IMPORT
# endif
#else
# define TCPCLIENT_EXPORT
#endif
