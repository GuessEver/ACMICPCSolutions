program rqnoj158;

var
  n:longint;
  map,f:array[0..50,0..50] of longint;

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
  read(n);
  fillchar(map,sizeof(map),255);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(map[i,j]);
    end;
end;

procedure main;
var
  i,j:longint;
begin
  f[1,1]:=1;
  for i:=1 to n do
    for j:=1 to n do
    begin
      if map[i,j]<>0 then continue;
      if (i=1)and(j=1) then continue;
      if (map[i-1,j]<>0)and(map[i,j-1]=0) then
        f[i,j]:=f[i,j-1];
      if (map[i-1,j]=0)and(map[i,j-1]<>0) then
        f[i,j]:=f[i-1,j];
      if (map[i-1,j]=0)and(map[i,j-1]=0) then
        f[i,j]:=f[i-1,j]+f[i,j-1];
    end;
  writeln(f[n,n]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

