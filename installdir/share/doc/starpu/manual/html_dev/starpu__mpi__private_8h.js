var starpu__mpi__private_8h =
[
    [ "_starpu_simgrid_mpi_req", "starpu__mpi__private_8h.html#struct__starpu__simgrid__mpi__req", [
      [ "request", "starpu__mpi__private_8h.html#aa4f811d99850c1351ff47b2489770fcd", null ],
      [ "status", "starpu__mpi__private_8h.html#aadda756e6e3853dede2f65683fcb744f", null ],
      [ "queue", "starpu__mpi__private_8h.html#a8929fdbbc4515f87531d10ddd7cbe913", null ],
      [ "done", "starpu__mpi__private_8h.html#ac41b673e450a8889737d9a7180741590", null ]
    ] ],
    [ "_starpu_mpi_node", "starpu__mpi__private_8h.html#struct__starpu__mpi__node", [
      [ "comm", "starpu__mpi__private_8h.html#a0dc761240e5b344d15f8118ee0b00d3a", null ],
      [ "rank", "starpu__mpi__private_8h.html#aad938384f7637b2b88fd8a612ff918df", null ]
    ] ],
    [ "_starpu_mpi_node_tag", "starpu__mpi__private_8h.html#struct__starpu__mpi__node__tag", [
      [ "node", "starpu__mpi__private_8h.html#a1d29ac44a16a6645647f381ce39f0203", null ],
      [ "data_tag", "starpu__mpi__private_8h.html#a315bf2a10497c47ae9069d0dd2e66fe9", null ]
    ] ],
    [ "_starpu_mpi_coop_sends", "starpu__mpi__private_8h.html#struct__starpu__mpi__coop__sends", [
      [ "reqs", "starpu__mpi__private_8h.html#a3940cc35bf3d78fbee4f9a7234ce37ea", null ],
      [ "mpi_data", "starpu__mpi__private_8h.html#a45bfbfebedf7429ecbec9ceb7e75999f", null ],
      [ "lock", "starpu__mpi__private_8h.html#ae572df944e5a9529c6b634f70dcbb06f", null ],
      [ "reqs_array", "starpu__mpi__private_8h.html#a4f67e07e2c45830b6c0a4fc64b899d74", null ],
      [ "n", "starpu__mpi__private_8h.html#a7dcb0d509f9090f7e2f194a4e0f36002", null ],
      [ "redirects_sent", "starpu__mpi__private_8h.html#ae60bc38123e6b8af297e131661e9a1ad", null ]
    ] ],
    [ "_starpu_mpi_data", "starpu__mpi__private_8h.html#struct__starpu__mpi__data", [
      [ "magic", "starpu__mpi__private_8h.html#ad0cf9408a6ed483ad3ac60c0174cb460", null ],
      [ "node_tag", "starpu__mpi__private_8h.html#ad81f1313a9e13839190c3b97adffe759", null ],
      [ "cache_sent", "starpu__mpi__private_8h.html#af8290f44c297fd4c3ce2d3e5ae89643b", null ],
      [ "cache_received", "starpu__mpi__private_8h.html#a92b523e9edf1eaaea43ab048f88ccbda", null ],
      [ "coop_lock", "starpu__mpi__private_8h.html#a44be0c6b595722070e8a5d4b92704c8c", null ],
      [ "coop_sends", "starpu__mpi__private_8h.html#a80609746f8a3b4a0c406686713b2215a", null ]
    ] ],
    [ "_starpu_mpi_req", "struct__starpu__mpi__req.html", "struct__starpu__mpi__req" ],
    [ "_starpu_mpi_argc_argv", "starpu__mpi__private_8h.html#struct__starpu__mpi__argc__argv", [
      [ "initialize_mpi", "starpu__mpi__private_8h.html#affc7472097a3193323cf5b4c1765abdd", null ],
      [ "argc", "starpu__mpi__private_8h.html#a00f78a52ceafa4fe7f4ec030d5900369", null ],
      [ "argv", "starpu__mpi__private_8h.html#acc9b3a4d1e83ec0ccca639c574883ac5", null ],
      [ "comm", "starpu__mpi__private_8h.html#ac23dc1dfa9acc82aed8ef4e931ad8ee8", null ],
      [ "fargc", "starpu__mpi__private_8h.html#aa81fc9f71f0a0e0ddbb2b41f5cc1117c", null ],
      [ "fargv", "starpu__mpi__private_8h.html#aa08fdb153202f2176a659f19e1033a4f", null ],
      [ "rank", "starpu__mpi__private_8h.html#acc4b3f9fde41f7372724a8b51fbb9eed", null ],
      [ "world_size", "starpu__mpi__private_8h.html#aceaaf9c405c994b6e43eeadbdd5dda2f", null ]
    ] ],
    [ "_starpu_mpi_backend", "struct__starpu__mpi__backend.html", "struct__starpu__mpi__backend" ],
    [ "STARPU_MPI_ASSERT_MSG", "starpu__mpi__private_8h.html#a59a11c9dabe2e9debe17614d08dcf4ac", null ],
    [ "_STARPU_MPI_MALLOC", "starpu__mpi__private_8h.html#a6414aea022d3fad480bd1a487f7b21af", null ],
    [ "_STARPU_MPI_CALLOC", "starpu__mpi__private_8h.html#a573f2d384957f7bf96b1293ff2a98630", null ],
    [ "_STARPU_MPI_REALLOC", "starpu__mpi__private_8h.html#a82696d8f3b61cab60644c1d914718016", null ],
    [ "_STARPU_MPI_COMM_DEBUG", "starpu__mpi__private_8h.html#a7da454b377ba02436f0a0dbd9319a30e", null ],
    [ "_STARPU_MPI_COMM_TO_DEBUG", "starpu__mpi__private_8h.html#adecb44c4cfc81a1ff875665a6eb8fd8f", null ],
    [ "_STARPU_MPI_COMM_FROM_DEBUG", "starpu__mpi__private_8h.html#a517cc30884eb8e1a2c4be8fdb7f45c03", null ],
    [ "_STARPU_MPI_DEBUG", "starpu__mpi__private_8h.html#a7f7403c10c8bae79e1db4e4c31cf6719", null ],
    [ "_STARPU_MPI_DISP", "starpu__mpi__private_8h.html#a8c2ab5fc627320f1308ff5e13203e4a2", null ],
    [ "_STARPU_MPI_MSG", "starpu__mpi__private_8h.html#a338fa19b2471427de48a33bd595557dc", null ],
    [ "_STARPU_MPI_LOG_IN", "starpu__mpi__private_8h.html#a2000f0b39b617e13a8e176795a7689aa", null ],
    [ "_STARPU_MPI_LOG_OUT", "starpu__mpi__private_8h.html#aed602cd2e94d53c38492472f6bbf9f8e", null ],
    [ "_starpu_mpi_request_type", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725", [
      [ "SEND_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725adf0b636c0689e25508c69c49c34e265a", null ],
      [ "RECV_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725a9e0a58bd636f7ff9351f848df63d6608", null ],
      [ "WAIT_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725ae117b61eddc8ad01eaa50c8370e491a9", null ],
      [ "TEST_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725afaf9c86080cdfe67ae5d41492e48be7b", null ],
      [ "BARRIER_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725ade7aa36bdd44d93d6ae5f4a6ffbb4de8", null ],
      [ "PROBE_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725ac8cd42b7b2fc65972ce0c0f6c8f452a2", null ],
      [ "UNKNOWN_REQ", "starpu__mpi__private_8h.html#a9f1b65cedbdd59958c4b373e56443725a280fd0988d2e70bd4fc2cadae012491f", null ]
    ] ],
    [ "_starpu_mpi_simgrid_mpi_test", "starpu__mpi__private_8h.html#ad72bacc6c5de826cce97df47a1505dca", null ],
    [ "_starpu_mpi_simgrid_wait_req", "starpu__mpi__private_8h.html#aadda6471d18c79585076ca8018fe77da", null ],
    [ "_starpu_mpi_get_mpi_error_code", "starpu__mpi__private_8h.html#a0a322f754b15c147e4188d32eda6ea01", null ],
    [ "_starpu_mpi_env_init", "starpu__mpi__private_8h.html#a51f6dc93fe0c7fb53520929dc6528d35", null ],
    [ "_starpu_mpi_data_get", "starpu__mpi__private_8h.html#a745f6df4609c161d126671ba5020fb30", null ],
    [ "_starpu_mpi_submit_ready_request", "starpu__mpi__private_8h.html#acabc3d97bc3c9986e095990f3486647f", null ],
    [ "_starpu_mpi_release_req_data", "starpu__mpi__private_8h.html#aebe07f8edcbc157935515dab84668751", null ],
    [ "_starpu_mpi_coop_sends_build_tree", "starpu__mpi__private_8h.html#a2351311c526cabf16612cffbb24d2dbe", null ],
    [ "_starpu_mpi_coop_send", "starpu__mpi__private_8h.html#a04cd121c3ddbd2e2fe11058fbfc1d210", null ],
    [ "_starpu_mpi_submit_coop_sends", "starpu__mpi__private_8h.html#afae857c0b15f4f87c903e0363d7a191f", null ],
    [ "_starpu_mpi_submit_ready_request_inc", "starpu__mpi__private_8h.html#af5cd8f87b2332c2d65f3cad198c736fa", null ],
    [ "_starpu_mpi_request_init", "starpu__mpi__private_8h.html#ac1d4bf67fc14afc906303eeecbdf36b6", null ],
    [ "_starpu_mpi_request_fill", "starpu__mpi__private_8h.html#aeb0917e2df5385ea1acac813e99a1d2f", null ],
    [ "_starpu_mpi_request_destroy", "starpu__mpi__private_8h.html#a7d493ba0bce669294e7a72265b7be4ef", null ],
    [ "_starpu_mpi_isend_size_func", "starpu__mpi__private_8h.html#a9a6982f9525e5ab49632b9760aeb0a19", null ],
    [ "_starpu_mpi_irecv_size_func", "starpu__mpi__private_8h.html#a7a78ec404e93319a38a75e84d08342b6", null ],
    [ "_starpu_mpi_wait", "starpu__mpi__private_8h.html#ae12f97ecbb97b02689e175edbf84c909", null ],
    [ "_starpu_mpi_test", "starpu__mpi__private_8h.html#abc2b3309b646b3c37668448c682a8e70", null ],
    [ "_starpu_mpi_barrier", "starpu__mpi__private_8h.html#a376d708b4955ced2bfc38b2dc66007ef", null ],
    [ "_starpu_mpi_progress_shutdown", "starpu__mpi__private_8h.html#a68828e4bc53f458a16ab381a3d2cbc39", null ],
    [ "_starpu_mpi_progress_init", "starpu__mpi__private_8h.html#a31e034162eaa77697eeca7a96d4c81eb", null ],
    [ "_starpu_mpi_wait_for_initialization", "starpu__mpi__private_8h.html#ac7a80cc8650f10fce94092684f37f31d", null ],
    [ "_starpu_mpi_data_flush", "starpu__mpi__private_8h.html#afe4bf18c5df27f9687ed1ac4e6017be1", null ],
    [ "_starpu_mpi_thread_wait", "starpu__mpi__private_8h.html#ab4d098b6e732c00163ae31437af16161", null ],
    [ "_starpu_mpi_thread_dontsleep", "starpu__mpi__private_8h.html#a54249ec5a702ee8e77a7dd802028c3e3", null ],
    [ "_starpu_debug_rank", "starpu__mpi__private_8h.html#aefdf3c80cd0820785a3772bc5fbf500c", null ],
    [ "_starpu_mpi_comm_debug", "starpu__mpi__private_8h.html#a1b32ae9c68b40345a37028a81aacd2c9", null ],
    [ "_starpu_mpi_fake_world_size", "starpu__mpi__private_8h.html#a5fda76d6c161348a869c6e37afa95669", null ],
    [ "_starpu_mpi_fake_world_rank", "starpu__mpi__private_8h.html#aceb36017688af6b08ea72e8625d0f953", null ],
    [ "_starpu_mpi_use_prio", "starpu__mpi__private_8h.html#a607ffb86acfccfb61357862dc3f0f1ca", null ],
    [ "_starpu_mpi_nobind", "starpu__mpi__private_8h.html#aac444ede757091e9baa43adc0329830f", null ],
    [ "_starpu_mpi_thread_cpuid", "starpu__mpi__private_8h.html#a7cc17836e439c94c8a7e1004df5fe9fa", null ],
    [ "_starpu_mpi_use_coop_sends", "starpu__mpi__private_8h.html#a8ec1387cf1c4467106521531e50aefeb", null ],
    [ "_starpu_mpi_req", "starpu__mpi__private_8h.html#ae59632a62dc68ee11df6fbfb41e91a97", null ],
    [ "_mpi_backend", "starpu__mpi__private_8h.html#a85965ce403715452e9116379b055a2b9", null ]
];