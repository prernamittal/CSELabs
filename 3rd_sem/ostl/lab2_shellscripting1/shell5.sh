echo enter values of 1st files
cat>nf1.txt
echo enter values of 2nd file
cat>nf2.txt
cat nf1.txt nf2.txt>nf3.txt
sort -nu nf3.txt
