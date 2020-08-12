#!/bin/bash
lineStart="csh>>>"
cFile="tempcsh.c"
execFile="tempcsh"
currLine=3
isInteractive=0
inMain=1

#handle command line flags
for opt in $@; do
	case $opt in
		-i|--interactive)
			isInteractive=1
			;;
		*)
			;;
	esac
done

echo "#include<stdio.h>
int main(){
return 0;}" > $cFile

function undo(){
	((currLine--))
	sed -i "${currLine}d" $cFile
}

function run(){
	gcc $cFile -o $execFile
	compilationReturn=$?
	./$execFile
	if [[ ( $1 == "-u" ) && ( compilationReturn -ne 0 || $? -ne 0 ) ]]; then
		undo
	fi
}

while :
do
	read -r -p $lineStart command

	if [[ $command == "exit" ]]; then #exit interactive mode
		break
	elif [[ -z $command ]]; then #handle nothing entered
		continue
	elif [[ $command == "undo" ]]; then #undo
		undo
	elif [[ $command == "run" ]]; then #compile and execute c-file
		run
	elif [[ $command == "func" ]]; then #start function and move cursor to top
		currLine=2
		inMain=0
	elif [[ $command == "endfunc" ]]; then #end function and move cursor to main
		currLine=$(wc -l < $cFile)
		inMain=1
	elif [[ $command == "print" ]]; then #print current c-file and current line
		echo "Current Line: $currLine"
		cat $cFile
	elif [[ $command == "#include"* ]]; then #add an include stmt at the top
		sed -i "2i\\$command\\" $cFile
	else #append to c-file at currLine
		sed -i "${currLine}i\\$command\\" $cFile
		((currLine++))
		if [[ $inMain == 1 && $isInteractive == 1 ]]; then #only compile if in interactive mode
			run -u
		fi
	fi
done
#cleanup
rm ./$cFile ./$execFile 2> /dev/null
