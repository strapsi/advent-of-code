#!/bin/bash

INSPECT=0
while read line; do
	START_FIRST=$(echo $line | cut -d ',' -f 1 | cut -d '-' -f 1)
	END_FIRST=$(echo $line | cut -d ',' -f 1 | cut -d '-' -f 2)
	START_SECOND=$(echo $line | cut -d ',' -f 2 | cut -d '-' -f 1)
	END_SECOND=$(echo $line | cut -d ',' -f 2 | cut -d '-' -f 2)
	if (( "$START_FIRST" >= "$START_SECOND" )) && (( "$END_FIRST" <= "$END_SECOND" )); then		
		let INSPECT++
	elif (( "$START_SECOND" >= "$START_FIRST" )) && (( "$END_SECOND" <= "$END_FIRST" )); then		
		let INSPECT++
	fi
done < ./inputs/day4

echo $INSPECT
