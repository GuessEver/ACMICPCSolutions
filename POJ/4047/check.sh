g++ D.cpp -o D
g++ st.cpp -o st
g++ mk.cpp -o mk
i=0
while true; do
	./mk > D.in
	./D < D.in > D.out
	./st < D.in > s.out
	if ! diff D.out s.out
	then
		echo " WA"
		break
	fi
	echo $((i=i+1)) " AC"
done
