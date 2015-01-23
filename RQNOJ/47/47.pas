program network;

const maxn=200+10;

type
  link=^tnode;
  tnode=record
    pos,wight:longint;
    next:link;
  end;

var
  n,m:longint;
  c,u,into,ans:array[0..maxn] of longint;
  chu,ru:array[0..maxn] of link;

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
  p^.wight:=z;
  p^.next:=chu[x];
  chu[x]:=p;

  new(p);
  p^.pos:=x;
  p^.wight:=z;
  p^.next:=ru[y];
  ru[y]:=p;
end;

procedure readdata;
var
  x,y,z,i:longint;
begin
  read(n,m);
  for i:=1 to n do
    read(c[i],u[i]);
  for i:=1 to m do
  begin
    read(x,y,z);
    insert(x,y,z);
    inc(into[y]);
  end;
end;

procedure tp;
var
  i,j,y:longint;
  p:link;
begin
  for i:=1 to n do
  begin
    j:=1;
    while (j<=n)and(into[j]<>0) do inc(j);
    into[j]:=maxlongint;
    ans[i]:=j;
    p:=chu[j];
    while p<>nil do
    begin
      y:=p^.pos;
      dec(into[y]);
      p:=p^.next;
    end;
  end;
end;

procedure work(k:longint);
var
  p:link;
  y,z:longint;
begin
  p:=ru[k];
  if ru[k]<>nil then c[k]:=c[k]-u[k];
  while p<>nil do
  begin
    y:=p^.pos;
    z:=p^.wight;
    if c[y]>0 then
      c[k]:=c[k]+c[y]*z;
    p:=p^.next;
  end;

end;

procedure main;
var
  i,num:longint;
begin
  tp;
  for i:=1 to n do
  begin
    work(ans[i]);
  end;
  
  num:=0;
  for i:=1 to n do
  begin
    if chu[i]<>nil then continue;
    if c[i]<=0 then continue;
    writeln(i,' ',c[i]);
    inc(num);
  end;
  if num=0 then writeln('NULL');
end;

begin
  init;
  readdata;
  main;
  outit;
end.

