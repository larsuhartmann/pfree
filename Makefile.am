bin_PROGRAMS=free
free_SOURCES=src/free.c src/meminfo_print.c src/meminfo_ushift.c \
	         src/meminfo_usage.c src/meminfo_version.c
nodist_free_SOURCES=src/host.c
free_LDFLAGS=$(ldflags)

AM_CPPFLAGS = -I$(top_srcdir)/include
METASOURCES = AUTO

EXTRA_DIST = machine include

valgrind: $(PROGRAMS)
	valgrind -q --track-fds=yes $(PROGRAMS)

check-syntax:
	$(COMPILE) -o nul -Wall -c -S ${CHK_SOURCES}
