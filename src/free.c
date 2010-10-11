#include <pfree.h>

#define optstring       "bkmgtVo"

int main(int argc, char *argv[])
{
     int opt;
     pf_meminfo_t m = PF_MEMINFO_DEFAULT;
     pf_options_t o = PF_OPTIONS_DEFAULT;

     while ( (opt = getopt(argc, argv, optstring)) != -1 ) {
          switch (opt) {
          case 'b':
               o.ushift=0;
               break;
          case 'k':
               o.ushift=10;
               break;
          case 'm':
               o.ushift=20;
               break;
          case 'g':
               o.ushift=30;
               break;
          case 'o':
               o.with_bcline=false;
          case 't':
               o.with_total=true;
               break;
          case 'V':
               meminfo_version();
          case '?':
          default:
               meminfo_usage(argv[0]);
          }
     }

     if ( machine_init(&m) < 0 )
          perror("Error while fetching memory information");

     meminfo_print(m, &o);

     exit (EXIT_SUCCESS);
}
