program rqnoj654;

var
  n:longint;
  x,y,xx,yy:array[0..10000+10] of longint;
  j,k,ans:longint;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure readdata;
var
  i,a,b:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(x[i],y[i],a,b);
    xx[i]:=x[i]+a;
    yy[i]:=y[i]+b;
  end;
  read(j,k);
end;

procedure main;
var
  i:longint;
begin
  ans:=-1;
  for i:=1 to n do
  begin
    if (j>=x[i])and(j<=xx[i])and(k>=y[i])and(k<=yy[i]) then
      ans:=i;
  end;
  writeln(ans);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

