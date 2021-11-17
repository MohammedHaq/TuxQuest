#!/bin/bash                                                                                                                                                                                                                                  



for f in $(find /home/haqm8/CS1XC3/Exam/dist/testing/ -type f ! -name "*output")
do
    echo $f
done
