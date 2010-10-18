#include <pfree.h>

#define optstring       "bkmgtVos:c:"

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
          case 's':
               o.wait_time = 1000000 * atof(optarg);
               break;
          case 'c':
               o.count = strtoimax(optarg, NULL, 10);
               break;
          case 'V':
               meminfo_version();
          case '?':
          default:
               meminfo_usage(argv[0]);
          }
     }


     do {
          if ( machine_init(&m) < 0 )
               perror("Error while fetching memory information");
          
          meminfo_print(m, &o);
          if ( o.wait_time > 0 ) {
               fputc('\n', stdout);
               if ( o.count != 1 )
                    usleep(o.wait_time);
          }
          if ( o.count == INTMAX_MIN )
               o.count=0;
     } while (o.wait_time && --o.count);
     exit (EXIT_SUCCESS);
}
