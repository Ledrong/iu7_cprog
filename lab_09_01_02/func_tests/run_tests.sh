#!/bin/bash

clear
for i in {1..5}; do
    echo "TEST $i"
    ../../app.exe < pos_$i_in.txt > outfile_pos.txt
    ../../app.exe < neg_$i_in.txt > outfile_neg.txt

    if cmp -s "pos_$i_out.txt" "outfile_pos.txt"; then
        echo "Test $i OK"
    else
        echo "Test $i FAILED"
    fi

    if cmp -s "neg_$i_out.txt" "outfile_neg.txt"; then
        echo "Test $i OK"
    else
        echo "Test $i FAILED"
    fi
    echo
done


