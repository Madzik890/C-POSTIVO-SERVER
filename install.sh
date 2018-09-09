#!/bin/sh

cp lib/libcrypto.so.1.1 /lib64
cp lib/libssl.so.1.1 /lib64

ldconfig

echo "Copied all files." 

make all
