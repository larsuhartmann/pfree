#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <unistd.h>

#include <config.h>
#include <machine.h>

#define PF_OPTIONS_DEFAULT { 10, true, true, 0, 0 }

typedef struct pf_options {
     int ushift;        /* number of rightshifts needed to shift
                         * values to requested output unit */
     bool with_bcline;  /* wheter pfree should print the -/+
                         * buffers/cache line */
     bool with_total;   /* wheter pfree should print a total line */
     int wait_time;     /* time to wait (-s option) */
     intmax_t count;    /* number of times to print output (-c option) */
} pf_options_t;

void
meminfo_print(pf_meminfo_t m, pf_options_t *o);

void
meminfo_ushift(pf_meminfo_t *m, pf_options_t *o);

void
meminfo_usage(char *bname);

void
meminfo_version();
