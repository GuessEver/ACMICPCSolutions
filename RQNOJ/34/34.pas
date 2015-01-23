program rqnoj34;

const
  maxq=1000*1000+10;
  dx:array[1..4] of longint=(0,0,1,-1);
  dy:array[1..4] of longint=(1,-1,0,0);

type
  tnode=record
    x,y:longint;
    step:longint;
  end;

var
  n:longint;
  map:array[0..1000+10,0..1000+10] of boolean;
  first,target:tnode;
  l,r:longint;
  q:array[0..maxq] of tnode;
  h:array[0..1000+10,0..1000+10] of boolean;


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
  i,j:longint;
  s:ansistring;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    for j:=1 to length(s) do
      if s[j]='0' then map[i,j]:=true
        else if s[j]='1' then map[i,j]:=false;
  end;
  read(first.x,first.y);
  read(target.x,target.y);
end;

procedure inq(var x:tnode);
begin
  inc(r);r:=r mod maxq;
  inc(x.step);
  q[r]:=x;
  h[x.x,x.y]:=true;
  
  if (x.x=target.x)and(x.y=target.y) then
  begin
    writeln(x.step);
    outit;
  end;
end;

function outq:tnode;
begin
  inc(l);
  exit(q[l]);
end;

procedure kuo(var node,newnode:tnode;i:longint);
begin
  newnode:=node;
  inc(newnode.x,dx[i]);
  inc(newnode.y,dy[i]);
  with newnode do
  begin
    if (x<1)or(x>n)or(y<1)or(y>n)or(not map[x,y]) then
      newnode:=node;
  end;
end;

procedure main;
var
  node,newnode:tnode;
  i:longint;
begin
  first.step:=-1;//入队后加 1 为 0
  inq(first);
  while l<>r do
  begin
    node:=outq;
    for i:=1 to 4 do
    begin
      kuo(node,newnode,i);
      if not h[newnode.x,newnode.y] then inq(newnode);
    end;
  end;
end;

begin
  init;
  readdata;
  main;
  outit;
end.

