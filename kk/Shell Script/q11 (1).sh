clear
echo "enter number and digit to count: "
read n
read d
c=0
while [ $n -gt 0 ]
do
	temp=`expr $n % 10`
	if [ $temp -eq $d ]
	then
		c=`expr $c + 1`
	fi
	n=`expr $n / 10`
done
echo "Frequency of $d in $n is: $c"
