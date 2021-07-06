#!/bin/sh

echo enter userName
read username
user_id=`id -u $username`

if [ -z "$user_id" ]
	then echo "Enter correct user name"
	exit
else echo "User ID: $user_id"
fi

count=`who | grep $user_id -c`
echo "User: $username UID: $user_id No of times logged in: $count"
  
