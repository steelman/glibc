#include <math_ldbl_opt.h>
#undef weak_alias
#define weak_alias(n,a)
#include <math/w_j0l_compat.c>
#if LIBM_SVID_COMPAT
long_double_symbol (libm, __j0l, j0l);
long_double_symbol (libm, __y0l, y0l);
#endif
