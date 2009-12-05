/****************************************************************************
**
** Copyright (C) 2008-2009 C. Bradford Barber. All rights reserved.
** $Id: //product/qhull/main/rel/cpp/QhullError.h#29 $$Change: 1098 $
** $DateTime: 2009/12/04 22:47:59 $$Author: bbarber $
**
****************************************************************************/

#ifndef QHULLERROR_H
#define QHULLERROR_H

#include "road/RoadError.h"

#include <assert.h>
#include <stdexcept>
#include <string>

namespace orgQhull {

#//Types
    //! QhullError -- std::exception class for Qhull
    class QhullError;

class QhullError : public RoadError {

public:
#//Constants
    enum {
        QHULLfirstError= 10000, //Larger than msgcode in Qhull's user.h
        QHULLlastError= 10067,
        NOthrow= 1 //! For flag to UsingQhullLIb()
    };

#//Constructors
    // default constructors
    QhullError() : RoadError() {};
    QhullError(int code, const std::string &message) : RoadError(code, message) {};
    QhullError(int code, const char *fmt) : RoadError(code, fmt) {};
    QhullError(int code, const char *fmt, int d) : RoadError(code, fmt, d) {};
    QhullError(int code, const char *fmt, int d, int d2) : RoadError(code, fmt, d, d2) {};
    QhullError(int code, const char *fmt, int d, int d2, float f) : RoadError(code, fmt, d, d2, f) {};
    QhullError(int code, const char *fmt, int d, int d2, float f, const char *s) : RoadError(code, fmt, d, d2, f, s) {};
    QhullError(int code, const char *fmt, int d, int d2, float f, const void *x) : RoadError(code, fmt, d, d2, f, x) {};
    QhullError(int code, const char *fmt, int d, int d2, float f, int i) : RoadError(code, fmt, d, d2, f, i) {};
    QhullError(int code, const char *fmt, int d, int d2, float f, long long i) : RoadError(code, fmt, d, d2, f, i) {};
    QhullError(int code, const char *fmt, int d, int d2, float f, double e) : RoadError(code, fmt, d, d2, f, e) {};

};//class QhullError

#ifndef QHULL_1
    #define QHULL_ASSERT assert

    //! See Qt's qglobal.h
    #if defined(Q_CC_INTEL) && !defined(Q_OS_WIN) // FIXUP
    template <typename T>
    inline void qUnused(T &x) { (void)x; }
    #  define QHULL_UNUSED(x) qUnused(x);
    #else
    #  define QHULL_UNUSED(x) (void)x;
    #endif
#endif

}//namespace orgQhull

#//Global functions

inline std::ostream &operator<<(std::ostream &os, const orgQhull::QhullError &e) { return os<< e.what(); }

#endif // QHULLERROR_H
