echo "Give a number"
read num
mul=1
while [ $num -gt 1 ]
do
    echo $x
    mul=$((mul*num))
    num=$((num-1))
done

echo $mul