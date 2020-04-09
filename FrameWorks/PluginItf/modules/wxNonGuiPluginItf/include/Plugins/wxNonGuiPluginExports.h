#pragma once
#if defined(__WXMSW__)
#   ifdef WXMAKINGDLL_NGUIITF
#       define WXDLLIMPEXP_NGUIITF WXEXPORT
#       define WXDLLIMPEXP_DATA_NGUIITF(type) WXEXPORT type
#       if defined(HAVE_VISIBILITY)
#           define WXDLLIMPEXP_INLINE_NGUIITF WXEXPORT
#       else
#           define WXDLLIMPEXP_INLINE_NGUIITF
#       endif
#   elif defined(WXUSINGDLL_NGUIITF)
#       define WXDLLIMPEXP_NGUIITF WXIMPORT
#       define WXDLLIMPEXP_DATA_NGUIITF(type) WXIMPORT type
#       if defined(HAVE_VISIBILITY)
#           define WXDLLIMPEXP_INLINE_NGUIITF WXIMPORT
#       else
#           define WXDLLIMPEXP_INLINE_NGUIITF
#       endif
#   else
#       define WXDLLIMPEXP_NGUIITF
#       define WXDLLIMPEXP_DATA_NGUIITF(type) type
#       define WXDLLIMPEXP_INLINE_NGUIITF
#   endif
#endif

/*
#if defined(__WXMSW__)
#ifdef WXMAKINGDLL_NGUIITF
#define WXDLLIMPEXP_NGUIITF __declspec(dllexport)
#else
#define WXDLLIMPEXP_NGUIITF __declspec(dllimport)
#endif
#else
#define WXDLLIMPEXP_NGUIITF
#endif
*/

