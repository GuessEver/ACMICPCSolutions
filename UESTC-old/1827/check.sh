g++ mk.cpp -o mk
g++ nnn.cpp -o nnn
g++ 1827.cpp -o 1827
i=0
while true; do
	./mk
	./nnn
	./1827
	if ! diff 1827.out nnn.out
	then
		echo "Wrong Answer"
		break
	fi
	let i=$i+1
	echo "$i Accpeted"
done
