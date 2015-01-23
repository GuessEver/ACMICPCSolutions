g++ 1002.cpp -o 1002
g++ std.cpp -o std
g++ mk.cpp -o mk
i=0
while true; do
	./mk
	./1002
	./std
	if ! diff 1002.out std.out
	then
		echo "Wrong Answer"
		break
	fi
	let i=$i+1
	echo $i" Accepted"
done

