#!/bin/bash

TOPIC=lab-topic
BROKER=broker:9092

/opt/kafka/bin/kafka-console-producer.sh --broker-list $BROKER --topic $TOPIC

