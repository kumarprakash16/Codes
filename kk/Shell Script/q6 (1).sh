clear
echo "Enter 3 numbers: "
read a
read b
read c
if [ $a -gt $b -a $a -gt $c ]
then
	echo "greatest is $a"
elif [ $b -gt $a -a $b -gt $c ]
then
	echo "greatest if $b"
else
	echo "greatest is $c"
fi
