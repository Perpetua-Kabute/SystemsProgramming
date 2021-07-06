#!/bin/sh
echo hello world!
echo "this will give me an error - ! I might have been misinformed "
#you cannot use a special character within quotes. escape using \
echo "this will now print correctly !"
printf "hello world\n"

#taking input from the user
read -p "Enter some text > " text
#printf does not print the line.  It prints word by word. Just use echo
echo "You entered: $text"

if read -t 3 -p "type something in 3 seconds >" response ; then 
	echo "You managed to type ($response) in 3 seconds"!
else
	echo "Sorry! You are too slow!"
fi


#Integer arithmetic
echo "Enter 4 numbers"
read -p "first number >" first_num
read -p "Second number >" second_num
read -p "third number >" third_num
read -p "fourth number >" fourth_num

echo "$first_num + $second_num + $third_num + $fourth_num = $((first_num + second_num + third_num + fourth_num))"
