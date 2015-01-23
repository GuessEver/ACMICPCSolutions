program tyvj1004;//滑雪

const
  dx:array[1..4] of longint=(0,0,1,-1);
  dy:array[1..4] of longint=(1,-1,0,0);

var
  n,m:longint;
  f,map:array[0..100+10,0..100+10] of longint;

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
  i,j:longint;
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(map[i,j]);
end;

function max(i,j:longint):longint;
var
  k:longint;
begin
  if (i<1)or(i>n)or(j<1)or(j>n) then exit(0);
  if f[i,j]<>0 then exit(f[i,j]);
  f[i,j]:=1;
  for k:=1 to 4 do
  begin
    if (map[i,j]<map[i+dx[k],j+dy[k]])and(f[i,j]<max(i+dx[k],j+dy[k])+1) then
      f[i,j]:=max(i+dx[k],j+dy[k])+1;
  end;
  exit(f[i,j]);
end;

procedure main;
var
  best,i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  best:=0;
  for i:=1 to n do
    for j:=1 to m do
    if best<max(i,j) then best:=max(i,j);
  writeln(best);
end;

begin
  init;
  readdata;
  main;
  outit;
end.



