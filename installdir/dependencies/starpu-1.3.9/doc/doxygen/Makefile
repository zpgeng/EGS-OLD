# Makefile.in generated by automake 1.16.3 from Makefile.am.
# doc/doxygen/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2020 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.




am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/starpu
pkgincludedir = $(includedir)/starpu
pkglibexecdir = $(libexecdir)/starpu
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-pc-linux-gnu
host_triplet = x86_64-pc-linux-gnu
target_triplet = x86_64-pc-linux-gnu
##am__append_1 = $(DOX_HTML_DIR) $(DOX_PDF)
#am__append_2 = $(DOX_HTML_DIR)
am__append_3 = $(top_srcdir)/doc/doxygen/html
am__append_4 = $(top_srcdir)/doc/doxygen/starpu.pdf
#am__append_5 = \
#	      $(top_srcdir)/doc/doxygen/chapters/version.sty \
#	      $(top_srcdir)/doc/doxygen/chapters/version.html

subdir = doc/doxygen
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4/acinclude.m4 \
	$(top_srcdir)/m4/ax_cxx_compile_stdcxx.m4 \
	$(top_srcdir)/m4/ax_dlb_callback_arg.m4 \
	$(top_srcdir)/m4/libs.m4 $(top_srcdir)/m4/libtool.m4 \
	$(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 \
	$(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 \
	$(top_srcdir)/m4/pkg.m4 $(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/src/common/config.h \
	$(top_builddir)/src/common/config-src-build.h \
	$(top_builddir)/include/starpu_config.h \
	$(top_builddir)/starpurm/include/starpurm_config.h
CONFIG_CLEAN_FILES = doxygen-config.cfg doxygen_filter.sh
CONFIG_CLEAN_VPATH_FILES =
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
SOURCES =
DIST_SOURCES =
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
am__uninstall_files_from_dir = { \
  test -z "$$files" \
    || { test ! -d "$$dir" && test ! -f "$$dir" && test ! -r "$$dir"; } \
    || { echo " ( cd '$$dir' && rm -f" $$files ")"; \
         $(am__cd) "$$dir" && rm -f $$files; }; \
  }
am__installdirs = "$(DESTDIR)$(txtdir)"
DATA = $(txt_DATA)
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
am__DIST_COMMON = $(srcdir)/Makefile.in \
	$(srcdir)/doxygen-config.cfg.in $(srcdir)/doxygen_filter.sh.in
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
pkglibdir = ${libdir}/starpu
ACLOCAL = ${SHELL} '/home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/build-aux/missing' aclocal-1.16
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 0
AR = ar
AS = as
ATLASDIR = 
AUTOCONF = ${SHELL} '/home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/build-aux/missing' autoconf
AUTOHEADER = ${SHELL} '/home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/build-aux/missing' autoheader
AUTOMAKE = ${SHELL} '/home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/build-aux/missing' automake-1.16
AWK = gawk
BLAS_LIB = openblas
BLAS_LIBS = 
BLAS_OPENBLAS_CFLAGS = -I/usr/include/x86_64-linux-gnu
BLAS_OPENBLAS_LIBS = -L/usr/lib/x86_64-linux-gnu/openblas -lblas
CC = /opt/ecrc/gcc/10.2.0/ub18/bin/gcc
CCDEPMODE = depmode=gcc3
CC_OR_MPICC = /opt/ecrc/gcc/10.2.0/ub18/bin/gcc
CFLAGS = -O3 -g -O2 -gdwarf-2 -g3  -I/usr/include/x86_64-linux-gnu -I/usr/include/x86_64-linux-gnu 
COVERAGE = no
CPP = /opt/ecrc/gcc/10.2.0/ub18/bin/gcc -E
CPPFLAGS = -D_FORTIFY_SOURCE=1 -I/home/gengz/gpu-v2/exageostat/installdir/include -D_GNU_SOURCE 
CXX = /opt/ecrc/gcc/10.2.0/ub18/bin/g++
CXXCPP = /opt/ecrc/gcc/10.2.0/ub18/bin/g++ -E
CXXDEPMODE = depmode=gcc3
CXXFLAGS = -O3 -g -O2 -gdwarf-2 -g3
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DGELS_LIBS = 
DLB_CFLAGS = 
DLB_LIBS = 
DLLTOOL = false
DSYMUTIL = 
DUMPBIN = 
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EXEEXT = 
F77 = /opt/ecrc/gcc/10.2.0/ub18/bin/gfortran
FC = /opt/ecrc/gcc/10.2.0/ub18/bin/gfortran
FCFLAGS = -O3 -g -O2 -gdwarf-2 -g3
FFLAGS = -O3 -g -O2 -gdwarf-2 -g3
FFTWF_CFLAGS = 
FFTWF_LIBS = -lfftw3f
FFTWL_CFLAGS = 
FFTWL_LIBS = -lfftw3l
FFTW_CFLAGS = 
FFTW_LIBS = -lfftw3
FGREP = /bin/grep -F
FXTDIR = 
FXT_CFLAGS = 
FXT_LDFLAGS = 
FXT_LIBS = 
GDB = /usr/bin/gdb
GLOBAL_AM_CFLAGS =  -Wall -Werror=implicit -Werror=implicit-function-declaration
GOTODIR = 
GREP = /bin/grep
HAVE_CXX11 = 1
HAVE_FFTWFL = 1
HELP2MAN = 
HWLOC_CFLAGS = -I/home/gengz/gpu-v2/exageostat/installdir/include -I/usr/include/libxml2
HWLOC_LIBS = -L/home/gengz/gpu-v2/exageostat/installdir/lib -lhwloc
HWLOC_REQUIRES = hwloc
ICC = 
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LD = /usr/bin/ld -m elf_x86_64
LDFLAGS = -L/home/gengz/gpu-v2/exageostat/installdir/lib -gdwarf-2 -g3
LIBOBJS = 
LIBS = -lrt -lrt -lm  -lpthread -lopenblas -L/usr/lib/x86_64-linux-gnu/openblas -lblas 
LIBSOCL_INTERFACE_AGE = 0
LIBSOCL_INTERFACE_CURRENT = 0
LIBSOCL_INTERFACE_REVISION = 3
LIBSTARPUFFT_INTERFACE_AGE = 0
LIBSTARPUFFT_INTERFACE_CURRENT = 2
LIBSTARPUFFT_INTERFACE_REVISION = 1
LIBSTARPUMPI_INTERFACE_AGE = 0
LIBSTARPUMPI_INTERFACE_CURRENT = 3
LIBSTARPUMPI_INTERFACE_REVISION = 2
LIBSTARPURM_INTERFACE_AGE = 0
LIBSTARPURM_INTERFACE_CURRENT = 2
LIBSTARPURM_INTERFACE_REVISION = 0
LIBSTARPU_INTERFACE_AGE = 0
LIBSTARPU_INTERFACE_CURRENT = 8
LIBSTARPU_INTERFACE_REVISION = 0
LIBSTARPU_LDFLAGS =   -lcudart -lcublas -lcudart -lcusparse -lnvidia-ml -lstdc++ -L/home/gengz/gpu-v2/exageostat/installdir/lib -lhwloc            
LIBSTARPU_LINK = libstarpu-1.3.la
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIPO = 
LN_S = ln -s
LTLIBOBJS = 
LT_SYS_LIBRARY_PATH = 
MAGMA_CFLAGS = 
MAGMA_LIBS = 
MAKEINFO = ${SHELL} '/home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/build-aux/missing' makeinfo
MANIFEST_TOOL = :
MKDIR_P = /bin/mkdir -p
MPICC = no
MPICC_LDFLAGS = 
MPICXX = no
MPIEXEC = /usr/bin/mpiexec
MPIEXEC_ARGS = 
MPIFORT = 
NM = /usr/bin/nm -B
NMAD_CFLAGS = 
NMAD_LIBS = 
NMEDIT = 
NVCC = /opt/ecrc/cuda/11.4/bin/nvcc
NVCCFLAGS = -std=c++11  -Wno-deprecated-gpu-targets -m64
NVCC_CC = 
OBJDUMP = objdump
OBJEXT = o
OPENBLAS_CFLAGS = -I/usr/include/x86_64-linux-gnu
OPENBLAS_LIBS = -lopenblas
OPENMP_CFLAGS = 
OTOOL = 
OTOOL64 = 
PACKAGE = starpu
PACKAGE_BUGREPORT = starpu-devel@inria.fr
PACKAGE_NAME = StarPU
PACKAGE_STRING = StarPU 1.3.9
PACKAGE_TARNAME = starpu
PACKAGE_URL = http://gitlab.inria.fr/starpu/starpu
PACKAGE_VERSION = 1.3.9
PATH_SEPARATOR = :
PKG_CONFIG = /usr/bin/pkg-config
POTI_CFLAGS = 
POTI_LIBS = 
PROG_DATE = date
PROG_FIND = /usr/bin/find
PROG_STAT = stat
RANLIB = ranlib
REALBASH = /bin/bash
SED = /bin/sed
SET_MAKE = 
SHELL = /bin/sh
SIMGRID_CFLAGS = 
SIMGRID_LIBS = 
SIMGRID_MC = 
SOCL_OCL_LIB_OPENCL_DIR = 
SOCL_VENDORS = vendors/install/socl.icd vendors/nvidia.icd
STARPU_BLAS_LDFLAGS = 
STARPU_BUILD_DIR = /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9
STARPU_COI_CPPFLAGS = 
STARPU_COI_LDFLAGS = 
STARPU_CUDA_CPPFLAGS = 
STARPU_CUDA_FORTRAN_LDFLAGS = 
STARPU_CUDA_LDFLAGS =  -lcudart -lcublas -lcudart -lcusparse -lnvidia-ml -lstdc++
STARPU_CUFFT_LDFLAGS = -lcufft
STARPU_CURAND_LDFLAGS =  -lcurand
STARPU_EFFECTIVE_VERSION = 1.3
STARPU_EXPORTED_LIBS =  -lpthread
STARPU_EXPORT_DYNAMIC = 
STARPU_GLPK_LDFLAGS =  
STARPU_HAVE_CXX11 = 1
STARPU_HAVE_F77_H = no
STARPU_HAVE_FFTW = 1
STARPU_HAVE_FFTWF = 1
STARPU_HAVE_HWLOC = 1
STARPU_HAVE_MAGMA = 
STARPU_HDF5_LDFLAGS = 
STARPU_LAPACK_LDFLAGS = 
STARPU_LEVELDB_LDFLAGS = 
STARPU_LIBNUMA_LDFLAGS =  
STARPU_MAJOR_VERSION = 1
STARPU_MINOR_VERSION = 3
STARPU_MS_LIB = 
STARPU_MS_LIB_ARCH = X64
STARPU_OPENBLAS = 1
STARPU_OPENBLAS_LDFLAGS = 
STARPU_OPENCL_CPPFLAGS = 
STARPU_OPENCL_DATAdir = 
STARPU_OPENCL_LDFLAGS = 
STARPU_OPENGL_RENDER = no
STARPU_OPENGL_RENDER_LDFLAGS = 
STARPU_PERF_DEBUG = no
STARPU_RELEASE_VERSION = 9
STARPU_SCIF_CPPFLAGS = 
STARPU_SCIF_LDFLAGS = 
STARPU_SC_HYPERVISOR = 
STARPU_SC_HYPERVISOR_DEBUG = no
STARPU_SRC_DIR = /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/.
STARPU_USE_CPU = yes
STARPU_USE_CUDA = yes
STARPU_USE_FXT = no
STARPU_USE_OPENCL = no
STRIP = strip
VERSION = 1.3.9
XMKMF = 
X_CFLAGS = 
X_EXTRA_LIBS = 
X_LIBS = 
X_PRE_LIBS =  -lSM -lICE
abs_builddir = /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/doc/doxygen
abs_srcdir = /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/doc/doxygen
abs_top_builddir = /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9
abs_top_srcdir = /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9
ac_ct_AR = ar
ac_ct_CC = /opt/ecrc/gcc/10.2.0/ub18/bin/gcc
ac_ct_CXX = 
ac_ct_DUMPBIN = 
ac_ct_F77 = 
ac_ct_FC = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-pc-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = pc
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
doxygencommand = 
dvidir = ${docdir}
epstopdfcommand = /usr/bin/epstopdf
exec_prefix = ${prefix}
gitcommand = /usr/bin/git
host = x86_64-pc-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/gengz/gpu-v2/exageostat/installdir/dependencies/starpu-1.3.9/build-aux/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
mpicc_path = no
mpicxx_path = no
mpiexec_path = /usr/bin/mpiexec
mpifort_path = 
oldincludedir = /usr/include
pdfdir = ${docdir}
pdflatexcommand = /usr/bin/pdflatex
prefix = /home/gengz/gpu-v2/exageostat/installdir
program_transform_name = s,x,x,
psdir = ${docdir}
runstatedir = ${localstatedir}/run
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target = x86_64-pc-linux-gnu
target_alias = 
target_cpu = x86_64
target_os = linux-gnu
target_vendor = pc
top_build_prefix = ../../
top_builddir = ../..
top_srcdir = ../..

# StarPU --- Runtime system for heterogeneous multicore architectures.
#
# Copyright (C) 2009-2021  Université de Bordeaux, CNRS (LaBRI UMR 5800), Inria
#
# StarPU is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 2.1 of the License, or (at
# your option) any later version.
#
# StarPU is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# See the GNU Lesser General Public License in COPYING.LGPL for more details.
#
DOXYGEN = doxygen
PDFLATEX = pdflatex
MAKEINDEX = makeindex
DOX_DIR = $(top_builddir)/doc/doxygen
DOX_CONFIG = $(top_srcdir)/doc/doxygen/doxygen.cfg
DOX_HTML_DIR = html
DOX_LATEX_DIR = latex
DOX_PDF = $(DOX_DIR)/starpu.pdf
DOX_TAG = starpu.tag
txtdir = $(docdir)/manual
EXTRA_DIST = $(am__append_1) $(am__append_2) $(am__append_3) \
	$(am__append_4) $(am__append_5) doxygen.cfg refman.tex \
	$(chapters) $(images)
txt_DATA = $(top_srcdir)/doc/doxygen/starpu.pdf
##txt_DATA = $(DOX_PDF)
DOX_HTML_SRCDIR = $(top_srcdir)/doc/doxygen/html
#DOX_HTML_SRCDIR = $(DOX_HTML_DIR)
chapters = \
	chapters/000_introduction.doxy		\
	chapters/101_building.doxy		\
	chapters/110_basic_examples.doxy		\
	chapters/201_advanced_examples.doxy		\
	chapters/210_check_list_performance.doxy		\
	chapters/301_tasks.doxy		\
	chapters/310_data_management.doxy		\
	chapters/320_scheduling.doxy		\
	chapters/330_scheduling_contexts.doxy		\
	chapters/340_scheduling_context_hypervisor.doxy		\
	chapters/350_scheduling_policy_definition.doxy		\
	chapters/360_debugging_tools.doxy		\
	chapters/370_online_performance_tools.doxy		\
	chapters/380_offline_performance_tools.doxy		\
	chapters/390_faq.doxy		\
	chapters/401_out_of_core.doxy		\
	chapters/410_mpi_support.doxy		\
	chapters/420_fft_support.doxy		\
	chapters/430_mic_support.doxy		\
	chapters/450_native_fortran_support.doxy		\
	chapters/460_socl_opencl_extensions.doxy		\
	chapters/470_simgrid.doxy		\
	chapters/480_openmp_runtime_support.doxy		\
	chapters/490_clustering_a_machine.doxy		\
	chapters/495_interoperability.doxy		\
	chapters/501_environment_variables.doxy		\
	chapters/510_configure_options.doxy		\
	chapters/520_files.doxy		\
	chapters/601_scaling_vector_example.doxy		\
	chapters/610_fdl_1_3.doxy		\
	chapters/code/forkmode.c \
	chapters/code/multiformat.c \
	chapters/code/complex.c \
	chapters/code/simgrid.c \
	chapters/code/vector_scal_c.c \
	chapters/code/vector_scal_cpu.c \
	chapters/code/vector_scal_cuda.c \
	chapters/code/vector_scal_opencl.c \
	chapters/code/vector_scal_opencl_codelet.cl \
	chapters/code/disk_copy.c \
	chapters/code/disk_compute.c \
	chapters/code/nf_initexit.f90 \
	chapters/api/fft_support.doxy \
	chapters/api/versioning.doxy \
	chapters/api/threads.doxy

images = \
	chapters/images/data_trace.eps \
	chapters/images/data_trace.pdf \
	chapters/images/data_trace.png \
	chapters/images/distrib_data.eps \
	chapters/images/distrib_data.pdf \
	chapters/images/distrib_data.png \
	chapters/images/distrib_data_histo.eps \
	chapters/images/distrib_data_histo.pdf \
	chapters/images/distrib_data_histo.png \
	chapters/images/paje_draw_histogram.eps \
	chapters/images/paje_draw_histogram.pdf \
	chapters/images/paje_draw_histogram.png \
	chapters/images/parallel_worker2.eps \
	chapters/images/parallel_worker2.pdf \
	chapters/images/parallel_worker2.png \
	chapters/images/runtime-par.eps \
	chapters/images/runtime-par.pdf \
	chapters/images/runtime-par.png \
	chapters/images/starpu_non_linear_memset_regression_based.eps \
	chapters/images/starpu_non_linear_memset_regression_based.pdf \
	chapters/images/starpu_non_linear_memset_regression_based.png \
	chapters/images/starpu_non_linear_memset_regression_based_2.eps \
	chapters/images/starpu_non_linear_memset_regression_based_2.pdf \
	chapters/images/starpu_non_linear_memset_regression_based_2.png \
	chapters/images/starpu_starpu_slu_lu_model_11.eps \
	chapters/images/starpu_starpu_slu_lu_model_11.pdf \
	chapters/images/starpu_starpu_slu_lu_model_11.png \
	chapters/images/starpu_chol_model_11_type.eps \
	chapters/images/starpu_chol_model_11_type.pdf \
	chapters/images/starpu_chol_model_11_type.png \
	chapters/images/tasks_size_overhead.eps \
	chapters/images/tasks_size_overhead.pdf \
	chapters/images/tasks_size_overhead.png \
	chapters/images/temanejo.png

#dox_inputs = $(DOX_CONFIG) 				\
#	$(chapters) 					\
#	starpu_config.h					\
#	chapters/version.sty				\
#	chapters/version.html				\
#	$(top_srcdir)/include/starpu.h			\
#	$(top_srcdir)/include/starpu_bitmap.h		\
#	$(top_srcdir)/include/starpu_bound.h		\
#	$(top_srcdir)/include/starpu_clusters.h		\
#	$(top_srcdir)/include/starpu_cublas.h		\
#	$(top_srcdir)/include/starpu_cublas_v2.h	\
#	$(top_srcdir)/include/starpu_cusparse.h		\
#	$(top_srcdir)/include/starpu_cuda.h		\
#	$(top_srcdir)/include/starpu_data_filters.h	\
#	$(top_srcdir)/include/starpu_data.h		\
#	$(top_srcdir)/include/starpu_data_interfaces.h	\
#	$(top_srcdir)/include/starpu_deprecated_api.h	\
#	$(top_srcdir)/include/starpu_disk.h		\
#	$(top_srcdir)/include/starpu_driver.h		\
#	$(top_srcdir)/include/starpu_expert.h		\
#	$(top_srcdir)/include/starpu_fxt.h		\
#	$(top_srcdir)/include/starpu_hash.h		\
#	$(top_srcdir)/include/starpu_mic.h		\
#	$(top_srcdir)/include/starpu_mod.f90		\
#	$(top_srcdir)/include/starpu_opencl.h		\
#	$(top_srcdir)/include/starpu_openmp.h		\
#	$(top_srcdir)/include/starpu_perfmodel.h	\
#	$(top_srcdir)/include/starpu_profiling.h	\
#	$(top_srcdir)/include/starpu_rand.h		\
#	$(top_srcdir)/include/starpu_sched_component.h	\
#	$(top_srcdir)/include/starpu_sched_ctx.h	\
#	$(top_srcdir)/include/starpu_sched_ctx_hypervisor.h	\
#	$(top_srcdir)/include/starpu_scheduler.h	\
#	$(top_srcdir)/include/starpu_simgrid_wrap.h	\
#	$(top_srcdir)/include/starpu_sink.h		\
#	$(top_srcdir)/include/starpu_stdlib.h		\
#	$(top_srcdir)/include/starpu_task_bundle.h	\
#	$(top_srcdir)/include/starpu_task_dep.h		\
#	$(top_srcdir)/include/starpu_task.h		\
#	$(top_srcdir)/include/starpu_task_list.h	\
#	$(top_srcdir)/include/starpu_task_util.h	\
#	$(top_srcdir)/include/starpu_thread.h		\
#	$(top_srcdir)/include/starpu_thread_util.h	\
#	$(top_srcdir)/include/starpu_tree.h		\
#	$(top_srcdir)/include/starpu_util.h		\
#	$(top_srcdir)/include/starpu_worker.h		\
#	$(top_srcdir)/include/fstarpu_mod.f90		\
#	$(top_srcdir)/mpi/include/starpu_mpi.h 		\
#	$(top_srcdir)/mpi/include/starpu_mpi_lb.h	\
#	$(top_srcdir)/mpi/include/fstarpu_mpi_mod.f90		\
#	$(top_srcdir)/sc_hypervisor/include/sc_hypervisor.h 		\
#	$(top_srcdir)/sc_hypervisor/include/sc_hypervisor_config.h 	\
#	$(top_srcdir)/sc_hypervisor/include/sc_hypervisor_lp.h		\
#	$(top_srcdir)/sc_hypervisor/include/sc_hypervisor_monitoring.h	\
#	$(top_srcdir)/sc_hypervisor/include/sc_hypervisor_policy.h	\
#	$(top_srcdir)/starpurm/include/starpurm.h

#CLEANFILES = $(DOX_TAG) starpu_config.h \
#    -r \
#    $(DOX_HTML_DIR) \
#    $(DOX_LATEX_DIR) \
#    $(DOX_PDF)

all: all-am

.SUFFIXES:
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign doc/doxygen/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign doc/doxygen/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
doxygen-config.cfg: $(top_builddir)/config.status $(srcdir)/doxygen-config.cfg.in
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@
doxygen_filter.sh: $(top_builddir)/config.status $(srcdir)/doxygen_filter.sh.in
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs
install-txtDATA: $(txt_DATA)
	@$(NORMAL_INSTALL)
	@list='$(txt_DATA)'; test -n "$(txtdir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(txtdir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(txtdir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_DATA) $$files '$(DESTDIR)$(txtdir)'"; \
	  $(INSTALL_DATA) $$files "$(DESTDIR)$(txtdir)" || exit $$?; \
	done

uninstall-txtDATA:
	@$(NORMAL_UNINSTALL)
	@list='$(txt_DATA)'; test -n "$(txtdir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(txtdir)'; $(am__uninstall_files_from_dir)
tags TAGS:

ctags CTAGS:

cscope cscopelist:


distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(DATA)
installdirs:
	for dir in "$(DESTDIR)$(txtdir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
#install-exec-hook:
#uninstall-hook:
clean: clean-am

clean-am: clean-generic clean-libtool mostlyclean-am

distclean: distclean-am
	-rm -f Makefile
distclean-am: clean-am distclean-generic

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am: install-txtDATA

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am:
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) install-exec-hook
install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-generic mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-txtDATA
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) uninstall-hook
.MAKE: install-am install-exec-am install-strip uninstall-am

.PHONY: all all-am check check-am clean clean-generic clean-libtool \
	cscopelist-am ctags-am distclean distclean-generic \
	distclean-libtool distdir dvi dvi-am html html-am info info-am \
	install install-am install-data install-data-am install-dvi \
	install-dvi-am install-exec install-exec-am install-exec-hook \
	install-html install-html-am install-info install-info-am \
	install-man install-pdf install-pdf-am install-ps \
	install-ps-am install-strip install-txtDATA installcheck \
	installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-generic \
	mostlyclean-libtool pdf pdf-am ps ps-am tags-am uninstall \
	uninstall-am uninstall-hook uninstall-txtDATA

.PRECIOUS: Makefile


##all: $(DOX_HTML_DIR) $(DOX_PDF)
#all: $(DOX_HTML_DIR)
#install-exec-hook:
#	$(MKDIR_P) $(DESTDIR)$(docdir)/manual/html
#	(cd $(DOX_HTML_SRCDIR) && $(PROG_FIND) . -type f -exec $(INSTALL_DATA) {} $(DESTDIR)$(docdir)/manual/html \;)
#uninstall-hook:
#	rm -rf $(DESTDIR)$(docdir)/manual/html
install-exec-hook:
	$(MKDIR_P) $(DESTDIR)$(docdir)/manual/html
	(cd $(DOX_HTML_SRCDIR) && $(PROG_FIND) . -type f -exec $(INSTALL_DATA) {} $(DESTDIR)$(docdir)/manual/html \;)
uninstall-hook:
	rm -rf $(DESTDIR)$(docdir)/manual/html

#starpu_config.h: $(top_srcdir)/include/starpu_config.h.in
#	@$(SED) 's/#undef \(.*\)/#define \1 1/' $< > $@

#chapters/version.sty: $(chapters)
#	@for f in $(chapters) ; do \
#                if test -f $(top_srcdir)/doc/doxygen/$$f ; then $(PROG_STAT) --format=%Y $(top_srcdir)/doc/doxygen/$$f ; fi \
#        done | sort -r | head -1 > timestamp_sty
#	@if test -s timestamp_sty ; then \
#		LC_ALL=C $(PROG_DATE) --date=@`cat timestamp_sty` +"%F" > timestamp_sty_updated ;\
#		LC_ALL=C $(PROG_DATE) --date=@`cat timestamp_sty` +"%B %Y" > timestamp_sty_updated_month ;\
#	fi
#	@if test -s timestamp_sty_updated ; then \
#		echo ':newcommand{:STARPUUPDATED}{'`cat timestamp_sty_updated`'}' > $(top_srcdir)/doc/doxygen/chapters/version.sty;\
#	else \
#		echo ':newcommand{:STARPUUPDATED}{unknown date}' > $(top_srcdir)/doc/doxygen/chapters/version.sty;\
#	fi
#	@echo ':newcommand{:STARPUVERSION}{$(VERSION)}' >> $(top_srcdir)/doc/doxygen/chapters/version.sty
#	@$(SED) -i 's/:/\\/g' $(top_srcdir)/doc/doxygen/chapters/version.sty
#	@for f in timestamp_sty timestamp_sty_updated timestamp_sty_updated_month ; do \
#		if test -f $$f ; then $(RM) $$f ; fi ;\
#	done

#chapters/version.html: $(chapters)
#	@for f in $(chapters) ; do \
#                if test -f $(top_srcdir)/doc/doxygen/$$f ; then $(PROG_STAT) --format=%Y $(top_srcdir)/doc/doxygen/$$f ; fi \
#        done | sort -r | head -1 > timestamp_html
#	@if test -s timestamp_html ; then \
#		LC_ALL=C $(PROG_DATE) --date=@`cat timestamp_html` +"%F" > timestamp_html_updated ;\
#		LC_ALL=C $(PROG_DATE) --date=@`cat timestamp_html` +"%B %Y" > timestamp_html_updated_month ;\
#	fi
#	@echo "This manual documents the usage of StarPU version $(VERSION)." > $(top_srcdir)/doc/doxygen/chapters/version.html
#	@if test -s timestamp_html_updated ; then \
#		echo "Its contents was last updated on "`cat timestamp_html_updated`"." >> $(top_srcdir)/doc/doxygen/chapters/version.html;\
#	else \
#		echo "Its contents was last updated on <em>unknown_date</em>." >> $(top_srcdir)/doc/doxygen/chapters/version.html;\
#	fi
#	@for f in timestamp_html timestamp_html_updated timestamp_html_updated_month ; do \
#		if test -f $$f ; then $(RM) $$f ; fi ;\
#	done

#doxy:
#	@rm -fr $(DOX_HTML_DIR) $(DOX_LATEX_DIR)
#	@$(DOXYGEN) $(DOX_CONFIG)

#$(DOX_TAG): $(dox_inputs)
#	@rm -fr $(DOX_HTML_DIR) $(DOX_LATEX_DIR)
#	@$(DOXYGEN) $(DOX_CONFIG)
#	@$(SED) -i 's/ModuleDocumentation <\/li>/<a class="el" href="modules.html">Modules<\/a>/' html/index.html
#	@$(SED) -i 's/FileDocumentation <\/li>/<a class="el" href="files.html">Files<\/a>/' html/index.html
#        # comment for the line below: what we really want to do is to remove the line, but dy doing so, it avoids opening the interactive menu when browsing files
#	@if test -f html/navtree.js ; then $(SED) -i 's/\[ "Files", "Files.html", null \]/\[ "", "Files.html", null \]/' html/navtree.js ; fi
#	@$(SED) -i 's/.*"Files.html".*//' html/pages.html
#	@if test -f latex/main.tex ; then mv latex/main.tex latex/index.tex ; fi
#	@$(SED) -i '/\\begin{titlepage}/,$$d' $(DOX_LATEX_DIR)/refman.tex
#	@cat $(top_srcdir)/doc/doxygen/refman.tex >> $(DOX_LATEX_DIR)/refman.tex

#$(DOX_HTML_DIR): $(DOX_TAG)

#$(DOX_PDF): $(DOX_TAG) refman.tex
#	@cp $(top_srcdir)/doc/doxygen/chapters/version.sty $(DOX_LATEX_DIR)
#	@cp $(top_srcdir)/doc/doxygen/chapters/images/*pdf $(DOX_LATEX_DIR)
#	@echo $(PDFLATEX) $(DOX_LATEX_DIR)/refman.tex
#	@cd $(DOX_LATEX_DIR) ;\
#	rm -f *.aux *.toc *.idx *.ind *.ilg *.log *.out ;\
#	$(SED) -i -e 's/__env__/\\_Environment Variables!/' -e 's/\\-\\_\\-\\-\\_\\-env\\-\\_\\-\\-\\_\\-//' ExecutionConfigurationThroughEnvironmentVariables.tex ;\
#	$(SED) -i -e 's/__configure__/\\_Configure Options!/' -e 's/\\-\\_\\-\\-\\_\\-configure\\-\\_\\-\\-\\_\\-//' CompilationConfiguration.tex ;\
#	$(SED) -i s'/\\item Module\\.Documentation/\\item \\hyperlink{ModuleDocumentation}{Module Documentation}/' index.tex ;\
#	$(SED) -i s'/\\item File\\.Documentation/\\item \\hyperlink{FileDocumentation}{File Documentation}/' index.tex ;\
#	max_print_line=1000000 $(PDFLATEX) -interaction batchmode refman.tex ;\
#	! < refman.log grep -v group__ | grep -v _amgrp | grep -v deprecated__ | grep "multiply defined" || exit 1 ;\
#	$(MAKEINDEX) refman.idx ;\
#	max_print_line=1000000 $(PDFLATEX) -interaction batchmode refman.tex ;\
#	done=0; repeat=5 ;\
#	while test $$done = 0 -a $$repeat -gt 0; do \
#           if $(EGREP) 'Rerun (LaTeX|to get cross-references right)' refman.log > /dev/null 2>&1; then \
#	       max_print_line=1000000 $(PDFLATEX) -interaction batchmode refman.tex; \
#	       repeat=`expr $$repeat - 1`; \
#	   else \
#	       done=1; \
#	   fi; \
#	done
#	mv $(DOX_LATEX_DIR)/refman.pdf $(DOX_PDF)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
