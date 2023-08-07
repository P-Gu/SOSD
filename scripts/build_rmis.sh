#! /usr/bin/env bash
git submodule update --init --recursive

rm -rf rmi_data
mkdir -p rmi_data
rm -rf /home/pgu/git/SOSD/competitors/rmi/*


function build_rmi_set() {
    DATA_NAME=$1
    HEADER_PATH=competitors/rmi/${DATA_NAME}_0.h
    JSON_PATH=scripts/rmi_specs/${DATA_NAME}.json

    shift 1
    if [ ! -f $HEADER_PATH ]; then
        echo "Building RMI set for $DATA_NAME"
        RMI/target/release/rmi data/$DATA_NAME --param-grid ${JSON_PATH} -d rmi_data/ --threads 8 --zero-build-time
        mv ${DATA_NAME}_* competitors/rmi/
    fi
}


cd RMI && cargo build --release && cd ..

#build_rmi_set fb_150K_uint64
#build_rmi_set fb_200M_uint64

#build_rmi_set books_150K_uint64
#build_rmi_set books_200M_uint64
build_rmi_set books_1M_uint64
#build_rmi_set fb_1M_uint64
#build_rmi_set books_1M_uint64


scripts/rmi_specs/gen.sh

