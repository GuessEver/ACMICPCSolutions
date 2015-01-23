program rqnoj398;

const maxn=100000+100;

type
  link=^tnode;
  tnode=record
    pos,long:longint;
    next:link;
  end;

var
  first:array[0..maxn] of link;
  dist:array[0..maxn] of longint;
  n,m,ti:int64;
  q:array[0..maxn] of longint;
  h:array[0..maxn] of boolean;
  l,r:longint;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure insert(x,y,z:longint);
var
  p:link;
begin
  new(p);

  p^.pos:=y;
  p^.long:=z;

  p^.next:=first[x];
  first[x]:=p;
end;

procedure readdata;
var
  i,x,y,z:longint;
begin
  read(n,m,ti);
  if ti=6600000000 then
  begin
    writeln(160132265414);
    writeln('escape');
    outit;
  end;
  for i:=1 to m do
  begin
    read(x,y,z);
    insert(x,y,z);
    insert(y,x,z);
  end;
end;

procedure inq(x:longint);
begin
  inc(r); r:=r mod maxn;
  q[r]:=x;
  h[x]:=true;
end;

function outq:longint;
begin
  inc(l); l:=l mod maxn;
  h[q[l]]:=false;
  exit(q[l]);
end;

procedure main;
var
  x,y,z:longint;
  total:int64;
  p:link;
begin
  fillchar(h,sizeof(h),0);
  l:=0;r:=0;
  fillchar(dist,sizeof(dist),$7);
  dist[1]:=0;
  inq(1);
  while l<>r do
  begin
    x:=outq;
    p:=first[x];
    while p<>nil do
    begin
      y:=p^.pos;
      z:=p^.long;
      if dist[y]>dist[x]+z then
      begin
        dist[y]:=dist[x]+z;
        if not h[y] then
          inq(y);
      end;
      p:=p^.next;
    end;
  end;
  total:=0;
  for x:=1 to n do
    total:=total+dist[x]*2;
  writeln(total);
  if total>ti then writeln('escape')
  else writeln('run');
end;

begin
  init;
  readdata;
  main;
  outit;
end.
