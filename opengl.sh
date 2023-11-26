#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.c>"
    exit 1
fi

filename="${1%.c}"  # Remove .c extension
executable="${filename}_executable"

# Compile the OpenGL code
gcc -o "$executable" "$filename.c" -lGL -lGLU -lglut

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./"$executable"
else
    echo "Compilation failed. Please check your code."
fi

