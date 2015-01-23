program rqnoj217;

var
  n:longint;
  a,f:array[0..1000+10] of longint;

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
  i,j,max,min:longint;
begin
  max:=1; min:=1;
  for i:=1 to n do f[i]:=1;
  for i:=1 to n do
  begin
    for j:=1 to i-1 do
    begin
      if a[i]>a[j] then continue;
      if f[i]<f[j]+1 then f[i]:=f[j]+1;
      if f[i]>max then max:=f[i];
    end;
  end;
  
  for i:=1 to n do f[i]:=1;
  for i:=1 to n do
    for j:=1 to i-1 do
    begin
      if a[i]<=a[j] then continue;
      if f[i]<f[j]+1 then f[i]:=f[j]+1;
      if f[i]>min then min:=f[i];
    end;
  
  writeln(max,' ',min);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

