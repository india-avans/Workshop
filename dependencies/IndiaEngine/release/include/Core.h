
#ifndef India_EXPORT_H
#define India_EXPORT_H

#ifdef IndiaEngine_BUILT_AS_STATIC
#  define India_EXPORT
#  define INDIAENGINE_NO_EXPORT
#else
#  ifndef India_EXPORT
#    ifdef IndiaEngine_EXPORTS
        /* We are building this library */
#      define India_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define India_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef INDIAENGINE_NO_EXPORT
#    define INDIAENGINE_NO_EXPORT 
#  endif
#endif

#ifndef INDIAENGINE_DEPRECATED
#  define INDIAENGINE_DEPRECATED __declspec(deprecated)
#endif

#ifndef INDIAENGINE_DEPRECATED_EXPORT
#  define INDIAENGINE_DEPRECATED_EXPORT India_EXPORT INDIAENGINE_DEPRECATED
#endif

#ifndef INDIAENGINE_DEPRECATED_NO_EXPORT
#  define INDIAENGINE_DEPRECATED_NO_EXPORT INDIAENGINE_NO_EXPORT INDIAENGINE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef INDIAENGINE_NO_DEPRECATED
#    define INDIAENGINE_NO_DEPRECATED
#  endif
#endif

#endif /* India_EXPORT_H */
