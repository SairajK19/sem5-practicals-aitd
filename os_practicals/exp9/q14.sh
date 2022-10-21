# Generate the series: 1,3,2,4,3,5,4,6,.....
i=1

while [ $i -le 8 ]
do
    sum=$(($i+2));
    echo -n "$i,$sum,"
    i=$(($i+1));
done
echo ""
