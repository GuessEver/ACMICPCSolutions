program son;

uses math;

var
  n,a0,a1,b0,b1:longint;

procedure init;
begin
end;

procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
function lcm(a,b:longint):longint;
var sum:longint;
begin
  sum:=a div gcd(a,b)*b;
  exit(sum);
end;

procedure work;
var i,ans,x:longint;
begin
  read(a0,a1,b0,b1);
  ans:=0;
  for i:=1 to trunc(sqrt(b1)) do
  begin
    if(b1 mod i <>0)then continue;
    if (gcd(i,a0)=a1)and(lcm(i,b0)=b1)then inc(ans);
    x:=b1 div i;
    if(x=i) then continue;
    if (gcd(x,a0)=a1)and(lcm(x,b0)=b1)then inc(ans);
  end;
  writeln(ans);
end;

procedure readdata;
var i:longint;
begin
  read(n);
  for i:=1 to n do
    work;
end;

begin
  init;
  readdata;
  outit;
end.


