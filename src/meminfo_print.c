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

#define d64             PRIu64
#define format1         "%*s%*s%*s%*s%*s%*s\n"
#define format2         "Mem:%*"d64"%*"d64"%*"d64"%*"d64"%*"d64"%*"d64"\n"
#define format3         "-/+ buffers/cache:%*"d64"%*"d64"\n"
#define format4         "Swap:%*"d64"%*"d64"%*"d64"\n"
#define format5         "Total:%*"d64"%*"d64"%*"d64"\n"

void
meminfo_print(pf_meminfo_t m, pf_options_t *o)
{
     meminfo_ushift(&m, o);
     
     printf(format1, 18, "total", 11, "used", 11, "free", 11, "shared", 11,
            "buffers", 11, "cached");
     printf(format2, 14, m.mem_total, 11, m.mem_used, 11, m.mem_free, 11,
            m.mem_shared, 11, m.buffers, 11, m.cached);
     if ( m.with_bcline && o->with_bcline )
          printf(format3, 11, m.mem_used - ( m.buffers + m.cached ),
                 11, m.mem_free + ( m.buffers + m.cached ));
     printf(format4, 13, m.swap_total, 11, m.swap_used, 11, m.swap_free);
     if ( o->with_total )
          printf(format5, 12, m.mem_total+m.swap_total, 11,
                 m.mem_used + m.swap_used, 11, m.mem_free + m.swap_free);
}
