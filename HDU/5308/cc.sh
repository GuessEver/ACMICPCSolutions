for((i=1;i<=26;i++)); do
	echo $i > "I.in"
	./I
	./check
done
