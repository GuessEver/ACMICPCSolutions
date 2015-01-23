program fruit;

const maxn=10000+10;

var
  n,total:longint;
  a:array[0..maxn] of longint;
  size:longint;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure insert(x:longint);
var
  i,j:longint;
begin
  inc(size);
  a[size]:=x;
  
  i:=size;//本身
  j:=i div 2;//父节点
  while (j>=1)and(a[i]<a[j]) do
  begin
    swap(a[i],a[j]);
    i:=j;
    j:=i div 2;
  end;
end;

procedure delete;
var
  i,j:longint;
begin
  a[1]:=a[size];
  dec(size);
  
  i:=1;//本身
  j:=i*2;//儿子节点
  if (j<n)and(a[j+1]<a[j]) then inc(j);
  while (j<=size)and(a[i]>a[j]) do
  begin
    swap(a[i],a[j]);
    i:=j;
    j:=i*2;
    if (j<n)and(a[j+1]<a[j]) then inc(j);
  end;
end;

procedure readdata;
var
  i,x:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(x);
    insert(x);
  end;
end;

procedure main;
var
  i,x,y:longint;
begin
  for i:=1 to n-1 do
  begin
    x:=a[1];
    delete;
    y:=a[1];
    delete;
    total:=total+x+y;
    insert(x+y);
  end;
  writeln(total);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

