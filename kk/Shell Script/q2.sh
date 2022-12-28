#find sum and average of 4 integers
clear
echo "Enter 4 integers : "
read n1
read n2
read n3
read n4
sum=`expr $n1 + $n2 + $n3 + $n4`
echo "sum\t: $sum\naverage\t: `expr $sum / 4`"
