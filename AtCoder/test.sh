#!/bin/sh

echo "contest name : "
read name
echo "number of problems : "
read num

mkdir $name
for i in `seq 0 $num`
do
    problem = "A" + $i
    cp "../template.cpp" "$name/$problem.cpp"
done
