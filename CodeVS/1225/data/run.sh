g++ mk.cpp -o mk
g++ std.cpp -o std
i=0
while ((i < 10))
do
	echo puzzle${i}.in puzzle${i}.out
	./mk > puzzle${i}.in
	./std < puzzle${i}.in > puzzle${i}.out
	let i=${i}+1
done
