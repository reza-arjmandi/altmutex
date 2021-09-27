#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#if (_MANAGED == 1) || (_M_CEE == 1)

#include "altmutex.h"

namespace std {
    using mutex = altmutex;
}

#endif
#endif