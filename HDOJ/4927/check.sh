g++ mk.cpp -o mk
g++ G.cpp -o G
#g++ G2.cpp -o G2
i=0
while true; do
	./mk > G.in
	./G < G.in > G.out
#	./G2 < G.in > G2.out
	java Main < G.in > G2.out
	if ! diff G.out G2.out
	then
		echo " WA"
		break
	fi
	echo $((i=i+1)) " AC"
done
