#!/bin/sh

#count all characters including whitespaces
file="Gachororo.txt"

#cat $file reads the content of the file and redirects output to tr command.
#tr -d deletes specified. In this case "[:space:] (white spaces).
#wc -c counts the number of characters after the white spaces are removed. 

characters=`cat $file | tr -d '[:space:] ' | wc -c`
echo "The number of characters excluding white spaces are $characters"


