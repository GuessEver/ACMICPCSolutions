program rqnoj220;

const
  dx:array[1..8] of longint=( 1, 1,-1,-1, 2, 2,-2,-2);
  dy:array[1..8] of longint=( 2,-2, 2,-2, 1,-1, 1,-1);

type
  tnode=record
    x,y,step:longint;
  end;
  
var
  first,target:tnode;
  l,r:longint;
  q:array[0..10*9*10*9+100] of tnode;
  h:array[0..20,0..20] of boolean;

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
  read(first.x,first.y);
  first.step:=-1;//入队后 +1 为 0
  target.x:=1;
  target.y:=5;
end;

function isok(x,y:longint):boolean;
begin
  if ((x=1)and(y=4))and((x=1)and(y=6))and((x=2)and(y=5)) then exit(false);
  exit(true);
end;

procedure inq(var x:tnode);
begin
  inc(r);
  inc(x.step);
  h[x.x,x.y]:=true;
  if (x.x=target.x)and(x.y=target.y) then
  begin
    writeln(x.step);
    outit;
  end;
  
  q[r]:=x;
end;

function outq:tnode;
begin
  inc(l);
  exit(q[l]);
end;

procedure kuo(var node,newnode:tnode;i:longint);
begin
  newnode:=node;
  newnode.x:=newnode.x+dx[i];
  newnode.y:=newnode.y+dy[i];
  if not isok(newnode.x,newnode.y) then newnode:=node;
  if (newnode.x<1)or(newnode.x>10)or(newnode.y<1)or(newnode.y>9) then newnode:=node;
end;

procedure main;
var
  node,newnode:tnode;
  i:longint;
begin
  fillchar(h,sizeof(h),0);
  inq(first);
  while l<r do
  begin
    node:=outq;
    for i:=1 to 8 do
    begin
      kuo(node,newnode,i);
      if not h[newnode.x,newnode.y] then inq(newnode);
    end;
  end;
  writeln('No Answer');
end;

begin
  init;
  readdata;
  main;
  outit;
end.

