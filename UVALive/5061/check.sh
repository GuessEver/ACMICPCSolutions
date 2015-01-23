g++ E.cpp -o E
g++ E2.cpp -o E2
g++ mk.cpp -o mk
i=0
while true; do
	./mk > E.in
	./E < E.in > E.out
	./E2 < E.in > E2.out
	if ! diff E.out E2.out
	then
		echo "WA"
		break
	fi
	echo $((i=i+1)) " AC"
done
