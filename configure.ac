#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.0])
AC_INIT([pro1], [1.0.0], [g1710431395@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_HEADERS([autoconf_config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([io.h fcntl.h malloc.h])

# Checks for typedefs, structures, and compiler characteristics.
if test $ac_cv_header_fcntl_h == "yes"
then
    AC_CHECK_DECLS([O_BINARY], , , [#include <fcntl.h>])
fi
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([pipe _pipe read _read write _write close _close])
AC_CHECK_FUNCS([printf_s])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
