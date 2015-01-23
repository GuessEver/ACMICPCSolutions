g++ mk.cpp -o mk
g++ 1831.cpp -o 1831
g++ pp.cpp -o pp
i=0
while true; do
	./mk
	./1831
	./pp
	if ! diff 1831.out pp.out 
	then
		echo "Wrong Answer"
		break
	fi
	let i=$i+1
	echo "$i Accpeted"
done
