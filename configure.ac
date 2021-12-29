AC_PREREQ([2.69])

AC_INIT([util], [1.1], [gzc@caculli.it])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AM_PROG_AR
LT_PREREQ([2.4.6])
LT_INIT([dlopen])

AC_LANG([C++])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Check for Programs
AC_PROG_CXX
AC_PROG_INSTALL

# Enforce C++11
AX_CXX_COMPILE_STDCXX([11], [noext], [mandatory])

# Check for libraries
AC_SEARCH_LIBS([pthread_create], [pthread])
AX_BOOST_BASE([1.76])
AX_BOOST_SYSTEM
AX_BOOST_FILESYSTEM
AX_BOOST_DATE_TIME
AX_BOOST_LOG
AX_BOOST_LOG_SETUP
AX_BOOST_LOCALE
AX_BOOST_THREAD

# Check for header files
AC_CHECK_HEADERS([
    math.h
    stdlib.h
    pthread.h
])

# Check for typedefs, structures and compiler characteristics

# Check for library functions
AC_CONFIG_FILES([
    src/util/logger/Makefile
    src/util/serialize/Makefile
    src/util/Makefile
    src/Makefile
    Makefile
])

AC_OUTPUT
