#!/bin/sh

message="Inviting the you as our computing student to our 21st Open
Webinar on innovation incubation scheduled for Friday, 25th
June 2021 from 10:00 A.M. The Zoom link for joining in on
Friday is as given below. We shall also broadcast the webinar
on our youtube channel. Youtube link:
https://youtu.be/ONVTA7LKMIs"

while read file 
	do
	email_address=`grep -o '\b[^\.]*\.abc\b'`
	mail -s "Invitation to Webinar" $email_address <<< $message
done < "persons_emails.txt"

