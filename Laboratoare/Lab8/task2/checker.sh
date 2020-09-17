#!/bin/bash

TOTAL=0
INPUT_DIR="input"
OUTPUT_DIR="output"
PROGRAM="./$1"
TMP_OUTPUT="test"
TIMEOUT_T=5
LOG="/dev/null"

NUM_TESTS="$(ls -1 $INPUT_DIR/ | wc -l)"
INC="$((100 / $NUM_TESTS))"

function print_header {
    echo "======== Laborator 2 ========"
}


function print_total {
    echo "TOTAL: $TOTAL"
}

function print_pass {
    TEST_NR="$1"

    echo "Test$1..................PASSED"
    TOTAL=$((TOTAL + $INC))
}


function print_failed {
    TEST_NR="$1"

    echo "Test$1..................FAILED"
}



function verify_test {
    TEST_NR="$1"
    TEST_INPUT_PATH="$INPUT_DIR/test$1.in"
    TEST_OUTPUT_PATH="$OUTPUT_DIR/test$1.ref"

    timeout $TIMEOUT_T $PROGRAM < "$TEST_INPUT_PATH" > "$TMP_OUTPUT"
    diff "$TEST_OUTPUT_PATH" "$TMP_OUTPUT" &> "$LOG"

    if [ $? -eq 0 ]; then
        print_pass "$TEST_NR"
    else
        print_failed "$TEST_NR"
    fi

    rm "$TMP_OUTPUT"
}

if [ $# -ne 1 ]; then
    echo "Usage: bash checker.sh <name_executable>"
    exit 1
fi

print_header

for nr in $(seq 0 $((NUM_TESTS - 1))); do
    verify_test "$nr"
done

print_total
