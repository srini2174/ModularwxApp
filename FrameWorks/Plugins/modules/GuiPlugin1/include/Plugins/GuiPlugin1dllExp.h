#pragma once

#if defined(__WXMSW__)
#ifdef WXMAKINGDLL_GUI1
#    define WXDLLIMPEXP_GUI1 WXEXPORT
#    define WXDLLIMPEXP_DATA_GUI1(type) WXEXPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUI1 WXEXPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUI1
#    endif
#elif defined(WXUSINGDLL_GUI1)
#    define WXDLLIMPEXP_GUI1 WXIMPORT
#    define WXDLLIMPEXP_DATA_GUI1(type) WXIMPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUI1 WXIMPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUI1
#    endif
#else 
#    define WXDLLIMPEXP_GUI1
#    define WXDLLIMPEXP_DATA_GUI1(type) type
#    define WXDLLIMPEXP_INLINE_GUI1
#endif

#endif

