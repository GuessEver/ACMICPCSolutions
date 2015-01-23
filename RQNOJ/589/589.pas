program nq;

var
  n:longint;
  num:longint;
  ans:array[0..100] of longint;
  h,s,z,y:array[-100..100] of boolean;

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
  read(n);
end;

procedure dfs(x:longint);
var
  i:longint;
begin
  if x>n then
  begin
    inc(num);
    if num<=3 then
    begin
      for i:=1 to n-1 do  write(ans[i],' ');
      write(ans[n]);
      writeln;
    end;
  end;
  
  for i:=1 to n do
  begin
    if (not h[x])and(not s[i])and(not z[x-i])and(not y[i+x]) then
    begin
      ans[x]:=i;
      h[x]:=true;
      s[i]:=true;
      z[x-i]:=true;
      y[i+x]:=true;
      dfs(x+1);
      h[x]:=false;
      s[i]:=false;
      z[x-i]:=false;
      y[i+x]:=false;
    end;
  end;
end;

procedure main;
begin
  fillchar(h,sizeof(h),0);
  fillchar(s,sizeof(s),0);
  fillchar(z,sizeof(z),0);
  fillchar(y,sizeof(y),0);
  dfs(1);
  writeln(num);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

