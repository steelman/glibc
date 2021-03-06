#include <shlib-compat.h>

#if SHLIB_COMPAT(libc, GLIBC_2_1, GLIBC_2_2) \
    && !defined(GLOB_NO_OLD_VERSION)

#include <dirent.h>
#include <glob.h>
#include <sys/stat.h>

#include <olddirent.h>

int __old_glob64 (const char *__pattern, int __flags,
		  int (*__errfunc) (const char *, int),
		  glob64_t *__pglob);
libc_hidden_proto (__old_glob64);

#define dirent __old_dirent64
#define GL_READDIR(pglob, stream) \
  ((struct __old_dirent64 *) (pglob)->gl_readdir (stream))
#undef __readdir
#define __readdir(dirp) __old_readdir64 (dirp)

#define glob_t glob64_t
#define glob(pattern, flags, errfunc, pglob) \
  __old_glob64 (pattern, flags, errfunc, pglob)
#define globfree(pglob) globfree64(pglob)

#define convert_dirent __old_convert_dirent
#define glob_in_dir __old_glob_in_dir

#undef stat
#define stat stat64
#undef __stat
#define __stat(file, buf) __xstat64 (_STAT_VER, file, buf)

#define GLOB_ATTRIBUTE attribute_compat_text_section

#include <posix/glob.c>

libc_hidden_def (__old_glob64);

compat_symbol (libc, __old_glob64, glob64, GLIBC_2_1);
#endif
