#!/bin/sh -e

# Define colors
YELLOW='\033[1;33m'
NC='\033[0m' # no color

BASEDIR=$(realpath "$(dirname "$0")")
ROOTDIR=$(realpath "$BASEDIR/..")
BUILDDIR=$ROOTDIR/build

print_header() {
    echo "${YELLOW}############################################################${NC}"
    echo "${YELLOW}### ${1}${NC}"
    echo "${YELLOW}############################################################${NC}"
}

if [ "$1" = "clean" ]; then 
    # clean up previous build
    print_header "clean up previous build"
    if [ -d "$BUILDDIR" ]; then
        rm -rf "$BUILDDIR"

cmake -S "$ROOTDIR" -B "$ROOTDIR/build"
cmake --build "$ROOTDIR/build"
