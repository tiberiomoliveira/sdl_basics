# -*- Autoconf -*-

AC_PREREQ([2.68])
AC_INIT([SDL Basics], [0.1], [tiberiomoliveira@gmail.com], [sdl_basics], [https://github.com/tiberiomoliveira/sdl_basics])
AM_INIT_AUTOMAKE([no-define -Wall -Werror -Wsyntax])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_CHECK_LIB([SDL], [main])

# Checks for header files.
AC_CHECK_HEADERS([SDL/SDL.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
