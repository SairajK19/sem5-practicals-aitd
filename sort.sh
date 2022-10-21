nums=[1,2,3,4]
temp=0
n=4

for ((i=0; i < $n; i++))
do
  for ((j=$i; j<$n; j++))
  do
    if [${num[$i]} -lt ${num[$j]}]
    then
      temp=${num[$i]}
      num[$i]=${num[$j]}
      num[$j]=$temp
    fi
  done
done
