program rqnoj72;

var
  n,sum,ss:longint;
  a:array[0..100+10] of longint;
  f:array[0..100*100+10] of boolean;

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
  for i:=1 to n do
  begin
    read(a[i]);
    inc(sum,a[i]);
  end;
  ss:=sum;
  sum:=sum div 2;
end;

procedure main;
var
  i,j:longint;
begin
  f[0]:=true;
  for i:=1 to n do
    for j:=sum downto a[i] do
    begin
      if f[j-a[i]] then f[j]:=f[j-a[i]];
    end;
  for j:=sum downto 0 do
    if f[j] then
    begin
      writeln(ss-j*2);
      outit;
    end;
end;

begin
  init;
  readdata;
  main;
  outit;
end.

