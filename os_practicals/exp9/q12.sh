echo -e "1] Goa\n2] Maharashtra\n3]Karnataka\n4]Kerala";
echo -n "State: ";
read state;

case $state in
    1)
        echo "Capital of Goa is Panjim";;
    2)
        echo "Capital of Maharashtra is Mumbai";;
    3)
        echo "Capital of Karnataka is Bangalore";;
    4)
        echo "Capital of kerala is Thiruvananthapuram";;
esac
