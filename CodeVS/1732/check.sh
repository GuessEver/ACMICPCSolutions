g++ 1732.cpp -o 1732
g++ std.cpp -o std
g++ mk.cpp -o mk
i=0
while true; do
	echo "          making data..."
	./mk
	echo "          run 1732..."
	./1732
	echo "          run std..."
	./std
	echo "          compare..."
	if ! diff 1732.out std.out
	then
		echo " Wrong Answer"
		break
	fi
	let i=$i+1
	echo $i" Accepted"
done

