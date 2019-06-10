../a.out $1 > my_log
~/testing/someones_fillit/fillit $1 > actual_log
DIFF=$(diff my_log actual_log)
if [ "$DIFF" != "" ]
then
	echo "my_output"
	cat my_log
	echo "correct_output"
	cat actual_log
else
	echo "good"
fi


