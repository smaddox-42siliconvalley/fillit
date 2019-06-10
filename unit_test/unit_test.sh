i=1
for file in $@
do
	../a.out "$file"  > my_log
	~/testing/someones_fillit/fillit "$file" > actual_log
	DIFF=$(diff my_log actual_log)
	if [ "$DIFF" != "" ]
	then
		echo "my_output"
		cat my_log
		echo "correct_output"
		cat actual_log
	else
		echo "test$i passed"
		((i++))
	fi
done

