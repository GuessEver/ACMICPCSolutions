program hotel;

var
  n,kk,pp:longint;
  ans:longint;
  k,p:array[0..200000+10] of longint;
  num,sum,next:array[0..200000+10] of longint;

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
  read(n,kk,pp);
  
  for i:=1 to n do
  begin
    read(k[i],p[i]);
    sum[i]:=sum[i-1];
    if p[i]<=pp then inc(sum[i]);
  end;
  
  for i:=2 to n do
    for j:=i-1 downto 1 do
    begin
      if k[j]=k[i] then
      begin
        next[i]:=j;
        break;
      end;
    end;

  num[1]:=1;
  for i:=2 to n do
    num[i]:=num[next[i]]+1;
end;

procedure main;
var
  i,j,x:longint;
begin
  ans:=0;
  
  //朴素枚举+前缀和优化
  {for i:=1 to n do
  begin
    for j:=i+1 to n do//从i+1开始 避免重复计数
    begin
      if k[i]<>k[j] then continue;//色调不同 跳过
      if sum[j]-sum[i-1]>0 then inc(ans);
    end;
  end;}
  
  //链表枚举+前缀和优化
  for j:=2 to n do
  begin
    i:=next[j];
    while i<>0 do
    begin
      if sum[j]-sum[i-1]>0 then
      begin
        inc(ans,num[i]);
        break;
      end;
      i:=next[i];
    end;
  end;
  
  writeln(ans);
end;


begin
  init;
  readdata;
  main;
  outit;
end.


