#!/bin/bash

contest=$1
nome=$2
qtde=$3

g++ $nome'.cpp' -o $nome -O2 -lm -Wall

if [[ $? -ne 0 ]];
then
	echo "COMPILOU NAO BROTHER";
	exit 1
fi

for ((i=1; i<=$qtde; ++i));
do
	input=$contest"/data/"$nome'/'$nome'.in.'$i
	output=$contest"/data/"$nome'/'$nome'.out.'$i
	myout=$nome'.myout.'$i
	time ./$nome < $input > $myout
	
	if [[ $? -ne 0 ]]
	then
		echo "RUNTIME ERROR"
		exit 1
	fi
	
	diff $myout $output > dif
	if [[ $? -ne 0 ]]
	then
		diff -b $myout $output > dif
		if [[ $? -ne 0 ]]
		then
			echo "Teste "$i" FAILED!"
			cat dif
			rm dif
			exit 1
		else
			echo "Teste "$i" OK -- (Presentation Error)"
		fi
	else
		echo "Teste "$i" OK!"
	fi
done

rm $nome
rm dif
rm *.myout.*

echo "ALL TESTS OK!!"
