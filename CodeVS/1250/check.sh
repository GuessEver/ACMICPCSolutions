g++ 1250.cpp -o 1250
g++ std.cpp -o std
g++ mk.cpp -o mk
i=0
while true; do
	./mk
	./1250
	./std
	if ! diff 1250.out std.out
	then
		echo " Wrong Answer"
		break
	fi
	let i=$i+1
	echo $i" Accepted"
done

