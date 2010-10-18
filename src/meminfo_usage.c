#include <pfree.h>

void
meminfo_usage(char *bname)
{
     fprintf(stderr, "Usage: %s [-[b|k|m|g]otV[s delay][c count]]\n", bname);
     exit(EXIT_FAILURE);
}
