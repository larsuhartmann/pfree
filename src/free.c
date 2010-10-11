#include <pfree.h>

int main(int argc, char *argv[])
{
     pf_meminfo_t m = PF_MEMINFO_DEFAULT;
     if ( machine_init(&m) < 0 )
          perror("Error while fetching memory information");

     meminfo_print(&m);

     exit (EXIT_SUCCESS);
}
