#!/bin/bash
path='/home/grid/testbed/tb050/Lab3/'
cd $path
                                                                                                                                            
flagsForCmplrOptmztion=(O0 O1 O2 O3 Os Ofast)
i=0
                                                                                                                                            
for flag in ${flagsForCmplrOptmztion[@]}; do
        srcfile="result$i"
        g++ -$flag myprog.cpp -o $srcfile
        time ./$srcfile
        let "i=i+1"
        echo -e "\n"
done
                                                                                                                                            
ml icc                                                                                                                                      
flagsForIccCpu=$(cat /proc/cpuinfo | grep flags | uniq | cut -d: -f2 | cut -d" " -f2- | tr _ .)
flagsForIccOptmztion=(O2 Ofast)
                                                                                                                                            
for optmzFlag in ${flagsForIccOptmztion[@]}; do
        for iccFlag in $flagsForIccCpu; do
                srcfile="iccResult$iccFlag$optmzFlag"
                icc -$optmzFlag -qopt-report-phase=vec myprog.cpp -o $srcfile -x$iccFlag 2> errors.txt
                if [ $? -eq 0 ]
                then
                        echo "icc compilation with -$optmzFlag flag and $iccFlag cpu extension:"
                        time ./$srcfile
                        echo -e "\n"
                fi
        done
done
