g++ std.cpp -o std
i=0
while true; do
	./std < EQUATION$i.IN > EQUATION$i.OUT
	let i=$i+1
	if [ $i -ge 10 ]; then break; fi
done
