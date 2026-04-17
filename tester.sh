#!/bin/bash
clang main.c matrix.c -o matrix_ops;
./matrix_ops < ./tests/test2.in
