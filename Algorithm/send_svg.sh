#!/bin/bash  
lastfile=""
if [ $1 ]
then
  lastfile=$1
else
	for file in `ls -t tsg*.dot`
	do
		if [ "$lastfile" = "" ]; then
		lastfile=$file
		break
	fi
	done
fi

echo "Generating the SVG file from dot" $lastfile
dot -Tsvg $lastfile -o ${lastfile:0:3}"_dag.svg"

echo "Start sending the SVG file..."
sz ${lastfile:0:3}"_dag.svg" 
echo "All have been done."
