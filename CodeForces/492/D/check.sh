g++ mk.cpp -o mk
g++ D.cpp -o D
g++ D3.cpp -o D3
i=0
while true; do
	./mk > D.in
	./D < D.in > D.out
	./D3 < D.in > D3.out
	if ! diff D.out D3.out
	then
		echo " WA"
		break
	fi
	echo $((i=i+1)) " AC"
done
