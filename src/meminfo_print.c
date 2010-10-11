#include <pfree.h>

#define d64             PRIu64
#define format1         "%*s%*s%*s%*s%*s%*s\n"
#define format2         "Mem:%*"d64"%*"d64"%*"d64"%*"d64"%*"d64"%*"d64"\n"
#define format3         "-/+ buffers/cache:%*"d64"%*"d64"\n"
#define format4         "Swap:%*"d64"%*"d64"%*"d64"\n"

void
meminfo_print(pf_meminfo_t *m)
{
     printf(format1, 18, "total", 11, "used", 11, "free", 11, "shared", 11,
            "buffers", 11, "cached");
     printf(format2, 14, m->mem_total, 11, m->mem_used, 11, m->mem_free, 11,
            m->mem_shared, 11, m->buffers, 11, m->cached);
     if ( m->with_bcline )
          printf(format3, 11, m->mem_used - ( m->buffers + m->cached ),
                 11, m->mem_free + ( m->buffers + m->cached ));
     printf(format4, 13, m->swap_total, 11, m->swap_used, 11, m->swap_free);
}
