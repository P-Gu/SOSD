#! /usr/bin/env bash
set -e

echo "Compiling benchmark..."
git submodule update --init --recursive 

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j 8 

function generate_lookups() {
    echo "Generating lookups for $1"
    [ -f ../data/$1_equality_lookups_10M ] || ./generate ../data/$1 10000000
    [ -f ../data/$1_equality_lookups_1M ] || ./generate ../data/$1 1000000
}

echo "Generating queries..."
#generate_lookups books_150K_uint64
#generate_lookups books_200M_uint32

#generate_lookups fb_150K_uint64
#generate_lookups fb_200M_uint64
generate_lookups books_1M_uint64
#generate_lookups fb_1M_uint64
#generate_lookups books_1M_uint64

