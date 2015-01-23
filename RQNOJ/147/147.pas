program rqnoj147;

var
  n,v:longint;
  a:array[0..30+10] of longint;
  f:array[0..30+10,0..20000+10] of boolean;

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
  read(v);
  read(n);
  for i:=1 to n do
    read(a[i]);
end;

procedure main;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  f[0,0]:=true;
  for i:=1 to n do
  begin
    for j:=0 to v do
    begin
      f[i,j]:=f[i-1,j];
      if (j>=a[i])and(f[i-1,j-a[i]]) then
        f[i,j]:=f[i-1,j-a[i]];
    end;
  end;
  for j:=v downto 0 do
    if f[n,j] then
    begin
      writeln(v-j);
      outit;
    end;
end;


begin
  init;
  readdata;
  main;
  outit;
end.

