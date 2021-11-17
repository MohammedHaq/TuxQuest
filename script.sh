#!/bin/bash

for f in $(find /home/haqm8/CS1XC3/Exam/dist/testing/ -type f ! -name "*output")
do
    touch "$f".test
    cat $f | ./tuxquest > "$f".test
    diff "$f".test "$f".output
    rm -rf "$f".test
done
    
    
