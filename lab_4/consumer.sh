#!/bin/bash

TOPIC=lab-topic
BROKER=broker:9092

FROM_BEGINNING=$1

if [ "$FROM_BEGINNING" == "from-beginning" ]; then
    CONSUMER_OPTIONS="--from-beginning"
else
    CONSUMER_OPTIONS=""
fi

/opt/kafka/bin/kafka-console-consumer.sh --bootstrap-server $BROKER --topic $TOPIC $CONSUMER_OPTIONS

