#!/bin/bash

# Define a function that attempts to locate a
# plugin with a given canonical name.
# Assumptions:
#   1. plugins is a top-level directory
# Inputs:
#   $1 is the canonical name
#   $2 is 1 if we are running under cmake
#   $3 is 1 if we are running using Visual Studio, blank otherwise
#   $4 is the build type; only used if $3 is 1
# Outputs:
#   return code is 0 is success, 1 if failed
#   Variable HDF5_PLUGIN_LIB is set to the library file name
#   Variable HDF5_PLUGIN_PATH is setthe absolute path to the
#                    directory containing the plugin library file
# Local variables are prefixed with FP_
#
# Note: we assume that the use of the CMAKE_BUILD_TYPE
# is obviated by setting the LIBRARY_OUTPUT_DIRECTORY
# variables: see hdf5plugins/CMakeLists.txt

findplugin() {

FP_NAME="$1"

# Figure out the compiler (some values from ./configure)
FP_ISCMAKE=
FP_ISMSVC=

# And topsrcdir
topbuilddir='/home/gengz/gpu-v2/exageostat/installdir/dependencies/netcdf-c-4.7.4'

# Are we operating under OS-X? (test using uname)
FP_OS=`uname | cut -d '_'  -f 1`
if test "x$FP_OS" = xDarwin ; then FP_ISOSX=1; fi

# Are we operating under CYGWIN? (test using uname)
FP_OS=`uname | cut -d '_'  -f 1`
if test "x$FP_OS" = xCYGWIN ; then FP_ISCYGWIN=1; fi

FP_PLUGINS="$topbuilddir/plugins"

FP_PLUGIN_LIB=
FP_PLUGIN_PATH=

# Figure out the plugin file name
# Test for visual studio before cygwin since both might be true
if test "x$FP_ISMSVC" != x ; then
  FP_PLUGIN_LIB="${FP_NAME}.dll"
elif test "x$FP_ISCYGWIN" != x ; then
  FP_PLUGIN_LIB="cyg${FP_NAME}.dll"
elif test "x$FP_ISOSX" != x ; then
  FP_PLUGIN_LIB="lib${FP_NAME}.so" # Should this include the version number in the name?
else # Presumably some form on *nix"
  FP_PLUGIN_LIB="lib${FP_NAME}.so"
fi

# Figure out the path to where the lib is stored
# This can probably be simplified
# Case 1: Cmake with Visual Studio
# Do not know where to look for a dylib
# Case 1: Cmake with Visual Studio
if test "x$FP_ISCMAKE" != x -a "x${FP_ISMSVC}" != x ; then
  # Case 1a: ignore the build type directory
  if test -f "${FP_PLUGINS}/${FP_PLUGIN_LIB}" ; then
    FP_PLUGIN_PATH="${FP_PLUGINS}"
  fi
else # Case 2: automake
  # Case 2a: look in .libs
  if test -f "${FP_PLUGINS}/.libs/${FP_PLUGIN_LIB}" ; then
    FP_PLUGIN_PATH="${FP_PLUGINS}/.libs"
  else # Case 2: look in FP_PLUGINS directly
    if test -f "${FP_PLUGINS}/${FP_PLUGIN_LIB}" ; then
      FP_PLUGIN_PATH="${FP_PLUGINS}"
    fi
  fi
fi

# Verify
if test "x$FP_PLUGIN_PATH" = x ; then
  echo "***Fail: Could not locate a usable HDF5_PLUGIN_PATH"
  return 1
fi
if ! test -f "$FP_PLUGIN_PATH/$FP_PLUGIN_LIB" ; then
  echo "***Fail: Could not locate a usable HDF5_PLUGIN_LIB"
  return 1
fi

# If we are operating using both Visual Studio and Cygwin,
# then we need to convert the FP_PLUGIN_PATH to windows format
if test "x$FP_ISMSVC" != x -a "x$FP_ISCYGWIN" != x ; then
FP_PLUGIN_PATH=`cygpath -wl $FP_PLUGIN_PATH`
fi

# Set the final output variables
HDF5_PLUGIN_LIB="$FP_PLUGIN_LIB"
HDF5_PLUGIN_PATH="$FP_PLUGIN_PATH"

return 0
}

# debug
if test "x$1" != x ; then
findplugin
echo "HDF5_PLUGIN_PATH=|$FP_PLUGIN_PATH|"
fi
