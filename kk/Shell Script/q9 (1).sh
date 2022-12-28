clear
echo "enter number"
read n
fact=1
i=2
while [ $i -le $n ]
do
	fact=`expr $fact \* $i`
	i=`expr $i + 1`
done
echo "Factorial : $fact"
