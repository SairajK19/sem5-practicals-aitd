echo -n "Enter the String to check for palindrome: "
read str

tmp=$str
len=`echo -n $str | wc -c`

while [ $len -gt 0 ]
do
	rev+=`echo -n $str | cut -c $len`
	len=`expr $len - 1`
done

if [ $rev = $str ]
then
	echo "String is palindrome"
else
	echo "String is not palindrome"
fi
