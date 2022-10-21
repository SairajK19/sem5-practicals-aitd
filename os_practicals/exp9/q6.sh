# 6
echo "Enter three numbers";
read num1;
read num2;
read num3;

if [ $num1 -gt $num2 ]
then
	if [ $num1 -ge $num3 ]
	then
		echo "$((num1)) is the greatest!";
	fi
elif [ $num2 -gt $num3 ]
then
	if [ $num2 -ge $num1 ]
	then
		echo "$((num2)) is the greatest!";
	fi
elif [ $num3 -gt $num2 ]
then
	echo "$((num3)) is the greatest!";
fi
