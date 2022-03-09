#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTUIDLL_LIB)
#  define QTUIDLL_EXPORT Q_DECL_EXPORT
# else
#  define QTUIDLL_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTUIDLL_EXPORT
#endif
