#!/bin/bash
#TODO -i flag for interactive mode
#only compile w/ -i and in main
lineStart="csh>>>"
cFile="tempcsh.c"
execFile="tempcsh"
currLine=3

echo "#include<stdio.h>
int main(){
return 0;}" > $cFile

while :
do
	read -r -p $lineStart command

	if [[ $command == "exit" ]]; then #exit interactive mode
		break
	elif [[ $command == "" ]]; then #handle nothing entered
		continue
	elif [[ $command == "undo" ]]; then #undo
		((currLine--))
		sed -i "${currLine}d" $cFile
	elif [[ $command == "run" ]]; then #compile and execute c-file
		gcc $cFile -o $execFile
		./$execFile
	elif [[ $command == "func" ]]; then #start function and move cursor to top
		currLine=2
	elif [[ $command == "endfunc" ]]; then #end function and move cursor to main
		currLine=$(wc -l < $cFile)
	elif [[ $command == "print" ]]; then #print current c-file and current line
		echo "Current Line: $currLine"
		cat $cFile
	elif [[ $command == "#include"* ]]; then #add an include stmt at the top
		sed -i "2i\\$command\\" $cFile
	else #append to c-file at currLine
		sed -i "${currLine}i\\$command\\" $cFile
		((currLine++))
	fi
done
#cleanup
rm ./$cFile ./$execFile 2> /dev/null
