AC_INIT([pfree], [current], [lars@chaotika.org])

AC_CONFIG_AUX_DIR(config)
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_HEADERS(config.h)

AC_PROG_CC

AC_CONFIG_FILES(Makefile)

case "$target" in
*linux*)
        machine=linux ;;
esac

AC_CONFIG_LINKS(host.c:machine/$machine.c)

AC_OUTPUT
