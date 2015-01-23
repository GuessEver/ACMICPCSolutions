program rqnoj329;

var
  n,hp,time:longint;
  v,t,h,w:array[0..100+10] of longint;
  f:array[0..100+10,0..100+10] of longint;//（第几个，就地滚动），体力，时间，longint:鼓舞

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

procedure qsort(l,r:longint);
var
  i,j,x:longint;
begin
  i:=l;j:=r;x:=v[(i+j)div 2];
  repeat
    while v[i]>x do inc(i);
    while v[j]<x do dec(j);
    if i<=j then
    begin
      swap(v[i],v[j]);
      swap(t[i],t[j]);
      swap(h[i],h[j]);
      swap(w[i],w[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

procedure readdata;
var
  i,j:longint;
begin
  read(n,hp,time);//信件封数，体力，时间
  for i:=1 to n do
    read(v[i],t[i],h[i],w[i]);//价值，时间，体力，鼓舞

  qsort(1,n);//按价值降序排序
  {for i:=1 to n do
    writeln(v[i],' ',t[i],' ',h[i],' ',w[i]);}

  //初始化
  for i:=0 to hp do
    for j:=0 to time do f[i,j]:=0;
end;

procedure main;
var
  i,j,k,max:longint;
begin
  //f[1,0]:=0;
  
  for i:=1 to n do
    for j:=hp downto h[i]+1 do
      for k:=time downto t[i] do
      begin
        if {(f[j-h[i],k-t[i]]<>-1)and}(f[j-h[i],k-t[i]]+w[i]>f[j,k]) then
          f[j,k]:=f[j-h[i],k-t[i]]+w[i];
      end;
      
  max:=0;
  for i:=0 to hp do
    for j:=0 to time do
      if f[i,j]>max then max:=f[i,j];
      
  writeln(max);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

