# When building float128 we need to ensure -mfloat128 is
# passed to all such object files.

# libgcc requires __tcb_parse_hwcap_and_convert_at_platform when built with
# a binary128 type.  That symbol is provided by the loader on dynamically
# linked executables, forcing to link the loader after libgcc link.
f128-loader-link = $(as-needed) $(elf-objpfx)ld.so $(no-as-needed)

ifeq ($(subdir),math)
# sqrtf128 requires emulation before POWER9.
CPPFLAGS += -I../soft-fp

# float128 requires adding a handful of extra flags.
$(foreach suf,$(all-object-suffixes),%f128$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),%f128_r$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),$(objpfx)test-float128%$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),$(objpfx)test-ifloat128%$(suf)): CFLAGS += -mfloat128
CFLAGS-libm-test-support-float128.c += -mfloat128
CFLAGS-test-math-issignaling.cc += -mfloat128
CFLAGS-test-math-iszero.cc += -mfloat128
$(objpfx)test-float128% $(objpfx)test-ifloat128% $(objpfx)test-math-iszero: \
  gnulib-tests += $(f128-loader-link)
endif

# Append flags to string <-> _Float128 routines.
ifneq ($(filter $(subdir),wcsmbs stdlib),)
$(foreach suf,$(all-object-suffixes),%f128$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),%f128_l$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),%f128_nan$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),%float1282mpn$(suf)): CFLAGS += -mfloat128
$(foreach suf,$(all-object-suffixes),%mpn2float128$(suf)): CFLAGS += -mfloat128
CFLAGS-bug-strtod.c += -mfloat128
CFLAGS-bug-strtod2.c += -mfloat128
CFLAGS-tst-strtod-round.c += -mfloat128
CFLAGS-tst-wcstod-round.c += -mfloat128
CFLAGS-tst-strtod6.c += -mfloat128
CFLAGS-tst-strfrom.c += -mfloat128
CFLAGS-tst-strfrom-locale.c += -mfloat128
CFLAGS-strfrom-skeleton.c += -mfloat128
$(foreach test,bug-strtod bug-strtod2 bug-strtod2 tst-strtod-round \
tst-wcstod-round tst-strtod6 tst-strrom tst-strfrom-locale \
strfrom-skeleton,$(objpfx)$(test)): gnulib-tests += $(f128-loader-link)

# When building glibc with support for _Float128, the powers of ten tables in
# fpioconst.c and in the string conversion functions must be extended.  Some
# Makefiles (e.g.: wcsmbs/Makefile) override CFLAGS defined by the Makefiles in
# sysdeps.  This is avoided with the use sysdep-CFLAGS instead of CFLAGS.
sysdep-CFLAGS += $(sysdep-CFLAGS-$(<F))
sysdep-CFLAGS-fpioconst.c += -mfloat128
sysdep-CFLAGS-strtod_l.c += -mfloat128
sysdep-CFLAGS-strtof_l.c += -mfloat128
sysdep-CFLAGS-strtold_l.c += -mfloat128
sysdep-CFLAGS-wcstod_l.c += -mfloat128
sysdep-CFLAGS-wcstof_l.c += -mfloat128
sysdep-CFLAGS-wcstold_l.c += -mfloat128
endif

# Append flags to printf routines.
ifeq ($(subdir),stdio-common)
CFLAGS-printf_fp.c = -mfloat128
CFLAGS-printf_fphex.c = -mfloat128
CFLAGS-printf_size.c = -mfloat128
endif
