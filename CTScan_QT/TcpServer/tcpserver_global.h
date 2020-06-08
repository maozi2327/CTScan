#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TCPSERVER_LIB)
#  define TCPSERVER_EXPORT Q_DECL_EXPORT
# else
#  define TCPSERVER_EXPORT Q_DECL_IMPORT
# endif
#else
# define TCPSERVER_EXPORT
#endif
