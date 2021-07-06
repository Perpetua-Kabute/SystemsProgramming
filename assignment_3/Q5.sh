#!/bin/sh

read -p "Enter the images' file path" path

#comvert all images and count the number of images outputed
for i in `ls $path` ; do convert $i $i.jpg | count=wc -l ; done
echo count
