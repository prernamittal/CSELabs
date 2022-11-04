echo enter n:
read n
for((i=1;i<=n;i++))
do
echo `expr $i \* 2 \- 1`
done