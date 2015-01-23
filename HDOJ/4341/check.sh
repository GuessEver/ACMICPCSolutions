g++ mk.cpp -o mk
g++ B.cpp -o B
g++ s.cpp -o s
i=0
while true; do
	./mk > B.in
	./B < B.in > B.out
	./s < B.in > s.out
	if ! diff B.out s.out
	then
		echo "WA"
		break
	fi
	echo $((i=i+1)) "AC"
done
