program rqnoj198;

var
  n,m:longint;
  t,p:array[0..10000+10] of longint;
  f:array[0..10000+10] of longint;

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
    read(t[i],p[i]);
end;

procedure main;
var
  i,j:longint;
begin
  for i:=1 to m do
    for j:=n downto t[i] do
    begin
      if f[j]<f[j-t[i]]+p[i] then
      begin
        f[j]:=f[j-t[i]]+p[i];
      end;
    end;
  writeln(f[n]);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

