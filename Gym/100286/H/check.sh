mkdata=mk
filea=H
fileb=p

g++ $mkdata.cpp -o $mkdata
g++ $filea.cpp -o $filea
g++ $fileb.cpp -o $fileb
g++ cc.cpp -o cc
cas=0
while true; do
	./$mkdata > hell.in
	./$filea
	./$fileb < hell.in > p.out
	./cc
	log=$?
	if [ $log -eq 1 ]; then
		break;
	fi
	echo $((cas=cas+1)) " Accepted"
done
