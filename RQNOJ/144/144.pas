program rqnoj144;

var
  n,k:longint;
  a:array[0..1001+10] of ansistring;

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

procedure swap(var a,b:ansistring);
var t:ansistring;
begin
  t:=a;a:=b;b:=t;
end;

procedure qsort(l,r:longint);
var
  i,j:longint;
  x:ansistring;
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

procedure main;
var
  i:longint;
begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  qsort(1,n);
  writeln(a[k]);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

