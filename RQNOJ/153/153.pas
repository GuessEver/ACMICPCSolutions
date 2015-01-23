program rqnoj153;

var
  n,sum:longint;

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
begin
  read(n);
end;

procedure work(x:longint);
var
  i:longint;
begin
  if x=1 then exit;
  x:=x div 2;
  for i:=1 to x do
  begin
    inc(sum);
    work(i);
  end;
end;

procedure main;
var
  i:longint;
begin
  sum:=1;
  work(n);
  writeln(sum);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

