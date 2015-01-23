program rqnoj350;

var
  n,m:longint;
  a,b:array[0..200000+10] of longint;

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
begin
end;

procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure qsort(l,r:longint);
var
  i,j:longint;
  x:longint;
begin
  i:=l;j:=r;x:=a[(i+j)div 2];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]);
      swap(b[i],b[j]);
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

procedure main;
var
  i,j,x,y,k,num:longint;
begin
  read(n,m);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  qsort(1,n);
  for i:=1 to m do
  begin
    read(x,y,k);
    num:=0;
    for j:=1 to n do
    begin
      if (b[j]<x)or(b[j]>y) then continue;
      inc(num);
      if num=k then
      begin
        writeln(a[j]);
        break;
      end;
    end;
  end;
end;


begin
  init;
  readdata;
  main;
  outit;
end.

