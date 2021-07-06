#!/bin/sh

networks_up()
{
  ping -c 1 $1 > /dev/null
  [ $? -eq 0 ] && echo Node with the IP: $i is up.
}

for i in 10.1.1.{1..255} 
do
networks_up $i & disown
done
