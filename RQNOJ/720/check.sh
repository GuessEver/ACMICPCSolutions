g++ -g mk.cpp -o mk
g++ -g A.cpp -o A
g++ -g Ap.cpp -o Ap
i=0
while true; do
	./mk
	./A
	./Ap
	if ! diff A.out Ap.out
	then
		echo " Wrong Answer"
		break
	fi
	echo $((i=i+1)) " Accepted"
done
