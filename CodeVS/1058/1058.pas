program chorus;

var
  n:longint;
  a,l,r:array[0..100+10] of longint;

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
    read(a[i]);
end;

procedure left;
var
  i,j:longint;
begin
  for i:=1 to n do l[i]:=1;
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
    begin
      if a[j]<a[i] then
      begin
        if l[i]<l[j]+1 then l[i]:=l[j]+1;
      end;
    end;
  end;
end;

procedure right;
var
  i,j:longint;
begin
  for i:=1 to n do r[i]:=1;
  for i:=n-1 downto 1 do
  begin
    for j:=n downto i+1 do
    begin
      if a[j]<a[i] then
      begin
        if r[i]<r[j]+1 then r[i]:=r[j]+1;
      end;
    end;
  end;
end;

procedure main;
var
  i,best:longint;
begin
  left;
  right;
  best:=0;
  for i:=1 to n do
    if best<l[i]+r[i]-1 then
      best:=l[i]+r[i]-1;
      
  writeln(n-best);
end;

begin
  init;
  readdata;
  main;
  outit;
end.
