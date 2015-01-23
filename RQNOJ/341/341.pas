program rqnoj341;

type
  link=^tnode;
  tnode=record
    pos,long:longint;
    next:link;
  end;
  
var
  n,m:longint;
  first:array[0..30000+10] of link;
  min:array[0..30000+10] of longint;

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
  read(n,m);
  for i:=1 to m do
  begin
    read(x,y,z);
    insert(x,y,z);
    insert(y,x,z);
  end;
end;

procedure main;
var
  flag:boolean;
  x,y,z:longint;
  p:link;
begin
  fillchar(min,sizeof(min),$7);
  min[1]:=0;
  
  while flag do
  begin
    flag:=false;
    for x:=1 to n do
    begin
      p:=first[x];
      while p<>nil do
      begin
        y:=p^.pos;
        z:=p^.long;
        if min[x]+z<min[y] then
        begin
          min[y]:=min[x]+z;
          flag:=true;
        end;
        p:=p^.next;
      end;
    end;
  end;
  writeln(min[n]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

