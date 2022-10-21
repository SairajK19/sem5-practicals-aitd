echo "Enter the number";
read num;

echo -e "\nMultiplication table is";

i=1
while [ $i -le 10 ]
do
    echo "$((num*i))";
    i=$((i+1));
done
