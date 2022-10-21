i=5;
j=5;
while [ $i -gt 0 ]
do
    while [ $j -gt 0 ]
    do
        echo -n "* ";
        j=$((j-1));
    done
    echo "";
    i=$((i-1));
    j=$i;
done
echo "";

i=1;
j=1;
while [ $i -le 4 ]
do
    while [ $j -le 4 ]
    do
        echo -n "$j ";
        j=$((j+1));
    done
    echo "";
    i=$((i+1));
    j=$i;
done
echo "";

i=1;
j=1;
while [ $i -le 4 ]
do
    while [ $j -le $i ]
    do
        echo -n "$i ";
        j=$((j+1));
    done
    echo "";
    i=$((i+1));
    j=1;
done
