#!/bin/bash

# Define the names of the executables
executable1="./testgen.exe"
executable2="./program.exe"
executable3="./my.exe"

# Define the initial and subsequent output files
input_file="input.txt"
output_file1="correct.txt"
output_file2="my.txt"

# Initialize the loop condition
outputs_equal=true

# Main loop
while $outputs_equal; do
    # Print starting test message
    echo "Starting test"

    # Generate a new input for each iteration
    $executable1 > $input_file

    # Execute the second executable, taking the input file and producing output1
    $executable2 < $input_file > $output_file1

    # Execute the third executable, taking output1 and producing output2
    $executable3 < $input_file > $output_file2

    # Check if the outputs are the same
    if cmp -s "$output_file1" "$output_file2"; then
        # Print test success message
        echo "Test success"
    else
        # Print test failed message and break the loop
        echo "Test failed"
        outputs_equal=false
    fi
done
