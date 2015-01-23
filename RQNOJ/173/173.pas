program rqnoj173;

var
  n,sum:longint;
  a:array[0..20000+10] of longint;

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
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[j]<a[i] then inc(sum);
  writeln(sum);
end;

procedure main;
begin
end;

begin
  init;
  readdata;
  main;
  outit;
end.

