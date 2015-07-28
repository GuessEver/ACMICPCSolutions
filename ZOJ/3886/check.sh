mkdata=mk
filea=F
fileb=p

g++ $mkdata.cpp -o $mkdata
g++ $filea.cpp -o $filea
g++ $fileb.cpp -o $fileb
cas=0
while true; do
	./$mkdata > $filea.in
	time ./$filea < $filea.in > $filea.out
	time ./$fileb < $filea.in > $fileb.out
	if ! diff $filea.out $fileb.out
	then
		echo " Wrong Answer"
		break
	fi
	echo $((cas=cas+1)) " Accepted"
done
