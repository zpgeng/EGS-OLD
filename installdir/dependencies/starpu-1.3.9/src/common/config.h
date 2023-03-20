/* src/common/config.h.  Generated from config.h.in by configure.  */
/* src/common/config.h.in.  Generated from configure.ac by autoheader.  */

/* enable FUT traces */
/* #undef CONFIG_FUT */

/* Define to 1 if you have the <aio.h> header file. */
#define HAVE_AIO_H 1

/* Define to 1 if you have the <ayudame.h> header file. */
/* #undef HAVE_AYUDAME_H */

/* Define to 1 if you have the `cblas_sgemv' function. */
#define HAVE_CBLAS_SGEMV 1

/* Define to 1 if you have the `clEnqueueMarkerWithWaitList' function. */
/* #undef HAVE_CLENQUEUEMARKERWITHWAITLIST */

/* Define to 1 if you have the `clGetExtensionFunctionAddressForPlatform'
   function. */
/* #undef HAVE_CLGETEXTENSIONFUNCTIONADDRESSFORPLATFORM */

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the <CL/cl_ext.h> header file. */
/* #undef HAVE_CL_CL_EXT_H */

/* Define to 1 if you have the `copy_file_range' function. */
#define HAVE_COPY_FILE_RANGE 1

/* Define to 1 if you have the <cuda_gl_interop.h> header file. */
#define HAVE_CUDA_GL_INTEROP_H 1

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* Define to 1 if you have the declaration of `cusparseSetStream', and to 0 if
   you don't. */
#define HAVE_DECL_CUSPARSESETSTREAM 1

/* Define to 1 if you have the declaration of `enable_fut_flush', and to 0 if
   you don't. */
/* #undef HAVE_DECL_ENABLE_FUT_FLUSH */

/* Define to 1 if you have the declaration of `fut_setup_flush_callback', and
   to 0 if you don't. */
/* #undef HAVE_DECL_FUT_SETUP_FLUSH_CALLBACK */

/* Define to 1 if you have the declaration of `fut_set_filename', and to 0 if
   you don't. */
/* #undef HAVE_DECL_FUT_SET_FILENAME */

/* Define to 1 if you have the declaration of
   `hwloc_cuda_get_device_osdev_by_index', and to 0 if you don't. */
#define HAVE_DECL_HWLOC_CUDA_GET_DEVICE_OSDEV_BY_INDEX 1

/* Define to 1 if you have the declaration of
   `nvmlDeviceGetTotalEnergyConsumption', and to 0 if you don't. */
#define HAVE_DECL_NVMLDEVICEGETTOTALENERGYCONSUMPTION 1

/* Define to 1 if you have the declaration of `smpi_process_set_user_data',
   and to 0 if you don't. */
/* #undef HAVE_DECL_SMPI_PROCESS_SET_USER_DATA */

/* Define to 1 if you have the <dlb.h> header file. */
/* #undef HAVE_DLB_H */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `enable_fut_flush' function. */
/* #undef HAVE_ENABLE_FUT_FLUSH */

/* Define to 1 if you have the `fut_setup_flush_callback' function. */
/* #undef HAVE_FUT_SETUP_FLUSH_CALLBACK */

/* Define to 1 if you have the `fut_set_filename' function. */
/* #undef HAVE_FUT_SET_FILENAME */

/* Define to 1 if you have the `fxt_close' function. */
/* #undef HAVE_FXT_CLOSE */

/* Define to 1 if you have the `getrlimit' function. */
#define HAVE_GETRLIMIT 1

/* Define to 1 if you have the <glpk.h> header file. */
/* #undef HAVE_GLPK_H */

/* Define to 1 if you have the <hdf5.h> header file. */
/* #undef HAVE_HDF5_H */

/* Define to 1 if you have the `hwloc_cpukinds_get_nr' function. */
#define HAVE_HWLOC_CPUKINDS_GET_NR 1

/* Define to 1 if you have the <hwloc/glibc-sched.h> header file. */
/* #undef HAVE_HWLOC_GLIBC_SCHED_H */

/* Define to 1 if you have the `hwloc_topology_dup' function. */
#define HAVE_HWLOC_TOPOLOGY_DUP 1

/* Define to 1 if you have the `hwloc_topology_set_components' function. */
#define HAVE_HWLOC_TOPOLOGY_SET_COMPONENTS 1

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the <leveldb/db.h> header file. */
/* #undef HAVE_LEVELDB_DB_H */

/* Define to 1 if you have the `atlas' library (-latlas). */
/* #undef HAVE_LIBATLAS */

/* Define to 1 if you have the `blas-openblas' library (-lblas-openblas). */
/* #undef HAVE_LIBBLAS_OPENBLAS */

/* Define to 1 if you have the `cblas' library (-lcblas). */
/* #undef HAVE_LIBCBLAS */

/* Define to 1 if you have the cusparse library */
#define HAVE_LIBCUSPARSE 1

/* Define to 1 if you have the `dlb' library (-ldlb). */
/* #undef HAVE_LIBDLB */

/* Define to 1 if you have the `gfortran' library (-lgfortran). */
/* #undef HAVE_LIBGFORTRAN */

/* Define to 1 if you have the `GL' library (-lGL). */
/* #undef HAVE_LIBGL */

/* Define to 1 if you have the `glpk' library (-lglpk). */
/* #undef HAVE_LIBGLPK */

/* Define to 1 if you have the `GLU' library (-lGLU). */
/* #undef HAVE_LIBGLU */

/* Define to 1 if you have the `glut' library (-lglut). */
/* #undef HAVE_LIBGLUT */

/* Define to 1 if you have the `goto' library (-lgoto). */
/* #undef HAVE_LIBGOTO */

/* Define to 1 if you have the `goto2' library (-lgoto2). */
/* #undef HAVE_LIBGOTO2 */

/* Define to 1 if you have the `hdf5' library (-lhdf5). */
/* #undef HAVE_LIBHDF5 */

/* Define to 1 if you have the `ifcore' library (-lifcore). */
/* #undef HAVE_LIBIFCORE */

/* Define to 1 if you have the `leveldb' library (-lleveldb). */
/* #undef HAVE_LIBLEVELDB */

/* Define to 1 if you have the `openblas' library (-lopenblas). */
/* #undef HAVE_LIBOPENBLAS */

/* Define to 1 if you have the `rt' library (-lrt). */
#define HAVE_LIBRT 1

/* Define to 1 if you have the `simgrid' library (-lsimgrid). */
/* #undef HAVE_LIBSIMGRID */

/* Define to 1 if you have the `ws2_32' library (-lws2_32). */
/* #undef HAVE_LIBWS2_32 */

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have the `memalign' function. */
#define HAVE_MEMALIGN 1

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if you have the `mkdtemp' function. */
#define HAVE_MKDTEMP 1

/* Define to 1 if you have the `mkostemp' function. */
#define HAVE_MKOSTEMP 1

/* Function MPI_Comm_f2c is available */
/* #undef HAVE_MPI_COMM_F2C */

/* Define to 1 if you have the `MSG_environment_get_routing_root' function. */
/* #undef HAVE_MSG_ENVIRONMENT_GET_ROUTING_ROOT */

/* Define to 1 if you have the `MSG_get_as_by_name' function. */
/* #undef HAVE_MSG_GET_AS_BY_NAME */

/* Define to 1 if you have the `MSG_host_get_speed' function. */
/* #undef HAVE_MSG_HOST_GET_SPEED */

/* Define to 1 if you have the <msg/msg.h> header file. */
/* #undef HAVE_MSG_MSG_H */

/* Define to 1 if you have the `MSG_process_attach' function. */
/* #undef HAVE_MSG_PROCESS_ATTACH */

/* Define to 1 if you have the `MSG_process_self_name' function. */
/* #undef HAVE_MSG_PROCESS_SELF_NAME */

/* Define to 1 if you have the `MSG_process_userdata_init' function. */
/* #undef HAVE_MSG_PROCESS_USERDATA_INIT */

/* Define to 1 if you have the `MSG_zone_get_by_name' function. */
/* #undef HAVE_MSG_ZONE_GET_BY_NAME */

/* Define to 1 if you have the `MSG_zone_get_hosts' function. */
/* #undef HAVE_MSG_ZONE_GET_HOSTS */

/* Define to 1 if you have the `nvmlDeviceGetTotalEnergyConsumption' function.
   */
#define HAVE_NVMLDEVICEGETTOTALENERGYCONSUMPTION 1

/* piom_ltask_set_bound_thread_os_indexes is availabe */
/* #undef HAVE_PIOM_LTASK_SET_BOUND_THREAD_OS_INDEXES */

/* Define to 1 if you have the `posix_memalign' function. */
#define HAVE_POSIX_MEMALIGN 1

/* Define to 1 if you have the `poti_init_custom' function. */
/* #undef HAVE_POTI_INIT_CUSTOM */

/* Define to 1 if you have the `poti_user_NewEvent' function. */
/* #undef HAVE_POTI_USER_NEWEVENT */

/* Define to 1 if you have the `pread' function. */
#define HAVE_PREAD 1

/* Define to 1 if you have the `pthread_setaffinity_np' function. */
#define HAVE_PTHREAD_SETAFFINITY_NP 1

/* pthread_spin_lock is available */
#define HAVE_PTHREAD_SPIN_LOCK 1

/* Define to 1 if you have the `pwrite' function. */
#define HAVE_PWRITE 1

/* Define to 1 if you have the `scandir' function. */
#define HAVE_SCANDIR 1

/* Define to 1 if you have the `sg_actor_attach' function. */
/* #undef HAVE_SG_ACTOR_ATTACH */

/* Define to 1 if you have the `sg_actor_data' function. */
/* #undef HAVE_SG_ACTOR_DATA */

/* Define to 1 if you have the `sg_actor_execute' function. */
/* #undef HAVE_SG_ACTOR_EXECUTE */

/* Define to 1 if you have the `sg_actor_get_data' function. */
/* #undef HAVE_SG_ACTOR_GET_DATA */

/* Define to 1 if you have the `sg_actor_init' function. */
/* #undef HAVE_SG_ACTOR_INIT */

/* Define to 1 if you have the `sg_actor_on_exit' function. */
/* #undef HAVE_SG_ACTOR_ON_EXIT */

/* Define to 1 if you have the `sg_actor_ref' function. */
/* #undef HAVE_SG_ACTOR_REF */

/* Define to 1 if you have the `sg_actor_self' function. */
/* #undef HAVE_SG_ACTOR_SELF */

/* Define to 1 if you have the `sg_actor_self_execute' function. */
/* #undef HAVE_SG_ACTOR_SELF_EXECUTE */

/* Define to 1 if you have the `sg_actor_set_data' function. */
/* #undef HAVE_SG_ACTOR_SET_DATA */

/* Define to 1 if you have the `sg_actor_sleep_for' function. */
/* #undef HAVE_SG_ACTOR_SLEEP_FOR */

/* Define to 1 if you have the `sg_cfg_set_int' function. */
/* #undef HAVE_SG_CFG_SET_INT */

/* Define to 1 if you have the `sg_config_continue_after_help' function. */
/* #undef HAVE_SG_CONFIG_CONTINUE_AFTER_HELP */

/* Define to 1 if you have the `sg_host_get_properties' function. */
/* #undef HAVE_SG_HOST_GET_PROPERTIES */

/* Define to 1 if you have the `sg_host_get_route' function. */
/* #undef HAVE_SG_HOST_GET_ROUTE */

/* Define to 1 if you have the `sg_host_get_speed' function. */
/* #undef HAVE_SG_HOST_GET_SPEED */

/* Define to 1 if you have the `sg_host_list' function. */
/* #undef HAVE_SG_HOST_LIST */

/* Define to 1 if you have the `sg_host_route' function. */
/* #undef HAVE_SG_HOST_ROUTE */

/* Define to 1 if you have the `sg_host_self' function. */
/* #undef HAVE_SG_HOST_SELF */

/* Define to 1 if you have the `sg_host_sendto' function. */
/* #undef HAVE_SG_HOST_SENDTO */

/* Define to 1 if you have the `sg_host_send_to' function. */
/* #undef HAVE_SG_HOST_SEND_TO */

/* Define to 1 if you have the `sg_host_speed' function. */
/* #undef HAVE_SG_HOST_SPEED */

/* Define to 1 if you have the `sg_link_bandwidth_set' function. */
/* #undef HAVE_SG_LINK_BANDWIDTH_SET */

/* Define to 1 if you have the `sg_link_get_name' function. */
/* #undef HAVE_SG_LINK_GET_NAME */

/* Define to 1 if you have the `sg_link_name' function. */
/* #undef HAVE_SG_LINK_NAME */

/* Define to 1 if you have the `sg_link_set_bandwidth' function. */
/* #undef HAVE_SG_LINK_SET_BANDWIDTH */

/* Define to 1 if you have the `sg_zone_get_by_name' function. */
/* #undef HAVE_SG_ZONE_GET_BY_NAME */

/* Define to 1 if you have the `sg_zone_get_hosts' function. */
/* #undef HAVE_SG_ZONE_GET_HOSTS */

/* Define to 1 if you have the `simcall_process_create' function. */
/* #undef HAVE_SIMCALL_PROCESS_CREATE */

/* Define to 1 if you have the <simgrid/actor.h> header file. */
/* #undef HAVE_SIMGRID_ACTOR_H */

/* Define to 1 if you have the <simgrid/barrier.h> header file. */
/* #undef HAVE_SIMGRID_BARRIER_H */

/* Define to 1 if you have the <simgrid/cond.h> header file. */
/* #undef HAVE_SIMGRID_COND_H */

/* Define to 1 if you have the <simgrid/engine.h> header file. */
/* #undef HAVE_SIMGRID_ENGINE_H */

/* Define to 1 if you have the `simgrid_get_clock' function. */
/* #undef HAVE_SIMGRID_GET_CLOCK */

/* Define to 1 if you have the <simgrid/host.h> header file. */
/* #undef HAVE_SIMGRID_HOST_H */

/* Define to 1 if you have the `simgrid_init' function. */
/* #undef HAVE_SIMGRID_INIT */

/* Define to 1 if you have the <simgrid/msg.h> header file. */
/* #undef HAVE_SIMGRID_MSG_H */

/* Define to 1 if you have the <simgrid/mutex.h> header file. */
/* #undef HAVE_SIMGRID_MUTEX_H */

/* Define to 1 if you have the <simgrid/semaphore.h> header file. */
/* #undef HAVE_SIMGRID_SEMAPHORE_H */

/* Define to 1 if you have the `simgrid_set_maestro' function. */
/* #undef HAVE_SIMGRID_SET_MAESTRO */

/* Define to 1 if you have the <simgrid/simdag.h> header file. */
/* #undef HAVE_SIMGRID_SIMDAG_H */

/* Define to 1 if you have the <simgrid/version.h> header file. */
/* #undef HAVE_SIMGRID_VERSION_H */

/* Define to 1 if you have the <simgrid/zone.h> header file. */
/* #undef HAVE_SIMGRID_ZONE_H */

/* Define to 1 if you have the `smpi_process_set_user_data' function. */
/* #undef HAVE_SMPI_PROCESS_SET_USER_DATA */

/* Define to 1 if you have the `SMPI_thread_create' function. */
/* #undef HAVE_SMPI_THREAD_CREATE */

/* Define to 1 if the system has the type `smx_actor_t'. */
/* #undef HAVE_SMX_ACTOR_T */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the <sys/stat.h> header file. */
/* #undef HAVE_SYS_STAT_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <valgrind/helgrind.h> header file. */
/* #undef HAVE_VALGRIND_HELGRIND_H */

/* Define to 1 if you have the <valgrind/memcheck.h> header file. */
/* #undef HAVE_VALGRIND_MEMCHECK_H */

/* Define to 1 if you have the <valgrind/valgrind.h> header file. */
/* #undef HAVE_VALGRIND_VALGRIND_H */

/* Define to 1 if you have the `xbt_barrier_init' function. */
/* #undef HAVE_XBT_BARRIER_INIT */

/* Define to 1 if you have the <xbt/base.h> header file. */
/* #undef HAVE_XBT_BASE_H */

/* Define to 1 if you have the <xbt/config.h> header file. */
/* #undef HAVE_XBT_CONFIG_H */

/* Define to 1 if you have the `xbt_mutex_try_acquire' function. */
/* #undef HAVE_XBT_MUTEX_TRY_ACQUIRE */

/* Define to 1 if you have the <xbt/synchro.h> header file. */
/* #undef HAVE_XBT_SYNCHRO_H */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "starpu"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "starpu-devel@inria.fr"

/* Define to the full name of this package. */
#define PACKAGE_NAME "StarPU"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "StarPU 1.3.9"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "starpu"

/* Define to the home page for this package. */
#define PACKAGE_URL "http://gitlab.inria.fr/starpu/starpu"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.3.9"

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* display DLB resource management verbose debug messages */
/* #undef STARPURM_DLB_VERBOSE */

/* Define to 1 if dlb support is enabled. */
/* #undef STARPURM_HAVE_DLB */

/* Define to 1 if DLB callbacks expect an user argument */
/* #undef STARPURM_HAVE_DLB_CALLBACK_ARG */

/* Define to 1 if StarPU has support for worker callbacks. */
/* #undef STARPURM_STARPU_HAVE_WORKER_CALLBACKS */

/* display resource management verbose debug messages */
/* #undef STARPURM_VERBOSE */

/* use ARMPL library */
/* #undef STARPU_ARMPL */

/* use STARPU_ATLAS library */
/* #undef STARPU_ATLAS */

/* location of StarPU build directory */

/* use built-in min_dgels */
/* #undef STARPU_BUILT_IN_MIN_DGELS */

/* Define this to enable cluster support */
/* #undef STARPU_CLUSTER */

/* enable debugging statements */
/* #undef STARPU_DEBUG */

/* enable developer warnings */
/* #undef STARPU_DEVEL */

/* Define to 1 to disable asynchronous copy between CPU and GPU devices */
/* #undef STARPU_DISABLE_ASYNCHRONOUS_COPY */

/* Define to 1 to disable asynchronous copy between CPU and CUDA devices */
/* #undef STARPU_DISABLE_ASYNCHRONOUS_CUDA_COPY */

/* Define to 1 to disable asynchronous copy between CPU and MIC devices */
/* #undef STARPU_DISABLE_ASYNCHRONOUS_MIC_COPY */

/* Define to 1 to disable asynchronous copy between MPI Master and MPI Slave
   devices */
/* #undef STARPU_DISABLE_ASYNCHRONOUS_MPI_MS_COPY */

/* Define to 1 to disable asynchronous copy between CPU and OpenCL devices */
/* #undef STARPU_DISABLE_ASYNCHRONOUS_OPENCL_COPY */

/* display verbose debug messages */
/* #undef STARPU_EXTRA_VERBOSE */

/* enable additional locking systems FxT traces */
/* #undef STARPU_FXT_LOCK_TRACES */

/* Path to the GNU debugger. */
#define STARPU_GDB_PATH "/usr/bin/gdb"

/* use STARPU_GOTO library */
/* #undef STARPU_GOTO */

/* Define to 1 if the target supports __atomic_compare_exchange_n */
#define STARPU_HAVE_ATOMIC_COMPARE_EXCHANGE_N 1

/* Define to 1 if the target supports __atomic_exchange_n */
#define STARPU_HAVE_ATOMIC_EXCHANGE_N 1

/* Define to 1 if the target supports __atomic_fetch_add */
#define STARPU_HAVE_ATOMIC_FETCH_ADD 1

/* Define to 1 if the target supports __atomic_fetch_or */
#define STARPU_HAVE_ATOMIC_FETCH_OR 1

/* Define to 1 if the target supports __atomic_test_and_set */
#define STARPU_HAVE_ATOMIC_TEST_AND_SET 1

/* The blas library is available */
#define STARPU_HAVE_BLAS 1

/* Define to 1 if CUDA device properties include BusID */
#define STARPU_HAVE_BUSID 1

/* The blas library has blas.h */
/* #undef STARPU_HAVE_CBLAS_H */

/* Peer transfers are supported in CUDA */
#define STARPU_HAVE_CUDA_MEMCPY_PEER 1

/* cufftDoubleComplex is available */
#define STARPU_HAVE_CUFFTDOUBLECOMPLEX 1

/* CURAND is available */
#define STARPU_HAVE_CURAND 1

/* compiler supports cxx11 */
#define STARPU_HAVE_CXX11 1

/* Define this on darwin. */
/* #undef STARPU_HAVE_DARWIN */

/* Define to 1 if CUDA device properties include DomainID */
#define STARPU_HAVE_DOMAINID 1

/* Define to 1 if you have the <f77.h> header file. */
/* #undef STARPU_HAVE_F77_H */

/* Define this if a Fortran compiler is available */
/* #undef STARPU_HAVE_FC */

/* Define to 1 if you have the libfftw3 library. */
#define STARPU_HAVE_FFTW 1

/* Define to 1 if you have the libfftw3f library. */
#define STARPU_HAVE_FFTWF 1

/* Define to 1 if you have the libfftw3l library. */
#define STARPU_HAVE_FFTWL 1

/* Define to 1 if you have the <glpk.h> header file. */
/* #undef STARPU_HAVE_GLPK_H */

/* Define to 1 if you have the <hdf5.h> header file. */
/* #undef STARPU_HAVE_HDF5 */

/* Define to 1 if you have the <valgrind/helgrind.h> header file. */
/* #undef STARPU_HAVE_HELGRIND_H */

/* Define to 1 if you have the hwloc library. */
#define STARPU_HAVE_HWLOC 1

/* Define this if icc is available */
/* #undef STARPU_HAVE_ICC */

/* Define to 1 if you have the <leveldb/db.h> header file. */
/* #undef STARPU_HAVE_LEVELDB */

/* libnuma is available */
/* #undef STARPU_HAVE_LIBNUMA */

/* Define to 1 if you have the nvidia-ml library */
#define STARPU_HAVE_LIBNVIDIA_ML 1

/* Define to 1 if you have the MAGMA library. */
/* #undef STARPU_HAVE_MAGMA */

/* Define to 1 if you have the <malloc.h> header file. */
#define STARPU_HAVE_MALLOC_H 1

/* Define to 1 if you have the `memalign' function. */
#define STARPU_HAVE_MEMALIGN 1

/* Define to 1 if you have the <valgrind/memcheck.h> header file. */
/* #undef STARPU_HAVE_MEMCHECK_H */

/* Define to 1 if you have msg.h in msg/. */
/* #undef STARPU_HAVE_MSG_MSG_H */

/* Define to 1 if the function nearbyintf is available. */
#define STARPU_HAVE_NEARBYINTF 1

/* Define to 1 if you have the `posix_memalign' function. */
#define STARPU_HAVE_POSIX_MEMALIGN 1

/* Define to 1 if you have libpoti and it is meant to be used */
/* #undef STARPU_HAVE_POTI */

/* pthread_barrier is available */
#define STARPU_HAVE_PTHREAD_BARRIER 1

/* pthread_setname_np is available */
#define STARPU_HAVE_PTHREAD_SETNAME_NP 1

/* pthread_spin_lock is available */
#define STARPU_HAVE_PTHREAD_SPIN_LOCK 1

/* Define to 1 if the function rintf is available. */
#define STARPU_HAVE_RINTF 1

/* Define to 1 if the function sched_yield is available. */
#define STARPU_HAVE_SCHED_YIELD 1

/* Define to 1 if the function setenv is available. */
#define STARPU_HAVE_SETENV 1

/* Define to 1 if you have actor.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_ACTOR_H */

/* Define to 1 if you have barrier.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_BARRIER_H */

/* Define to 1 if you have cond.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_COND_H */

/* Define to 1 if you have engine.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_ENGINE_H */

/* Define to 1 if you have host.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_HOST_H */

/* Define to 1 if you have msg.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_MSG_H */

/* Define to 1 if you have mutex.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_MUTEX_H */

/* Define to 1 if you have semaphore.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_SEMAPHORE_H */

/* Define to 1 if you have simdag.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_SIMDAG_H */

/* Define to 1 if you have version.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_VERSION_H */

/* Define to 1 if you have zone.h in simgrid/. */
/* #undef STARPU_HAVE_SIMGRID_ZONE_H */

/* Define to 1 if you have the smx_actor_t type. */
/* #undef STARPU_HAVE_SMX_ACTOR_T */

/* statement expressions are available */
#define STARPU_HAVE_STATEMENT_EXPRESSIONS 1

/* Define to 1 if the function strerro_r is available. */
#define STARPU_HAVE_STRERROR_R 1

/* struct timespec is defined */
#define STARPU_HAVE_STRUCT_TIMESPEC 1

/* Define to 1 if the target supports __sync_bool_compare_and_swap */
#define STARPU_HAVE_SYNC_BOOL_COMPARE_AND_SWAP 1

/* Define to 1 if the target supports __sync_fetch_and_add */
#define STARPU_HAVE_SYNC_FETCH_AND_ADD 1

/* Define to 1 if the target supports __sync_fetch_and_or */
#define STARPU_HAVE_SYNC_FETCH_AND_OR 1

/* Define to 1 if the target supports __sync_lock_test_and_set */
#define STARPU_HAVE_SYNC_LOCK_TEST_AND_SET 1

/* Define to 1 if the target supports __sync_synchronize */
#define STARPU_HAVE_SYNC_SYNCHRONIZE 1

/* Define to 1 if the target supports __sync_val_compare_and_swap */
#define STARPU_HAVE_SYNC_VAL_COMPARE_AND_SWAP 1

/* Define to 1 if you have the <unistd.h> header file. */
#define STARPU_HAVE_UNISTD_H 1

/* Define to 1 if the function unsetenv is available. */
#define STARPU_HAVE_UNSETENV 1

/* Define to 1 if you have the <valgrind/valgrind.h> header file. */
/* #undef STARPU_HAVE_VALGRIND_H */

/* Define this on windows. */
/* #undef STARPU_HAVE_WINDOWS */

/* enable X11 */
#define STARPU_HAVE_X11 1

/* Define to 1 if you have base.h in xbt/. */
/* #undef STARPU_HAVE_XBT_BASE_H */

/* Define to 1 if you have config.h in xbt/. */
/* #undef STARPU_HAVE_XBT_CONFIG_H */

/* Define to 1 if you have synchro.h in xbt/. */
/* #undef STARPU_HAVE_XBT_SYNCHRO_H */

/* calibration heuristic value */
#define STARPU_HISTORYMAXERROR 50

/* Define to 1 on Linux */
#define STARPU_LINUX_SYS 1

/* enable long check */
/* #undef STARPU_LONG_CHECK */

/* Major version number of StarPU. */
#define STARPU_MAJOR_VERSION 1

/* Maximum number of CPUs supported */
#define STARPU_MAXCPUS 64

/* maximum number of CUDA devices */
#define STARPU_MAXCUDADEVS 4

/* maximum number of implementations */
#define STARPU_MAXIMPLEMENTATIONS 4

/* maximum number of MIC cores */
#define STARPU_MAXMICCORES 120

/* maximum number of MIC devices */
#define STARPU_MAXMICDEVS 0

/* maximum number of MPI devices */
#define STARPU_MAXMPIDEVS 0

/* maximum number of message-passing kernels */
#define STARPU_MAXMPKERNELS 10

/* maximum number of memory nodes */
#define STARPU_MAXNODES 8

/* maximum number of NUMA nodes */
#define STARPU_MAXNUMANODES 2

/* maximum number of OPENCL devices */
#define STARPU_MAXOPENCLDEVS 8

/* enable memory stats */
/* #undef STARPU_MEMORY_STATS */

/* MIC RMA transfer is enable */
#define STARPU_MIC_USE_RMA 1

/* Minor version number of StarPU. */
#define STARPU_MINOR_VERSION 3

/* use MKL library */
/* #undef STARPU_MKL */

/* use user defined library */
/* #undef STARPU_MLR_MODEL */

/* enable performance model debug */
/* #undef STARPU_MODEL_DEBUG */

/* display MPI verbose debug messages */
/* #undef STARPU_MPI_EXTRA_VERBOSE */

/* Use multiple threads to communicate with slaves */
/* #undef STARPU_MPI_MASTER_SLAVE_MULTIPLE_THREAD */

/* enable StarPU MPI pedantic isend */
/* #undef STARPU_MPI_PEDANTIC_ISEND */

/* display MPI verbose debug messages */
/* #undef STARPU_MPI_VERBOSE */

/* Using native windows threads */
/* #undef STARPU_NATIVE_WINTHREADS */

/* enable new check */
/* #undef STARPU_NEW_CHECK */

/* how many buffers can be manipulated per task */
#define STARPU_NMAXBUFS 8

/* Maximum number of workers */
#define STARPU_NMAXWORKERS 80

/* Maximum number of worker combinations */
#define STARPU_NMAX_COMBINEDWORKERS 64

/* Maximum number of sched_ctxs supported */
#define STARPU_NMAX_SCHED_CTXS 10

/* drivers must progress */
#define STARPU_NON_BLOCKING_DRIVERS 1

/* disable assertions */
/* #undef STARPU_NO_ASSERT */

/* Define to 1 if you use the openblas library. */
#define STARPU_OPENBLAS 1

/* Define to 1 on OpenBSD systems */
/* #undef STARPU_OPENBSD_SYS */

/* Define this to enable using an OpenCL simulator */
/* #undef STARPU_OPENCL_SIMULATOR */

/* enable OpenGL rendering of some examples */
/* #undef STARPU_OPENGL_RENDER */

/* Define this to enable OpenMP runtime support */
/* #undef STARPU_OPENMP */

/* enable performance debug */
/* #undef STARPU_PERF_DEBUG */

/* performance models location */
#define STARPU_PERF_MODEL_DIR "/home/gengz/gpu-v2/exageostat/installdir"

/* enable quick check */
/* #undef STARPU_QUICK_CHECK */

/* Release version number of StarPU. */
#define STARPU_RELEASE_VERSION 9

/* enable debug sc_hypervisor */
/* #undef STARPU_SC_HYPERVISOR_DEBUG */

/* Define this to enable simgrid execution */
/* #undef STARPU_SIMGRID */

/* Define to 1 if you have the `simgrid_init' function. */
/* #undef STARPU_SIMGRID_HAVE_SIMGRID_INIT */

/* Define to 1 if you have the `xbt_barrier_init' function. */
/* #undef STARPU_SIMGRID_HAVE_XBT_BARRIER_INIT */

/* Define this to enable Model Checker in simgrid execution */
/* #undef STARPU_SIMGRID_MC */

/* check spinlock use */
/* #undef STARPU_SPINLOCK_CHECK */

/* location of StarPU sources */

/* Only static compilation was made */
/* #undef STARPU_STATIC_ONLY */

/* use user defined library */
/* #undef STARPU_SYSTEM_BLAS */

/* enable data allocation cache */
#define STARPU_USE_ALLOCATION_CACHE 1

/* Define to 1 if Ayudame 1 is available and should be used */
/* #undef STARPU_USE_AYUDAME1 */

/* Define to 1 if Ayudame 2 is available and should be used */
/* #undef STARPU_USE_AYUDAME2 */

/* CPU driver is activated */
#define STARPU_USE_CPU 1

/* CUDA support is activated */
#define STARPU_USE_CUDA 1

/* Define to 1 if drandr48 is available and should be used */
#define STARPU_USE_DRAND48 1

/* Define to 1 if erandr48_r is available */
#define STARPU_USE_ERAND48_R 1

/* enable FxT traces */
/* #undef STARPU_USE_FXT */

/* MIC workers support is enabled */
/* #undef STARPU_USE_MIC */

/* Message-passing SINKs support is enabled */
/* #undef STARPU_USE_MP */

/* whether the StarPU MPI library is available */
/* #undef STARPU_USE_MPI */

/* MPI Master Slave support is enabled */
/* #undef STARPU_USE_MPI_MASTER_SLAVE */

/* whether the StarPU MPI library (with a native MPI implementation) is
   available */
/* #undef STARPU_USE_MPI_MPI */

/* whether the StarPU MPI library (with a NewMadeleine implementation) is
   available */
/* #undef STARPU_USE_MPI_NMAD */

/* OpenCL support is activated */
/* #undef STARPU_USE_OPENCL */

/* enable sc_hypervisor lib */
/* #undef STARPU_USE_SC_HYPERVISOR */

/* Define to 1 to disable STARPU_SKIP_IF_VALGRIND when running tests. */
/* #undef STARPU_VALGRIND_FULL */

/* display verbose debug messages */
/* #undef STARPU_VERBOSE */

/* workers must call callbacks on sleep/wake-up */
/* #undef STARPU_WORKER_CALLBACKS */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "1.3.9"

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#define restrict __restrict
/* Work around a bug in Sun C++: it does not support _Restrict or
   __restrict__, even though the corresponding Sun C compiler ends up with
   "#define restrict _Restrict" or "#define restrict __restrict__" in the
   previous line.  Perhaps some future version of Sun C++ will work with
   restrict; if so, hopefully it defines __RESTRICT like Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
# define __restrict__
#endif
