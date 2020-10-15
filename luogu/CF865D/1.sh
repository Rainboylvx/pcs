while true
do
    python data_generator.py > input
    ./1 < input > 1.out
    python 2.py < input > 2.out
    diff 1.out 2.out
    if [ $? == 1 ];then
        echo "no"
        break
    else
        echo "yes"
    fi
done
