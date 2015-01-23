g++ mk.cpp -o mk
g++ s.cpp -o s
g++ J.cpp -o J
i=0
while true; do
	./mk > J.in
	./s < J.in > s.out
	./J < J.in > J.out
	if ! diff J.out s.out
	then
		echo " WA"
		break
	fi
	echo $((i=i+1)) " AC"
done
