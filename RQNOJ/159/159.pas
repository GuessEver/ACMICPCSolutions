program rqnoj159;

var
  n,k:longint;
  a:array[0..200000+10] of longint;

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
begin
end;

procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure qsort(l,r:longint);
var
  i,j:longint;
  x:longint;
begin
  i:=l;j:=r;x:=a[(i+j)div 2];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]);
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

function ok(x:longint):boolean;
var
  i:longint;
begin
  for i:=2 to x-1 do
  begin
    if x mod i =0 then exit(false);
  end;
  exit(true);
end;

procedure main;
var
  i,sum:longint;
begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  qsort(1,n);
  sum:=0;
  for i:=1 to n do
    if a[i]>=k then
    begin
      inc(sum,a[i-1]);
      break;
    end;
  for i:=n downto 1 do
    if a[i]<=k then
    begin
      inc(sum,a[i+1]);
      break;
    end;
  writeln(sum);
  if ok(sum) then writeln('Y') else writeln('F');
end;


begin
  init;
  readdata;
  main;
  outit;
end.

