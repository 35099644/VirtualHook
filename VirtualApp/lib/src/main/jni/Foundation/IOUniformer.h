//
// VirtualApp Native Project
//

#ifndef NDK_HOOK_H
#define NDK_HOOK_H


#include <string>
#include <list>
#include <jni.h>
#include <dlfcn.h>
#include <stddef.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/syscall.h>

//#include <MSHook.h>
#include "Helper.h"


#define HOOK_SYMBOL(handle, func) hook_template(handle, #func, (void*) new_##func, (void**) &orig_##func)
#define HOOK_DEF(ret, func, ...) \
  static ret (*orig_##func)(__VA_ARGS__); \
  static ret new_##func(__VA_ARGS__)


namespace IOUniformer {
    void startUniformer(int api_level, int preview_api_level);

    void redirect(const char*orig_path, const char*new_path);

    void readOnly(const char*path);

    const char *query(const char *orig_path);

    const char *restore(const char *redirected_path);
}

#endif //NDK_HOOK_H
