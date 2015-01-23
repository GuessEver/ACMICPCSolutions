g++ mk.cpp -o mk
g++ p.cpp -o p
g++ F.cpp -o F
i=0
while true; do
	./mk > F.in
	./F < F.in > F.out
	./p < F.in > p.out
	if ! diff F.out p.out
	then
		echo "WA"
		break
	fi
	echo $((i=i+1))" AC"
done
