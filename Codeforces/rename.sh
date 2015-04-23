#!/bin/bash
FOLDERS=./BetaRound*
for folder in $FOLDERS; do
	nfolder="#${folder##*\#}"
	mv "$folder" $nfolder
done
