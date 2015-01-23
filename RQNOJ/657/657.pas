program qc;

var
  n,m,max:longint;
  s:int64;
  nnn,sss:array[0..200000+10] of longint;
  w,v,l,r:array[0..200000+10] of longint;

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
  read(n,m,s);
  max:=0;
  for i:=1 to n do
  begin
    read(w[i],v[i]);
    if w[i]>max then max:=w[i];//找出最大重量
  end;
  for i:=1 to m do
    read(l[i],r[i]);
end;

function workjyi(i:longint):int64;
var
  num,sum:int64;
begin
  num:=nnn[r[i]]-nnn[l[i]-1];
  sum:=sss[r[i]]-sss[l[i]-1];
  exit(num*sum);
end;

procedure predoing(ww:longint);
var
  i:longint;
begin
  nnn[0]:=0;sss[0]:=0;
  for i:=1 to n do
  begin
    nnn[i]:=nnn[i-1];
    sss[i]:=sss[i-1];
    if w[i]>=ww then
    begin
      inc(nnn[i]);
      inc(sss[i],v[i]);
    end;
  end;
end;

function workjy(ww:longint):int64;
var
  jyi,y:int64;
  i:longint;
begin
  y:=0;
  predoing(ww);//预处理sum和num
  for i:=1 to m do//依次计算每个区间
  begin
    jyi:=workjyi(i);
    y:=y+jyi;
  end;
  exit(y);
end;

procedure main;
var
  jy,ans:int64;
  bot,top,mid:longint;
begin
  //fillchar(ans,sizeof(ans),$7f);
  
  //二分+预处理求和
  bot:=0;top:=max+10;
  while bot<top do
  begin
    mid:=bot+(top-bot)div 2;
    jy:=workjy(mid);
    if jy<=s then top:=mid;
    if jy>s then bot:=mid+1;
  end;
  
  ans:=abs(workjy(bot)-s);
  if abs(workjy(bot-1)-s)<ans then ans:=abs(workjy(bot-1)-s);
  writeln(ans);
end;

begin
  init;
  readdata;
  main;
  outit;
end.


