program rqnoj484;

var
  n,m,num:longint;
  map:array[0..100+10,0..100+10] of char;
  ans:array[0..100+10,0..100+10] of longint;

procedure init;
begin
end;

procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure work;
var
  i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to m do
    begin
      if map[i,j]='*' then
      begin
        ans[i,j]:=-1;
        continue;
      end;
      if map[i-1,j]='*' then inc(ans[i,j]);//上
      if map[i+1,j]='*' then inc(ans[i,j]);//下
      if map[i,j-1]='*' then inc(ans[i,j]);//左
      if map[i,j+1]='*' then inc(ans[i,j]);//右
      if map[i-1,j-1]='*' then inc(ans[i,j]);//左上
      if map[i-1,j+1]='*' then inc(ans[i,j]);//右上
      if map[i+1,j-1]='*' then inc(ans[i,j]);//左下
      if map[i+1,j+1]='*' then inc(ans[i,j]);//右下
    end;
  if num>=2 then
  begin
    writeln;
    writeln;
  end;
  writeln('Field #',num,':');
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      if ans[i,j]=-1 then
      begin
        write('*');
        continue;
      end;
      write(ans[i,j]);
    end;
    if i<>n then writeln;
  end;
end;

procedure readdata;
var
  i,j:longint;
begin
  while true do
  begin
    readln(n,m);
    fillchar(map,sizeof(map),0);
    if (n=0)and(m=0) then outit;
    inc(num);
    for i:=1 to n do
    begin
      for j:=1 to m do
        read(map[i,j]);
      readln;
    end;
    fillchar(ans,sizeof(ans),0);
    work;
  end;
end;

begin
  init;
  readdata;
  //main;
  outit;
end.

