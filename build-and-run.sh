#!/bin/bash

# Build all .c files in src/ into an executable named 8_queens.out
gcc -O2 src/*.c -o 8_queens.out

# Check if build succeeded
if [ $? -eq 0 ]; then
    echo "Build successful. Running program..."
    if [ -z "$1" ]; then
        echo "No arguments provided. BRUTE_FORCE will be used as default."
        ./8_queens.out
    else
        ./8_queens.out "$1"
    fi
else
    echo "Build failed."
fi
