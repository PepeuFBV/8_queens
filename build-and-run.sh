#!/bin/bash

# Build all .c files in src/ into an executable named 8_queens.out
gcc src/*.c -o 8_queens.out

# Check if build succeeded
if [ $? -eq 0 ]; then
    echo "Build successful. Running program..."
    ./8_queens.out
else
    echo "Build failed."
fi
