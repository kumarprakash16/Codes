clear
echo "enter number of terms"
n1=1
n2=1
read n
echo "$n1\n$n2"
#read n
while [ $n -gt 2 ]
do
	temp=$n1
	n1=$n2
	n2=`expr $temp + $n1`
	echo "$n2"
	n=`expr $n - 1`
done
