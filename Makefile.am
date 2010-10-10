bin_PROGRAMS=free
free_SOURCES=src/free.c
nodist_free_SOURCES=src/host.c
free_LDFLAGS=$(ldflags)

AM_CPPFLAGS = -I$(top_srcdir)/include
METASOURCES = AUTO

EXTRA_DIST = machine include

valgrind: $(PROGRAMS)
	valgrind -q --track-fds=yes $(PROGRAMS)
