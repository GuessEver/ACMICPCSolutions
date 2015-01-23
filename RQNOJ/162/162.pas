program rqnoj162;

var
  n,m:longint;
  p,a:array[0..5000+10] of longint;
  f:array[0..20000+10] of longint;

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
  for i:=1 to n do
  begin
    read(p[i],a[i]);
  end;
end;

procedure main;
var
  i,j,k:longint;
begin
  for i:=1 to n do f[i]:=-1;
  for i:=1 to n do
  begin
    for j:=p[i] to m do
    begin
      if (f[j-p[i]]<>-1)and(f[j]<f[j-p[i]]+a[i]) then
        f[j]:=f[j-p[i]]+a[i];
    end;
  end;
  writeln(f[m]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

