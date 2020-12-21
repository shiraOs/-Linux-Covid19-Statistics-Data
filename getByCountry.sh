#!/bin/bash

wget https://api.covid19api.com/countries -O countriesJson.txt
chmod 755 countriesJson.txt
mkdir countries
cat countriesJson.txt | sed "s/{/\n/g" | sed "/united-states/d" |sed "s/ /%20/g" | awk -F \" '{print $8}' > countriesList.txt
cat countriesList.txt | while read line
do
	echo Written ${line}
	sleep 0.1s
	curl=https://api.covid19api.com/country/${line}
	wget ${curl} -O ${line}.cnt 2> tmp.log
	cat ${line}.cnt | sed "s/{/\n/g" | sed "1d" |awk -F \" '{print $30,$31; print $32,$33;print $34,$35;print $36,$37;print $38,$40}' | sed "s/ :/:/g"| sed "s/,//g" |sed "s/ /:/g" > ./countries/${line}.country
done
rm *.cnt *.log  countriesJson.txt
echo finish
