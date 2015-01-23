program rqnoj1;

var
  n:longint;
  a:array[0..200] of longint;

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
  i:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
end;

procedure exchange(var a,b:longint);
var
  t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure qsort(l,r:longint);
var
  i,j,x:longint;
begin
  i:=l;j:=r;x:=a[(i+j)shr 1];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      exchange(a[i],a[j]);
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;

procedure main;
var
  i,t:longint;
begin
  qsort(1,n);
  t:=n;
  for i:=2 to t do
  begin
    if a[i]=a[i-1] then
      dec(t);
  end;
  writeln(t);
  for i:=1 to n-1 do
  begin
    if a[i]<>a[i+1] then
      write(a[i],' ');
  end;
  if a[n]<>a[n-1] then
    writeln(a[n]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

