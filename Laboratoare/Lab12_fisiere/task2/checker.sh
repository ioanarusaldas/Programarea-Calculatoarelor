#!/bin/bash

TOTAL=0
INPUT_DIR="input"  # if modify, then modify prepare_test
OUTPUT_DIR="output"
PROGRAM="./$1"
TMP_OUTPUT="test"
TIMEOUT_T=5
LOG="/dev/null"

function print_header {
    echo "======== Laborator 12 ========"
}


function print_total {
    echo "TOTAL: $TOTAL"
}

function print_pass {
    TEST_NR="$1"

    echo "Test$1..................PASSED"
    TOTAL=$((TOTAL + 20))
}


function print_failed {
    TEST_NR="$1"

    echo "Test$1..................FAILED"
}

function prepare_test {
	TEST_NR="$1"
	for i in $INPUT_DIR/test${TEST_NR}*.in; do
		file_name=${i:12}
		cp ${i} ${file_name}
	done
}

function clean_test {
	TEST_NR="$1"
	for i in $INPUT_DIR/test${TEST_NR}*.in; do
		file_name=${i:12}
		rm ${file_name}
	done
}

function verify_test {
    TEST_NR="$1"
    TEST_INPUT_PATH="$INPUT_DIR/test$1.in"
    TEST_OUTPUT_PATH="$OUTPUT_DIR/test$1.ref"

	prepare_test "$TEST_NR"

    timeout $TIMEOUT_T $PROGRAM
    diff "$TEST_OUTPUT_PATH" data.out &> "$LOG"

    if [ $? -eq 0 ]; then
        print_pass "$TEST_NR"
    else
        print_failed "$TEST_NR"
    fi

	clean_test "$TEST_NR"
}

if [ $# -ne 1 ]; then
    echo "Usage: bash checker.sh <name_executable>"
    exit 1
fi

print_header

for nr in $(seq 0 4); do
    verify_test "$nr"
done

print_total
