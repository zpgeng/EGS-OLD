#!/bin/sh

# This .in file is processed at build time into a shell that runs a
# parallel I/O example for pnetcdf.

# Ed Hartnett

set -e
echo
echo "Running pnetcdf parallel I/O example..."
mpiexec -n 4 ./parallel_vara
echo '*** SUCCESS!!!'
