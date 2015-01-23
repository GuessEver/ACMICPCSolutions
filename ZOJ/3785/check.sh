g++ mk.cpp -o mk
g++ J.cpp -o J
g++ ppp.cpp -o ppp
i=0
while true; do
	./mk > J.in
	./J < J.in > J.out
	./ppp < J.in > ppp.out
	if ! diff J.out ppp.out
	then
		echo " Wrong Answer"
		break
	fi
	echo $((i=i+1)) " Accepted"
done
