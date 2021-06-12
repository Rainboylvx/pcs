for i in {1..1000};
do
    echo $i
    ./data > in
    ./t1 < in > out1
    ./t2 < in > out2
    diff out1 out2 || exit  失败就退出
done

