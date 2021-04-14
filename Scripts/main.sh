x=10
y=` expr $x + 1 `
echo $x $y
z=` expr $x + $y \* 10`
echo $z

# < -lt  > -gt == -eq >= -ge <= -le

echo "Enter a Number"
read num1
if [ $num1 -gt 0 ]
then
echo 'positive'
elif [ $num1 -lt 0 ]
then
echo 'negative'
else
echo 'zero'
fi

#loops while untill
x=0
while [ $x -lt 10 ]
do
    echo $x
    x=$((x+1))
done

echo 'UNTILL'

y=0
until [ $y -gt 5 ]
do
    echo $y
    y=`expr $y + 1`
done

for files in /*
do
    echo $files
done