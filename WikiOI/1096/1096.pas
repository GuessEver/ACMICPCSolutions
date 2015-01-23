program rqnoj12;

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
  i,x,num:longint;
  a:array[1..10] of longint;
begin
  num:=0;
  for i:=1 to 10 do read(a[i]);
  read(x);
  inc(x,30);
  for i:=1 to 10 do
    if x>=a[i] then
      inc(num);
  writeln(num);
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
