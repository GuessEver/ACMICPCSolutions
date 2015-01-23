program tyvj1048;

type
  arr=array[0..1000+10] of longint;

var
  n:longint;
  ti,qi:arr;
  f,co:array[0..1000+10,0..1000+10] of longint;//f[区间起始位置，区间长度]

procedure init;
begin
  assign(input,'tyvj1048.in');
  assign(output,'tyvj1048.out');
  reset(input);
  rewrite(output);
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

procedure qs(var a:arr;l,r:longint);
var
  i,j,x:longint;
begin
  i:=l;j:=r;x:=a[(i+j)div 2];
  repeat
    while a[i]>x do inc(i);
    while a[j]<x do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]);
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qs(a,i,r);
  if l<j then qs(a,l,j);
end;

procedure predoing;
var
  i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to n do
    begin
      if ti[i]>qi[j] then co[i,j]:=200
      else if ti[i]<qi[j] then co[i,j]:=-200
      else co[i,j]:=0;
    end;
  for i:=1 to n do f[i,1]:=co[i,n-1+1];
end;

procedure main;
var
  i,j:longint;
begin
  qs(ti,1,n);
  qs(qi,1,n);
  predoing;
  
  for j:=2 to n do//枚举区间长度
    for i:=1 to n-j+1 do//枚举起始位置
    begin
      //f[i,j]:=max(co[i,n-j+1]+f[i+1,j-1],co[i+j-1,n-j+1]+f[i,j-1]);
      f[i,j]:=co[i,n-j+1]+f[i+1,j-1];
      if f[i,j]<co[i+j-1,n-j+1]+f[i,j-1] then
        f[i,j]:=co[i+j-1,n-j+1]+f[i,j-1];
    end;
  writeln(f[1,n]);
end;

procedure readdata;
var
  i:longint;
begin
  read(n);
  while n<>0 do
  begin
    for i:=1 to n do read(ti[i]);
    for i:=1 to n do read(qi[i]);
    main;
    read(n);
  end;
end;

begin
  init;
  readdata;
  //main;
  outit;
end.
