g++ mk.cpp -o mk
g++ 1322.cpp -o 1322
g++ 1322ps.cpp -o 1322ps
i=0
while true; do
	echo "               making data..."
	./mk
	echo "               run 1322..."
	./1322
	echo "               run 1322ps..."
	./1322ps
	echo "               diffing..."
	if ! diff 1322.out 1322ps.out
	then
		echo "Wrong Answer"
		break
	fi
	let i=$i+1
	echo "$i Accpeted"
done
