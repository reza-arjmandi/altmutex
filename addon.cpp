#pragma managed(push, off)
#include "altmutex/mutex.h"
#include "napi.h"

Napi::String Test(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports["test"] = Napi::Function::New(env, Test);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
#pragma managed(pop)