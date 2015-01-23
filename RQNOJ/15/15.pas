program rqnoj15;

var
  n,m:longint;
  t,p:array[0..10000+10] of longint;
  f:array[0..1,0..10000+10] of longint;

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
  i,j,best:longint;
begin
  for i:=1 to m do
  begin
    for j:=0 to n do
    begin
      f[i mod 2,j]:=f[(i-1)mod 2,j];
      if (j>=t[i])and(f[i mod 2,j]<f[(i-1)mod 2,j-t[i]]+p[i]) then
        f[i mod 2,j]:=f[(i-1)mod 2,j-t[i]]+p[i];
    end;
  end;
  best:=0;
  for j:=n downto 0 do
    if f[m mod 2,j]>best then best:=f[m mod 2,j];
  writeln(best);
end;


begin
  init;
  readdata;
  main;
  outit;
end.


