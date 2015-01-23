g++ -g 11636.cpp -o 11636
g++ -g std.cpp -o std
g++ -g mk.cpp -o mk
i=0
while true; do
	./mk
	./11636
	./std
	if ! diff 11636.out std.out 
	then
		echo "Wrong Answer"
		break
	fi
	echo $((i=i+1)) Accepted
done
