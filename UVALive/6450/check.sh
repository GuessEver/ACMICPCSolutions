g++ mk.cpp -o mk
g++ G.cpp -o G
g++ G3.cpp -o G3
i = 0
while true; do
	./mk
	./G < G.in > G.out
	./G3 < G.in > G3.out
	if ! diff G.out G3.out
	then
		echo " Wrong!!!"
		break
	fi
	echo $((i=i+1)) " Accepted"
done
