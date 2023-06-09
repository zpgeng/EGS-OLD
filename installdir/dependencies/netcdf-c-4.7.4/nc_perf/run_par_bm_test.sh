#!/bin/sh

# This shell file tests the bm_ile program for parallel I/O.
# Ed Hartnett

if test "x$srcdir" = x ; then srcdir=`pwd`; fi
. ../test_common.sh

echo ""
for type_name in floats ints shorts
do
    echo "*** Running bm_file for parallel access on simple ${type_name} test files, 1D to 6D..."
    header="-h"
    for i in 1 2 3
    do
	test $i = 1 && chunksizes="100000"
	test $i = 2 && chunksizes="316:316"
	test $i = 3 && chunksizes="46:46:46"
	for numproc in 1 4 16
	do
	    mpiexec -n $numproc ./bm_file -p -d ${header} -s ${numproc} -f 4 -o p_${type_name}2_${i}D_3.nc -c 0:-1:0:${chunksizes} ${type_name}2_${i}D_3.nc
	    ${NCDUMP} -n tst_${type_name}2_${i}D p_${type_name}2_${i}D_3.nc > p_${type_name}2_${i}D.cdl
	    diff tst_${type_name}2_${i}D.cdl p_${type_name}2_${i}D.cdl &> /dev/null
	    header=
	done
    done
    echo '*** SUCCESS!!!'
done

exit 0
