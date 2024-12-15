#!/bin/bash

# Set the input and output paths
INPUT_PATH="rsvp_log.txt"
OUTPUT_PATH="/logs/output"

# Set the mapper and reducer scripts
MAPPER_SCRIPT="mapper.py"
REDUCER_SCRIPT="reducer.py"

# Run the Hadoop streaming job
hadoop jar /usr/lib/hadoop-mapreduce/hadoop-streaming.jar \
    -input $INPUT_PATH \
    -output $OUTPUT_PATH \
    -mapper $MAPPER_SCRIPT \
    -reducer $REDUCER_SCRIPT

