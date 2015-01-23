program rqnoj169;

var
  n:longint;
  a:array[0..10] of longint;
  f:array[0..100+10] of longint;

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
  for i:=1 to 10 do
  begin
    read(a[i]);
   // a[i]:=a[i]-a[i-1];
  end;
  read(n);
end;

procedure main;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),$7);
  f[0]:=0;
  for i:=1 to 10 do
    for j:=i to n do
    begin
      if f[j]>f[j-i]+a[i] then f[j]:=f[j-i]+a[i];
    end;
  writeln(f[n]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.


