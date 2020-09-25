#ifndef AKIUTILS_H
#define AKIUTILS_H

#define AKI_DEBUG

namespace AKI {

    void Assert(bool isSuccessed, const char* message);

} // namspace AKI

#if defined(AKI_DEBUG)
#   define AKI_LOG(msg, ...) printf(msg, ##__VA_ARGS__)
#   define AKI_ASSERT(isSuccessed, msg) AKI::Assert(isSuccessed, msg)
#else
#   define AKI_LOG(msg, ...)
#   define AKI_ASSERT(isSuccessed, msg)
#endif


#endif //AKIUTILS_H
