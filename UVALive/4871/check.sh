g++ mk.cpp -o mk
g++ p.cpp -o p
g++ I.cpp -o I
i=0
while true; do
	./mk > I.in
	./I < I.in > I.out
	./p < I.in > p.out
	if ! diff I.out p.out
	then
		echo "WA"
		break
	fi
	echo $((i=i+1))" AC"
done
