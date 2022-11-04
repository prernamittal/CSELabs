echo enter a number
read n
if [ `expr n%2` ==0 ]
then
echo even
else
echo odd
fi

