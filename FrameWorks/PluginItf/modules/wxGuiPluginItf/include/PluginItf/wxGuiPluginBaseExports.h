#pragma once

#if defined(__WXMSW__)
#ifdef WXMAKINGDLL_GUIBASE
#    define WXDLLIMPEXP_GUIBASE WXEXPORT
#    define WXDLLIMPEXP_DATA_GUIBASE(type) WXEXPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUIBASE WXEXPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUIBASE
#    endif
#elif defined(WXUSINGDLL_GUIBASE)
#    define WXDLLIMPEXP_GUIBASE WXIMPORT
#    define WXDLLIMPEXP_DATA_GUIBASE(type) WXIMPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUIBASE WXIMPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUIBASE
#    endif
#else 
#    define WXDLLIMPEXP_GUIBASE
#    define WXDLLIMPEXP_DATA_GUIBASE(type) type
#    define WXDLLIMPEXP_INLINE_GUIBASE
#endif

#endif // __WXMSW__

