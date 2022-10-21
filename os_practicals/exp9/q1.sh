hour=$(date +"%H")

if [ $hour -ge 0 -a $hour -lt 12 ]
then
      echo "Good morning"
  elif [ $hour -ge 12 -a $hour -lt 17 ] 
  then
        echo "Good afternoon"
  else
        echo "Good evening"
fi
