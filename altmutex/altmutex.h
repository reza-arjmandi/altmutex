#pragma once

#include <windows.h>

class altmutex {

public:
      
  using native_handle_type = CRITICAL_SECTION;

  altmutex() {
    InitializeCriticalSectionAndSpinCount(
      &_mut, 0x00000400);
  }

  ~altmutex() {
    DeleteCriticalSection(&_mut);
  }

  altmutex(const altmutex&) = delete;
  void operator=(const altmutex&) = delete;

  void lock() {
    EnterCriticalSection(&_mut);
  }

  bool try_lock() {
    EnterCriticalSection(&_mut);
    return true;
  }
      
  void unlock() {
    LeaveCriticalSection(&_mut);
  }

  native_handle_type native_handle() {
    return _mut;
  }

private:
  CRITICAL_SECTION _mut;

};

