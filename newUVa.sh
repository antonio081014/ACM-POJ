#!/bin/sh

for i in "$@"
do
	STR=$STR\_$i
done

echo -n "//" >> UVa$STR\.java
touch UVa$STR\.java
#date >> UVa$STR\.cpp
#cat Temple >> UVa$STR\.cpp
#mv UVa$STR\.cpp Judge/
