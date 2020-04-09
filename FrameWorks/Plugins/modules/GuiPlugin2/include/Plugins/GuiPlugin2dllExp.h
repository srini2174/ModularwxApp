#ifndef _GUIPLUGIN2_H
#define _GUIPLUGIN2_H

#if defined(__WXMSW__)

#ifdef WXMAKINGDLL_GUI2
#    define WXDLLIMPEXP_GUI2 WXEXPORT
#    define WXDLLIMPEXP_DATA_GUI2(type) WXEXPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUI2 WXEXPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUI2
#    endif
#elif defined(WXUSINGDLL)
#    define WXDLLIMPEXP_GUI2 WXIMPORT
#    define WXDLLIMPEXP_DATA_GUI2(type) WXIMPORT type
#    if defined(HAVE_VISIBILITY)
#        define WXDLLIMPEXP_INLINE_GUI2 WXIMPORT
#    else
#        define WXDLLIMPEXP_INLINE_GUI2
#    endif
#else 
#    define WXDLLIMPEXP_GUI2
#    define WXDLLIMPEXP_DATA_GUI2(type) type
#    define WXDLLIMPEXP_INLINE_GUI2
#endif

#endif // __WXMSW__

#endif // _DECLARATIONS_H
