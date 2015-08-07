g++ J.cpp -o J
g++ p.cpp -o p
for ((i=1;i<=10000;i++)); do
	echo $i > J.in
	./J < J.in > J.out
	./p < J.in > p.out
	if ! diff J.out p.out
	then
		echo "$i failed"
		break
	fi
	echo "$i ok"
done
