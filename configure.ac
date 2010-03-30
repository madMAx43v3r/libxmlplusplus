AC_INIT([libxml++], [2.26.1],
        [https://bugzilla.gnome.org/enter_bug.cgi?product=libxml%2B%2B],
        [libxml++], [http://libxmlplusplus.sourceforge.net/])
AC_PREREQ([2.59])

AC_CONFIG_SRCDIR([libxml++/libxml++.h])
AC_CONFIG_AUX_DIR([macros])
AC_CONFIG_MACRO_DIR([macros])
AC_CONFIG_HEADERS([config.h libxml++config.h])

AM_INIT_AUTOMAKE([1.9 -Wno-portability dist-bzip2 no-define nostdinc subdir-objects])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])
AM_MAINTAINER_MODE([disable])
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

MM_PREREQ([0.8])
MM_INIT_MODULE([libxml++-2.6])

# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
AC_SUBST([LIBXMLXX_SO_VERSION], [2:7:0])

AC_PROG_CXX
LT_PREREQ([2.2.6])
LT_INIT([dlopen win32-dll disable-static])

PKG_CHECK_MODULES([LIBXMLXX], [libxml-2.0 >= 2.6.1 glibmm-2.4 >= 2.4.0])

AC_LANG([C++])
AC_CHECK_HEADERS([string list map], [], [AC_MSG_ERROR([required headers not found])])

AC_ARG_ENABLE([examples],
        [AS_HELP_STRING([--enable-examples],
                [build the examples])],
        [enable_examples=$enableval],
        [enable_examples=no])

AM_CONDITIONAL([ENABLE_EXAMPLES], [test "x$enable_examples" = xyes])

# Offer the ability to omit some API from the library, to reduce the code size:
LIBXMLCPP_ARG_ENABLE_API_EXCEPTIONS

MM_ARG_ENABLE_DOCUMENTATION
MM_ARG_WITH_TAGFILE_DOC([glibmm-2.4.tag], [glibmm-2.4])

MM_ARG_ENABLE_WARNINGS([LIBXMLXX_WXXFLAGS],
        [-Wall],
        [-pedantic -Wall -Wextra])

AC_PATH_PROG([XMLLINT], [xmllint], [xmllint])
AC_ARG_VAR([XMLLINT], [path to xmllint utility])
AC_PATH_PROGS([DB2LATEX], [db2latex docbook2latex], [db2latex])
AC_ARG_VAR([DB2LATEX], [path to db2latex utility])
MM_CHECK_PERL()

AC_CONFIG_FILES([Makefile
        docs/reference/Doxyfile
        MSVC_Net2005/libxml++/libxml++.rc
        MSVC_Net2008/libxml++/libxml++.rc
        libxml++-2.6.pc])

AC_CONFIG_COMMANDS([MSVC_Net2005/libxml++/libxml++config.h],
        [cp -f libxml++config.h MSVC_Net2005/libxml++/libxml++config.h])
AC_CONFIG_COMMANDS([MSVC_Net2008/libxml++/libxml++config.h],
        [cp -f libxml++config.h MSVC_Net2008/libxml++/libxml++config.h])

AC_OUTPUT