# Install script for directory: /home/gengz/gpu-v2/exageostat

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/gengz/gpu-v2/exageostat/build/install_dir")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/gengz/gpu-v2/exageostat/build/libexageostat.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/gengz/gpu-v2/exageostat/src/include/MLE.h"
    "/home/gengz/gpu-v2/exageostat/include/context.h"
    "/home/gengz/gpu-v2/exageostat/include/morse_starpu.h"
    "/home/gengz/gpu-v2/exageostat/include/descriptor.h"
    "/home/gengz/gpu-v2/exageostat/include/auxiliary.h"
    "/home/gengz/gpu-v2/exageostat/include/chameleon_starpu.h"
    "/home/gengz/gpu-v2/exageostat/include/runtime_codelet_d.h"
    "/home/gengz/gpu-v2/exageostat/include/exageostat-constants.h"
    "/home/gengz/gpu-v2/exageostat/include/common.h"
    "/home/gengz/gpu-v2/exageostat/include/global.h"
    "/home/gengz/gpu-v2/exageostat/include/compute_z.h"
    "/home/gengz/gpu-v2/exageostat/include/morse_tasks_ds.h"
    "/home/gengz/gpu-v2/exageostat/include/compute_s.h"
    "/home/gengz/gpu-v2/exageostat/include/compute_d.h"
    "/home/gengz/gpu-v2/exageostat/include/compute_c.h"
    "/home/gengz/gpu-v2/exageostat/include/tile.h"
    "/home/gengz/gpu-v2/exageostat/include/async.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_exact/src/include/MLE_exact.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_exact/src/include/MLE_exact_s.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_exact/src/include/MLE_sdexact.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_exact/runtime/starpu/include/starpu_exageostat.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_exact/core/include/exageostatcore.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_approx/src/include/MLE_approx.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_approx/runtime/starpu/include/starpu_exageostat_approx.h"
    "/home/gengz/gpu-v2/exageostat/misc/include/MLE_misc.h"
    "/home/gengz/gpu-v2/exageostat/misc/include/flat_file.h"
    "/home/gengz/gpu-v2/exageostat/r-wrappers/include/rwrappers.h"
    "/home/gengz/gpu-v2/exageostat/include/flops.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_approx/src/include/diag.h"
    "/home/gengz/gpu-v2/exageostat/exageostat_exact/src/include/mixed_prec.h"
    "/home/gengz/gpu-v2/exageostat/cudacore/include/exageostatcudacore.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/gengz/gpu-v2/exageostat/build/exageostat.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/exageostat" TYPE FILE FILES "/home/gengz/gpu-v2/exageostat/build/config.log")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/gengz/gpu-v2/exageostat/build/examples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/gengz/gpu-v2/exageostat/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
