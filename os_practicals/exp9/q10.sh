is_prime="true"
i=2
j=2

while [ $i -le 20 ]
do
    if [ $i -le 1 ]
    then
        is_prime="false"
    else
       while [ $j -lt $i ]
       do
           if [ $(($j % $i)) -eq 0 ]
            then
                is_prime="false"
            fi
            j=$(($j+1))
#            echo $j
       done
    fi
    
    if [ $is_prime=="true" ]
    then
        echo -n "$i "
    fi

    i=$(($i+1))
done
echo ""
