#!/usr/bin/env python
import sys

current_log_type = None
current_count = 0

# Read each line from stdin (i.e., from the output of the mapper)
for line in sys.stdin:
    line = line.strip()
    
    log_type, count = line.split("\t")
    count = int(count)
    
    # If we have a new log type, output the previous one and reset counters
    if current_log_type == log_type:
        current_count += count
    else:
        if current_log_type:
            print(f"{current_log_type}\t{current_count}")
        current_log_type = log_type
        current_count = count

# Output the last log type
if current_log_type:
    print(f"{current_log_type}\t{current_count}")

