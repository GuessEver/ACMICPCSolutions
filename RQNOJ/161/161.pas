program lift;

const maxn=200+10;

var
  n,a,b:longint;
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
  i,k:longint;
begin
  fillchar(map,sizeof(map),$7);
  read(n,a,b);
  for i:=1 to n do
  begin
    map[i,i]:=0;
    read(k);
    if k=0 then continue;
    if i+k<=n then map[i,i+k]:=1;
    if i-k>0 then map[i,i-k]:=1;
  end;
end;

procedure main;
var
  i,j,k,min:longint;
begin
  fillchar(dist,sizeof(dist),$7);
  fillchar(h,sizeof(h),0);
  dist[a]:=0;
  
  for i:=1 to n do
  begin
    k:=0;min:=maxlongint;
    for j:=1 to n do
    begin
      if (not h[j])and(dist[j]<min) then
      begin
        min:=dist[j];
        k:=j;
      end;
    end;
    
    h[k]:=true;
    
    for j:=1 to n do
    begin
      if (not h[j])and(dist[j]>dist[k]+map[k,j]) then
        dist[j]:=dist[k]+map[k,j];
    end;
  end;
  
  if dist[b]=$07070707 then writeln(-1) else writeln(dist[b]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.


