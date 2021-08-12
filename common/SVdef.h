#ifndef SV_DEF_h_
#define SV_DEF_h_

// #ifdef EXPORT_API

#ifndef SV_EXTERN_C
#  ifdef __cplusplus && defined EXPORT_API
#    define SV_EXTERN_C extern "C"
#  else
#    define SV_EXTERN_C
#  endif
#endif

#ifndef SV_EXPORTS
#   if (defined _WIN32 || defined WINCE || defined __CYGWIN__ || defined _MSC_VER) && defined EXPORT_API
#       define SV_EXPORTS __declspec(dllexport)
#   elif defined __GNUC__ && __GNUC__ >= 4 && defined EXPORT_API
#       define SV_EXPORTS __attribute__ ((visibility ("default")))
#   endif
#endif

#ifndef SV_EXPORTS
#   define SV_EXPORTS
#endif

// #endif //EXPORT_API

#endif //SV_DEF_h_