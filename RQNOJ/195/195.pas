program rqnoj195;

const
  maxq=2010*2010;
  maxm=2000+10;
  dx:array[1..4] of longint=(0,0,1,-1);
  dy:array[1..4] of longint=(1,-1,0,0);

type
  tnode=record
    x,y:longint;
    step:longint;
  end;

var
  n,m:longint;
  map:array[0..maxm,0..maxm] of longint;
  l,r:longint;
  q:array[0..maxq] of tnode;
  f:array[0..maxm,0..maxm] of boolean;
  first,target:tnode;

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
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(map[i,j]);
  read(target.x,target.y);
  read(first.x,first.y);
end;

procedure inq(var x:tnode);
begin
  inc(r);r:=r mod maxq;
  inc(x.step);
  q[r]:=x;

  f[x.x,x.y]:=true;

  if (x.x=target.x)and(x.y=target.y) then
  begin
    writeln(x.step);
    outit;
  end;
end;

function outq:tnode;
begin
  inc(l);l:=l mod maxq;
  exit(q[l]);
end;

procedure kuo(var node,newnode:tnode;i:longint);
begin
  newnode:=node;
  with newnode do
  begin
    inc(x,dx[i]);
    inc(y,dy[i]);
    if (x<1)or(x>n)or(y<1)or(y>m) then
      newnode:=node;
    if map[x,y]=1 then
      newnode:=node;
  end;
end;

procedure main;
var
  node,newnode:tnode;
  i:longint;
begin
  fillchar(f,sizeof(f),0);
  first.step:=-1;//入队后加1为0
  inq(first);
  while l<>r do
  begin
    node:=outq;
    for i:=1 to 4 do
    begin
      kuo(node,newnode,i);
      if not f[newnode.x,newnode.y] then
        inq(newnode);
    end;
  end;
  writeln('No Answer!');
end;

begin
  init;
  readdata;
  main;
  outit;
end.

