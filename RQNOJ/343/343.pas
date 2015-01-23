program rqnoj343;

var
  n,m:longint;
  f:array[0..5000+10] of longint;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure predoing;
var i:longint;
begin
  for i:=1 to n do
    f[i]:=i;
end;

function find(x:longint):longint;
begin
  if f[x]=x then exit(x);

  f[x]:=find(f[x]);
  exit(f[x]);
end;

procedure insert(x,y:longint);
var rx,ry:longint;
begin
  rx:=find(x);
  ry:=find(y);
  f[rx]:=ry;
end;

procedure readdata;
var
  i,x,y:longint;
begin
  read(n,m);
  predoing;
  for i:=1 to m do
  begin
    read(x,y);
    insert(x,y);
  end;
end;

procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure qsort(l,r:longint);
var
  i,j,x:longint;
begin
  i:=l;j:=r;x:=f[(i+j)div 2];
  repeat
    while f[i]<x do inc(i);
    while f[j]>x do dec(j);
    if i<=j then
    begin
      swap(f[i],f[j]);
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

procedure main;
var
  i,num,max:longint;
begin
  for i:=1 to n do
    f[i]:=find(i);
  qsort(1,n);
  num:=0;max:=0;
  for i:=2 to n do
  begin
    if f[i]=f[i-1] then inc(num);
    if (f[i]<>f[i-1])or(i=n) then
    begin
      if num>max then max:=num;
      num:=1;
    end;
  end;
  writeln(max);
end;

begin
  init;
  readdata;
  main;
  outit;
end.
