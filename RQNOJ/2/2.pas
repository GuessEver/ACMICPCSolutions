program rqnoj2;

var
  n,m:longint;
  v,p,a:array[0..50] of longint;
  f:array[0..25+10,0..30000+10] of longint;

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
  begin
    read(v[i],p[i]);
    a[i]:=v[i]*p[i];
  end;
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
      if (j>=v[i])and(f[i,j]<f[i-1,j-v[i]]+a[i]) then
        f[i,j]:=f[i-1,j-v[i]]+a[i];
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

