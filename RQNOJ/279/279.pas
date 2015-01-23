program rqnoj279;

var
  n:longint;
  lost,get:array[0..20+10] of longint;
  f:array[0..100+10] of longint;

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
  i:longint;
begin
  read(n);
  for i:=1 to n do read(lost[i]);
  for i:=1 to n do read(get[i]);
end;

procedure main;
var
  i,j:longint;
begin
  for i:=1 to n do
    for j:=100 downto lost[i]+1 do
      if f[j]<f[j-lost[i]]+get[i] then
        f[j]:=f[j-lost[i]]+get[i];
  writeln(f[100]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.


