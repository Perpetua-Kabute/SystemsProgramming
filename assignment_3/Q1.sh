#!/bin/sh
#Integer arithmetic
echo "Enter 4 numbers"
read -p "first number >" first_num
read -p "Second number >" second_num
read -p "third number >" third_num
read -p "fourth number >" fourth_num

echo "$first_num + $second_num + $third_num + $fourth_num = $((first_num + second_num + third_num + fourth_num))"
