i=0
j=0
res=0
while [ $j -le 30 ]
do
	((j++))
	((i++))
	res=$(($j%11+1))
	../tetrigen/tetrigen -v -f $res
	mv 'test'.fillit "test_$i"
done
