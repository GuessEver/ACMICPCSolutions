program hornet;

const maxn=100+100;

var
  n,v:longint;
  x,y,f:array[0..maxn] of longint;
  map:array[0..maxn,0..maxn] of extended;//记录时间
  dist:array[0..maxn] of extended;
  h:array[0..maxn] of boolean;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

function dis(i,j:longint):extended;
begin
  exit(sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])));
end;

procedure readdata;
var
  i,j:longint;
begin
  read(n,v);
  for i:=1 to n do//处理相连情况
  begin
    read(x[i],y[i],f[i]);
    if f[i]=0 then continue;
    map[i,f[i]]:=dis(i,f[i])/v;
    map[f[i],i]:=dis(i,f[i])/v;
  end;
  for i:=1 to n do//处理自由落体
    for j:=1 to n do
    begin
      if i=j then continue;
      if (x[i]=x[j])and(y[i]>y[j]) then//自由落体 i --> j
      begin
        map[i,j]:=sqrt((2*(y[i]-y[j]))/10);
      end;
    end;
 { for i:=1 to n do
   begin
     for j:=1 to n do
       writeln(map[i,j]:10:3);
     writeln;
   end;}
end;

procedure dijkstra;
var
  i,k,j:longint;
  total,min:extended;
begin
  total:=0;
  for i:=1 to n do
  begin

    k:=0;min:=maxlongint;
    for j:=1 to n do
    begin
      if (not h[j])and(min>dist[j]) then
      begin
        k:=j;min:=dist[j];
      end;
    end;

    h[k]:=true;

    for j:=1 to n do
    begin
      if (not h[j])and(map[k,j]<>0)and(dist[j]>dist[k]+map[k,j]) then
        dist[j]:=dist[k]+map[k,j];
    end;
  end;
  writeln(dist[n]:0:2);
end;

procedure main;
var
  i,k,j:longint;
begin
  for i:=1 to n do
    dist[i]:=1e10;
  dist[1]:=0;
  dijkstra;
end;

begin
  init;
  readdata;
  main;
  outit;
end.

