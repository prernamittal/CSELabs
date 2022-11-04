echo quad eqn
read a; read b; read c
d=`expr $b \* $b - 4 \* $a \* $c`
if [ $d -gt 0 ]
then
flag=1
elif [ $d -lt 0 ]
then
flag=2
else
flag=3
fi
case $flag in
1) echo real roots
r1=`expr $b \* -1 + $d / 2 \* $a`
r2=`expr $b \* -1 - $d / 2 \* $a`
echo $r1
echo $r2
;;
2) echo complex roots
r1=`expr $b \* -1 + $d / 2 \* $a`
r2=`expr $b \* -1 - $d / 2 \* $a`
echo $r1
echo $r2
;;
3) echo equal roots
r1=`expr $b \* -1 + $d / 2 \* $a`
r2=`expr $b \* -1 - $d / 2 \* $a`
echo $r1
echo $r2
;;
esac
