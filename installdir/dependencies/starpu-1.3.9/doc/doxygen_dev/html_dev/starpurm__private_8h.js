var starpurm__private_8h =
[
    [ "s_starpurm", "starpurm__private_8h.html#structs__starpurm", [
      [ "topology", "starpurm__private_8h.html#a0e4adee70608b8a7706ecae0d27cd2a1", null ],
      [ "max_ncpus", "starpurm__private_8h.html#a8f5805530cda7cda6ccf030d49749b58", null ],
      [ "selected_ncpus", "starpurm__private_8h.html#af7a22933cb482c4af23c5e7292d0e867", null ],
      [ "selected_nworkers", "starpurm__private_8h.html#a0f109c7dd70bace2bcf1422ec0fdaf4d", null ],
      [ "state", "starpurm__private_8h.html#a3444ecaaef663df4e936243d1b6eb4d5", null ],
      [ "dynamic_resource_sharing", "starpurm__private_8h.html#a2b308747414d39f8c1576673112fffc6", null ],
      [ "sched_ctx_id", "starpurm__private_8h.html#aefb65c20aead2c00dce2f5713bb84d36", null ],
      [ "unit_ntypes", "starpurm__private_8h.html#a5664fb1fccae012cfd1763ab96f51258", null ],
      [ "nunits_by_type", "starpurm__private_8h.html#a30a97830722b2877ec8a8e0a309b813f", null ],
      [ "nunits", "starpurm__private_8h.html#a9bddfb343eab27f0cf820840bc46c9c4", null ],
      [ "unit_offsets_by_type", "starpurm__private_8h.html#ac25dc9d69fcc1a1ed64ae396517d6187", null ],
      [ "units", "starpurm__private_8h.html#a0559894aec26de36981d256b0347a045", null ],
      [ "global_cpuset", "starpurm__private_8h.html#a11e8a636d1cb81b96ac0647d948938ac", null ],
      [ "all_cpu_workers_cpuset", "starpurm__private_8h.html#a5b427009bd90f5856525c55269293a56", null ],
      [ "all_opencl_device_workers_cpuset", "starpurm__private_8h.html#abf1ed12eb66fe3c46ea59bbc6248224f", null ],
      [ "all_cuda_device_workers_cpuset", "starpurm__private_8h.html#a09cd95b18a44717d6d96bf21c0980475", null ],
      [ "all_mic_device_workers_cpuset", "starpurm__private_8h.html#aedfb6bed0f3edb1b2ccf5a9baf4df095", null ],
      [ "all_device_workers_cpuset", "starpurm__private_8h.html#a0506013fa3fd8e22b302cd76bbe1812c", null ],
      [ "selected_cpuset", "starpurm__private_8h.html#a8e11b937623bdf6d0b993fe96d1a8e2f", null ],
      [ "initially_owned_cpuset_mask", "starpurm__private_8h.html#a2e9a66aa00d98289ca461846ee463a48", null ],
      [ "max_worker_id", "starpurm__private_8h.html#a095fd1941d26172eb4a05a2606497459", null ],
      [ "worker_unit_ids", "starpurm__private_8h.html#a4afb8b55f80dd3f73339302dddbd32c1", null ],
      [ "max_temporary_ctxs", "starpurm__private_8h.html#ae80693f84d3a80c87d2e3c4ec95ecd1d", null ],
      [ "avail_temporary_ctxs", "starpurm__private_8h.html#ae21089199bc4ec3344c3482247cb90f3", null ],
      [ "temporary_ctxs_mutex", "starpurm__private_8h.html#aedd9839100c260da7817e8ff9acf4779", null ],
      [ "temporary_ctxs_cond", "starpurm__private_8h.html#a4d721bd43f141fcd2513338a7f81319b", null ],
      [ "starpu_in_pause", "starpurm__private_8h.html#a5d082d876c34f4a3d3b70841ac6b8897", null ],
      [ "event_thread", "starpurm__private_8h.html#a9fe8a9eee0c60fee3b459842dd2e5c2e", null ],
      [ "event_list_mutex", "starpurm__private_8h.html#a5a2fa2ba33f701a2b38a978735e6cccc", null ],
      [ "event_list_cond", "starpurm__private_8h.html#a208d3bb3e684a9876560f4bdb2cebab1", null ],
      [ "event_processing_cond", "starpurm__private_8h.html#a7f9dd68a00cf6e9ae1a4f4512e373ee7", null ],
      [ "event_processing_enabled", "starpurm__private_8h.html#a5318de626cab6508b59c8058b2d2ea94", null ],
      [ "event_processing_ended", "starpurm__private_8h.html#ad1116b7464d1b73ebbef3e4986ab3b1a", null ],
      [ "event_list_head", "starpurm__private_8h.html#a9c7fec9a09a140a4c51c8a909fef321e", null ],
      [ "event_list_tail", "starpurm__private_8h.html#abad8a78081398b74f22bbbec4888cd1f", null ]
    ] ],
    [ "e_state", "starpurm__private_8h.html#a74a75e4700f1f71bb89d80765319e57b", [
      [ "state_uninitialized", "starpurm__private_8h.html#a74a75e4700f1f71bb89d80765319e57baab5f31eab1beac712454352de2e31715", null ],
      [ "state_init", "starpurm__private_8h.html#a74a75e4700f1f71bb89d80765319e57bacbcbc09c941eac752a6b026a21159c1e", null ]
    ] ],
    [ "e_starpurm_unit_type", "starpurm__private_8h.html#a2e2e243a40f5c7aeb1f092b0b82f91ed", [
      [ "starpurm_unit_cpu", "starpurm__private_8h.html#a2e2e243a40f5c7aeb1f092b0b82f91eda2a7a0284053af98cfb4d0096fc77f4aa", null ],
      [ "starpurm_unit_opencl", "starpurm__private_8h.html#a2e2e243a40f5c7aeb1f092b0b82f91edafb8b7c5ae862fac6e658e75b608f90f1", null ],
      [ "starpurm_unit_cuda", "starpurm__private_8h.html#a2e2e243a40f5c7aeb1f092b0b82f91eda5ac302495b65e882fe267e77f01a592c", null ],
      [ "starpurm_unit_mic", "starpurm__private_8h.html#a2e2e243a40f5c7aeb1f092b0b82f91eda8e1f3ea88a51234947b1d3ba9a94acce", null ],
      [ "starpurm_unit_ntypes", "starpurm__private_8h.html#a2e2e243a40f5c7aeb1f092b0b82f91edaef47192da00a4b7884a0d4cdc34996e8", null ]
    ] ]
];