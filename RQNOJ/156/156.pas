program rqnoj167;

var
  n:longint;
  a,f:array[0..10000+10] of longint;

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
  for i:=1 to n do read(a[i]);
end;

procedure main;
var
  max,i,j:longint;
begin
  max:=1;
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      if (a[i]>a[j])and(f[i]<f[j]+1) then
      begin
        f[i]:=f[j]+1;
        if max<f[i] then max:=f[i];
      end;
  writeln(max);
end;

begin
  init;
  readdata;
  main;
  outit;
end.


