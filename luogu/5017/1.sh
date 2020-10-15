var=1
while true
do
    python data_generator.py > input
    ./1 < input > 1.out 2>/dev/null
    ./50per < input > 2.out 2>/dev/null
    diff 1.out 2.out
    if [ $? == 1 ];then
        echo "no"
        break
    else
        echo "$var"
    fi
    var=$(($var+1))
done
