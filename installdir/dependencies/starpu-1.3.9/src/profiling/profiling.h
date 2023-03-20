/* StarPU --- Runtime system for heterogeneous multicore architectures.
 *
 * Copyright (C) 2010-2021  Université de Bordeaux, CNRS (LaBRI UMR 5800), Inria
 * Copyright (C) 2020       Federal University of Rio Grande do Sul (UFRGS)
 *
 * StarPU is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * StarPU is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU Lesser General Public License in COPYING.LGPL for more details.
 */

#ifndef __PROFILING_H__
#define __PROFILING_H__

/** @file */

#include <starpu.h>
#include <starpu_profiling.h>
#include <starpu_util.h>
#include <common/config.h>

/** Create a task profiling info structure (with the proper time stamps) in case
 * profiling is enabled. */
struct starpu_profiling_task_info *_starpu_allocate_profiling_info_if_needed(struct starpu_task *task);

/** Update the per-worker profiling info after a task (or more) was executed.
 * This tells StarPU how much time was spent doing computation. */
void _starpu_worker_update_profiling_info_executing(int workerid, struct timespec *executing_time, int executed_tasks, uint64_t used_cycles, uint64_t stall_cycles, double consumed_energy, double flops);

/** Record the date when the worker started to sleep. This permits to measure
 * how much time was spent sleeping. */
void _starpu_worker_restart_sleeping(int workerid);

/** Record the date when the worker stopped sleeping. This permits to measure
 * how much time was spent sleeping. */
void _starpu_worker_stop_sleeping(int workerid);

/** Record the date when the worker started to execute a piece of code. This
 * permits to measure how much time was really spent doing computation at the
 * end of the codelet. */
void _starpu_worker_register_executing_start_date(int workerid, struct timespec *executing_start);

/** Record that the worker is not executing any more. */
void _starpu_worker_register_executing_end(int workerid);

/** When StarPU is initialized, a matrix describing all the bus between memory
 * nodes is created: it indicates whether there is a physical link between two
 * memory nodes or not. This matrix should contain the identifier of the bus
 * between two nodes or -1 in case there is no link. */
void _starpu_initialize_busid_matrix(void);

/** Tell StarPU that there exists a link between the two memory nodes. This
 * function returns the identifier associated to the bus which can be used to
 * retrieve profiling information about the bus activity later on. */
int _starpu_register_bus(int src_node, int dst_node);

/** Tell StarPU that "size" bytes were transferred between the two specified
 * memory nodes. */
void _starpu_bus_update_profiling_info(int src_node, int dst_node, size_t size);

void _starpu_profiling_set_task_push_start_time(struct starpu_task *task);
void _starpu_profiling_set_task_push_end_time(struct starpu_task *task);

/** This function needs to be called before other starpu_profile_* functions */
void _starpu_profiling_init(void);

/** This function starts profiling if the STARPU_PROFILING environment variable was set */
void _starpu_profiling_start(void);

void _starpu_profiling_terminate(void);

#endif // __PROFILING_H__
