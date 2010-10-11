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

/* This file contains the platform dependent parts needed to get pfree
 * running on FreeBSD */

#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <kvm.h>
#include <unistd.h>

#include <machine.h>

#define DEVNULL_PATH    "/dev/null"

int
machine_init(pf_meminfo_t *ret)
{
     size_t t = sizeof(ret->mem_used);
     int pagesize;
     struct kvm_swap swapinfo;
     kvm_t *kd;

     pagesize = getpagesize();

     sysctlbyname("vm.stats.vm.v_active_count", &ret->mem_used, &t, NULL, 0);
     ret->mem_used *= pagesize;
     sysctlbyname("vm.stats.vm.v_free_count", &ret->mem_free, &t, NULL, 0);
     ret->mem_free *= pagesize;
     ret->mem_total = ret->mem_free + ret->mem_used;
     sysctlbyname("vfs.bufspace", &ret->buffers, &t, NULL, 0);
     sysctlbyname("vm.stats.vm.v_cache_count", &ret->cached, &t, NULL, 0);
     ret->cached *= pagesize;

     kd = kvm_open(NULL, DEVNULL_PATH, NULL, O_RDONLY, "kvm_open");
     kvm_getswapinfo(kd, &swapinfo, 1, 0);
     ret->swap_total *= pagesize;
     ret->swap_used *= pagesize;
     ret->swap_free = swapinfo.ksw_total - swapinfo.ksw_used;

     return 0;
}
