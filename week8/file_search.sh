#!/bin/bash

# checking the given arguments
if [ "$#" -lt 1 ]; then
    echo "usage: $0 command"
    exit 1
fi

# search the given manual page
result=$(man -w "$1" 2>/dev/null)

# printing the result or a echo if not found
[ -z "$result" ] && echo "Manual-page not found '$1'." || echo "$result"

