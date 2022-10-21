echo "Enter the number";
read count;
echo "";
num1=0;
num2=1

for ((i=0; i<count; i++))
do
    echo -n "$num1 ";
    fn=$((num1+num2));
    num1=$num2;
    num2=$fn;
done
