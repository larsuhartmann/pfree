/*
 * Copyright (c) 2010 Lars Hartmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    1. Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *      
 *    2. Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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
