#!/bin/bash

# Check if an input file is provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

# Processing the file
cat "$1" \
    | tr -s '[:space:]' '\n' \
    | tr -cd '[:alnum:]\n' \
    | tr '[:upper:]' '[:lower:]' \
    | sort \
    | uniq -c \
    | sort -nr \
    | head -n 10
