#swap
clear
echo "enter two values"
read a
read b
echo "First value\t: $a\nSecond value\t: $b"
c=$a
a=$b
b=$c
echo "\n...After swapping...\nFirst value\t: $a\nSecond value\t: $b"
