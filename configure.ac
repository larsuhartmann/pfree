AC_INIT([pfree], [2], [lars@chaotika.org])

AC_CONFIG_AUX_DIR(config)
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_HEADERS(config.h)

AC_PROG_CC

AC_CONFIG_FILES(Makefile)

ldflags=""

case "$target" in
*linux*)
        machine=linux ;;
*freebsd*)
        machine=freebsd
        ldflags="-lkvm"
        ;;
esac

AC_CONFIG_LINKS(src/host.c:machine/$machine.c)
AC_SUBST(ldflags)

AC_OUTPUT
