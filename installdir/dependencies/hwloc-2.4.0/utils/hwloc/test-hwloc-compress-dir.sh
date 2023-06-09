#!/bin/sh
#-*-sh-*-

#
# Copyright © 2013-2020 Inria.  All rights reserved.
# Copyright © 2014 Cisco Systems, Inc.  All rights reserved.
# See COPYING in top-level directory.
#

HWLOC_top_srcdir="/home/gengz/gpu-v2/exageostat/installdir/dependencies/hwloc-2.4.0"
HWLOC_top_builddir="/home/gengz/gpu-v2/exageostat/installdir/dependencies/hwloc-2.4.0"
srcdir="$HWLOC_top_srcdir/utils/hwloc"
builddir="$HWLOC_top_builddir/utils/hwloc"
compress="$builddir/hwloc-compress-dir"

HWLOC_PLUGINS_PATH=${HWLOC_top_builddir}/hwloc/.libs
export HWLOC_PLUGINS_PATH

HWLOC_DEBUG_CHECK=1
export HWLOC_DEBUG_CHECK

HWLOC_XML_EXPORT_SUPPORT=0
export HWLOC_XML_EXPORT_SUPPORT

if test x0 = x1; then
  # make sure we use default numeric formats
  LANG=C
  LC_ALL=C
  export LANG LC_ALL
fi

: ${TMPDIR=/tmp}
{
  tmp=`
    (umask 077 && mktemp -d "$TMPDIR/fooXXXXXX") 2>/dev/null
  ` &&
  test -n "$tmp" && test -d "$tmp"
} || {
  tmp=$TMPDIR/foo$$-$RANDOM
  (umask 077 && mkdir "$tmp")
} || exit $?

set -e

(cd "$tmp" && gunzip -c $srcdir/test-hwloc-compress-dir.input.tar.gz | tar xf -)
(cd "$tmp" && gunzip -c $srcdir/test-hwloc-compress-dir.output.tar.gz | tar xf -)
(cd "$tmp" && mkdir test-hwloc-compress-dir.newoutput)
(cd "$tmp" && mkdir test-hwloc-compress-dir.newoutput2)

$compress "$tmp/test-hwloc-compress-dir.input" "$tmp/test-hwloc-compress-dir.newoutput"

/usr/bin/diff -u -w -r "$tmp/test-hwloc-compress-dir.output" "$tmp/test-hwloc-compress-dir.newoutput"

$compress -R "$tmp/test-hwloc-compress-dir.newoutput" "$tmp/test-hwloc-compress-dir.newoutput2"

/usr/bin/diff -u -w -r "$tmp/test-hwloc-compress-dir.input" "$tmp/test-hwloc-compress-dir.newoutput2"

rm -rf "$tmp"
