g++ mk.cpp -o mk
g++ E.cpp -o E
g++ p.cpp -o p
i=10
while true; do
	((i=i+1))
	echo "1 $((i))" > E.in
	./E < E.in > E.out
	./p < E.in > p.out
	if ! diff E.out p.out
	then
		echo "WA"
		break
	fi
	echo $((i=i+1)) "AC"
done
