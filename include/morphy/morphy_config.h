#if defined(_MSC_VER)
# include "morphy_config_msvc.h"
#elif defined(__CYGWIN__)
# include "morphy_config_cygwin.h"
#else
# include "morphy_config_mingw.h"
#endif
