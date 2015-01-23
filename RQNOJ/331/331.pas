program relation;

var
  n,m,p:longint;
  f:array[0..5000+10] of longint;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure predoing;
var i:longint;
begin
  for i:=1 to n do
    f[i]:=i;
end;

function find(x:longint):longint;
begin
  if f[x]=x then exit(x);
  
  f[x]:=find(f[x]);
  exit(f[x]);
end;

procedure insert(x,y:longint);
var rx,ry:longint;
begin
  rx:=find(x);
  ry:=find(y);
  f[rx]:=ry;
end;

procedure readdata;
var
  i,x,y:longint;
begin
  read(n,m,p);
  predoing;
  for i:=1 to m do
  begin
    read(x,y);
    insert(x,y);
  end;
  for i:=1 to p do
  begin
    read(x,y);
    if find(x)=find(y) then writeln('Yes')
    else writeln('No');
  end;
end;

procedure main;
begin
end;

begin
  init;
  readdata;
  main;
  outit;
end.

