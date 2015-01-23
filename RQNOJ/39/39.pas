program rqnoj39;

var
  n,m:longint;
  a:array[0..21+10] of longint;
  f:array[0..21+10,0..35000+10] of longint;

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
  read(n,m);
  for i:=1 to m do
    read(a[i]);
end;

procedure main;
var
  i,j,best:longint;
begin
  for i:=1 to m do
  begin
    for j:=0 to n do
    begin
      f[i,j]:=f[i-1,j];
      if (j>=a[i])and(f[i,j]<f[i-1,j-a[i]]+a[i]) then
        f[i,j]:=f[i-1,j-a[i]]+a[i];
    end;
  end;
  best:=0;
  for j:=1 to n do
    if f[m,j]>best then best:=f[m,j];
  writeln(best);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

