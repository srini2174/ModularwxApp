#ifndef _GUIPROPVIEWER_H
#define _GUIPROPVIEWER_H

#if defined(__WXMSW__)

#ifdef WXMAKINGDLL_GUIPV
#    define WXDLLIMPEXP_GUIPV WXEXPORT
#    define WXDLLIMPEXP_DATA_GUIPV(type) WXEXPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUIPV WXEXPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUIPV
#    endif
#elif defined(WXUSINGDLL)
#    define WXDLLIMPEXP_GUIPV WXIMPORT
#    define WXDLLIMPEXP_DATA_GUIPV(type) WXIMPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUIPV WXIMPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUIPV
#    endif
#else 
#    define WXDLLIMPEXP_GUIPV
#    define WXDLLIMPEXP_DATA_GUIPV(type) type
#    define WXDLLIMPEXP_INLINE_GUIPV
#endif

#endif // __WXMSW__

#endif // _DECLARATIONS_H
