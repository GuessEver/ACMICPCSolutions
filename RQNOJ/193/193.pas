program road;

const maxn=1000+10;

var
  n,m:longint;
  map:array[0..maxn,0..maxn] of longint;
  dist:array[0..maxn] of longint;
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

procedure readdata;
var
  i,x,y,z:longint;
begin
  fillchar(map,sizeof(map),$7);
  read(n,m);
  for i:=1 to m do
  begin
    read(x,y,z);
    if map[x,y]=0 then map[x,y]:=z
    else if map[x,y]>z then map[x,y]:=z;
    map[y,x]:=map[x,y];
  end;
end;

procedure prim;
var
  i,j,k,min,total:longint;
begin
  total:=0;
  for i:=1 to n do
  begin
    //find min
    k:=0;min:=maxlongint;
    for j:=1 to n do
      if (not h[j])and(dist[j]<min) then
      begin
        k:=j;min:=dist[j];
      end;
    //hash
    //writeln(k:5,'     -->',dist[k]:10);
    h[k]:=true;
    //join
    inc(total,dist[k]);
    for j:=1 to n do
      if (not h[j])and(dist[j]>map[k,j]) then dist[j]:=map[k,j];
  end;
  
  writeln(total);
  
end;

procedure main;
begin
  fillchar(dist,sizeof(dist),$7);
  dist[1]:=0;
  prim;
end;

begin
  init;
  readdata;
  main;
  outit;
end.

