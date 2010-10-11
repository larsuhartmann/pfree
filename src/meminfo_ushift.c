#include <pfree.h>

void
meminfo_ushift(pf_meminfo_t *m, pf_options_t *o)
{
     m->mem_total>>=o->ushift;
     m->mem_used>>=o->ushift;
     m->mem_free>>=o->ushift;
     m->mem_shared>>=o->ushift;
     m->buffers>>=o->ushift;
     m->cached>>=o->ushift;
     m->swap_total>>=o->ushift;
     m->swap_used>>=o->ushift;
     m->swap_free>>=o->ushift;
}
