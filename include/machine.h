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

/* This file describes the interface between pfree and a
 * machine-dependent module. This header is not machine dependent and
 * doesn't need to be changed for any module */

#include <stdint.h>
#include <stdbool.h>

/* default values for pf_meminfo struct */
#define PF_MEMINFO_DEFAULT { 0, 0, 0, 0, 0, 0, 0, 0, 0, false }

/* this struct is filled by machine_init */
typedef struct pf_meminfo {
     uint64_t mem_total;        /* bytes of total memory */
     uint64_t mem_used;         /* bytes of used memory */
     uint64_t mem_free;         /* bytes of free memory */
     uint64_t mem_shared;       /* bytes of shared memory */
     uint64_t buffers;          /* buffered bytes */
     uint64_t cached;           /* cached bytes */
     uint64_t swap_total;       /* bytes of total swap */
     uint64_t swap_used;        /* bytes of used swap */
     uint64_t swap_free;        /* bytes of free swap */
     bool with_bcline;          /* wheter pfree should print the -/+
                                 * buffers/cache line */
} pf_meminfo_t;

/* this is the actual interface to the machine dependent code, this
 * function is to be implemented as part of porting this program. It's
 * sole purpose is to fill out the fields in the struct so pfree can
 * use em. */
int
machine_init(pf_meminfo_t *ret);
