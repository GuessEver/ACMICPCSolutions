program rqnoj490;

var
  n:longint;
  a,s:array[0..200+10] of longint;
  f:array[0..200+10,0..200+10] of longint;

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
    a[i+n]:=a[i];
  end;
  for i:=1 to 2*n do
    s[i]:=s[i-1]+a[i];
end;

function sum(i,j:longint):longint;
begin
  if i<=j then exit(s[j]-s[i-1])
  else exit(s[j+n]-s[i-1]);
end;

function min(i,j:longint):longint;
var
  k:longint;
begin
  if f[i,j]<>$07070707 then exit(f[i,j]);
  if i=j then exit(0);
  for k:=i to j-1 do
  begin
    if f[i,j]>min(i,k)+min(k+1,j)+sum(i,j) then
      f[i,j]:=min(i,k)+min(k+1,j)+sum(i,j);
  end;
  exit(f[i,j]);
end;

function max(i,j:longint):longint;
var
  k:longint;
begin
  if f[i,j]<>0 then exit(f[i,j]);
  if i=j then exit(0);
  for k:=i to j-1 do
  begin
    if f[i,j]<max(i,k)+max(k+1,j)+sum(i,j) then
      f[i,j]:=max(i,k)+max(k+1,j)+sum(i,j);
  end;
  exit(f[i,j]);
end;

procedure main;
var
  ans,i,j:longint;
begin
  ans:=maxlongint;
  fillchar(f,sizeof(f),$7);
  for i:=1 to n do
    if ans>min(i,i+n-1) then
      ans:=min(i,i+n-1);
  writeln(ans);

  ans:=0;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    if ans<max(i,i+n-1) then
      ans:=max(i,i+n-1);
  writeln(ans);
  
{  for i:=1 to n do
  begin
    for j:=i to i+n-1 do
      write(f[i,j]:5);
    writeln;
  end;}
end;

begin
  init;
  readdata;
  main;
  outit;
end.

