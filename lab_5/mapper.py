#!/usr/bin/env python
import sys

# Read each line from stdin (i.e., from the log file)
for line in sys.stdin:
    line = line.strip()
    
    # Check for the different log levels (INFO, TRACE, WARNING)
    if "INFO" in line:
        print("INFO\t1")
    elif "TRACE" in line:
        print("TRACE\t1")
    elif "WARNING" in line:
        print("WARNING\t1")
    # You can add more log levels as necessary (e.g., ERROR)

