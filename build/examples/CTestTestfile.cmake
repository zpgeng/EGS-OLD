# CMake generated Testfile for 
# Source directory: /home/gengz/gpu-v2/exageostat/examples
# Build directory: /home/gengz/gpu-v2/exageostat/build/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(synthetic_dmle_test_matern_stationary_ooc "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=6400" "--dts=512" "--ncores=52" "--computation=exact" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--ooc" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_dmle_test_matern_stationary_ooc PROPERTIES  ENVIRONMENT "STARPU_SILENT=1;STARPU_LIMIT_CPU_MEM=100;STARPU_DISK_SWAP=\"/tmp\";STARPU_DISK_SWAP_BACKEND=unistd;STARPU_DISK_SWAP_SIZE=1024" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;54;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_ooc "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=6400" "--dts=512" "--ncores=52" "--computation=exact" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--ooc" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_dmle_test_ooc PROPERTIES  ENVIRONMENT "STARPU_SILENT=1;STARPU_LIMIT_CPU_MEM=100;STARPU_DISK_SWAP=\"/tmp\";STARPU_DISK_SWAP_BACKEND=unistd;STARPU_DISK_SWAP_SIZE=1024" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;76;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_sdmle_test_ooc "numactl" "--interleave=all" "./synthetic_sdmle_test" "--test" "--N=6400" "--dts=512" "--ncores=52" "--computation=exact" "--diag_thick=1" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--ooc" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_sdmle_test_ooc PROPERTIES  ENVIRONMENT "STARPU_SILENT=1;STARPU_LIMIT_CPU_MEM=100;STARPU_DISK_SWAP=\"/tmp\";STARPU_DISK_SWAP_BACKEND=unistd;STARPU_DISK_SWAP_SIZE=1024" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;99;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_smle_test_ooc "numactl" "--interleave=all" "./synthetic_smle_test" "--test" "--N=6400" "--dts=512" "--ncores=52" "--computation=exact" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--ooc" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_smle_test_ooc PROPERTIES  ENVIRONMENT "STARPU_SILENT=1;STARPU_LIMIT_CPU_MEM=100;STARPU_DISK_SWAP=\"/tmp\";STARPU_DISK_SWAP_BACKEND=unistd;STARPU_DISK_SWAP_SIZE=1024" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;123;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_diag_approx_t1 "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=19881" "--dts=960" "--ncores=52" "--computation=diag_approx" "--diag_thick=5" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--predict=10" "--lts=1900" "--acc=5" "--maxrank=300" "--opt_iters=5" "--opt_tol=2" "--predict=100" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_dmle_test_diag_approx_t1 PROPERTIES  ENVIRONMENT "STARPU_SILENT=1" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;165;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_lr_approx_t1 "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=8100" "--dts=960" "--ncores=52" "--computation=lr_approx" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--predict=100" "--lts=1000" "--acc=7" "--maxrank=400" "--opt_iters=2" "--opt_tol=4" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_dmle_test_lr_approx_t1 PROPERTIES  ENVIRONMENT "STARPU_SILENT=1" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;191;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_mloe_mmom "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=6400" "--dts=512" "--ncores=52" "--computation=exact" "--kernel=?:?:?" "--ikernel=1:0.1:0.5" "--olb=0.01:0.01:0.01" "--oub=5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--predict=10" "--mloe_mmom" "--kernel_fun=univariate_matern_stationary")
set_tests_properties(synthetic_dmle_test_mloe_mmom PROPERTIES  ENVIRONMENT "STARPU_SILENT=1" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;299;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_bivariate_parsimonious "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=6400" "--dts=512" "--ncores=52" "--computation=exact" "--kernel=?:?:?:?:?:?" "--ikernel=1:1:0.1:0.5::0.5:0.1" "--olb=0.01:0.01:0.01:0.01:0.01:0.01" "--oub=5:5:5:5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--predict=10" "--kernel_fun=bivariate_matern_parsimonious")
set_tests_properties(synthetic_dmle_test_bivariate_parsimonious PROPERTIES  ENVIRONMENT "STARPU_SILENT=1" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;323;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_bivariate_parsimonious_tlr "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=1600" "--dts=320" "--ncores=52" "--computation=lr_approx" "--kernel=?:?:?:?:?:?" "--ikernel=1:1:0.1:0.5::0.5:0.1" "--olb=0.01:0.01:0.01:0.01:0.01:0.01" "--oub=5:5:5:5:5:5" "--zvecs=1" "--opt_iters=5" "--opt_tol=4" "--acc=5" "--maxrank=400" "--lts=600" "--kernel_fun=bivariate_matern_parsimonious")
set_tests_properties(synthetic_dmle_test_bivariate_parsimonious_tlr PROPERTIES  ENVIRONMENT "STARPU_SILENT=1" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;346;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
add_test(synthetic_dmle_test_bivariate_parsimonious_dst "numactl" "--interleave=all" "./synthetic_dmle_test" "--test" "--N=1600" "--dts=320" "--ncores=52" "--computation=diag_approx" "--kernel=?:?:?:?:?:?" "--ikernel=1:1:0.1:0.5::0.5:0.1" "--olb=0.01:0.01:0.01:0.01:0.01:0.01" "--oub=5:5:5:5:5:5" "--zvecs=1" "--opt_iters=10" "--opt_tol=4" "--diag_thick=2" "--kernel_fun=bivariate_matern_parsimonious")
set_tests_properties(synthetic_dmle_test_bivariate_parsimonious_dst PROPERTIES  ENVIRONMENT "STARPU_SILENT=1" _BACKTRACE_TRIPLES "/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;371;add_test;/home/gengz/gpu-v2/exageostat/examples/CMakeLists.txt;0;")
