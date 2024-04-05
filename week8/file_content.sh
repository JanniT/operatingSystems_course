#!/bin/bash

# check if an input file is given
if [ -z "$1" ]; then
    echo "Usage: $0 input_file"
    exit 1
fi

# Print the 10 most frequent words
cat "$1" | tr -s '[:space:]' '\n' | tr -d '[:punct:]' | tr '[:upper:]' '[:lower:]' | sort | uniq -c | sort -nr | head -n 10
