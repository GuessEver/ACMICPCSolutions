program alpha;
var
  n:longint;
  s:array[1..3] of string;
  a,b,c,ans,h,order:array[0..30] of longint;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure pre;
var
  i,k:longint;
  u:array[0..30] of longint;
begin
  fillchar(u,sizeof(u),0);
  k:=0;

  for i:=n downto 1 do
  begin
    if u[a[i]]=0 then
    begin
      u[a[i]]:=1;
      k:=k+1;
      order[k]:=a[i];
    end;
    if u[b[i]]=0 then
    begin
      u[b[i]]:=1;
      k:=k+1;
      order[k]:=b[i];
    end;
    if u[c[i]]=0 then
    begin
      u[c[i]]:=1;
      k:=k+1;
      order[k]:=c[i];
    end;
  end;

end;

procedure readdata;
var
  i:longint;
begin
  readln(n);

  for i:=1 to 3 do
    readln(s[i]);

  //预处理 a+b=c
  for i:=1 to n do
  begin
    a[i]:=ord(s[1][i])-ord('A')+1;
    b[i]:=ord(s[2][i])-ord('A')+1;
    c[i]:=ord(s[3][i])-ord('A')+1;
  end;

 { for i:=1 to n do
    write(a[i]);
  writeln;
  for i:=1 to n do
    write(b[i]);
  writeln;
  for i:=1 to n do
    write(c[i]);
  writeln;}

  pre;
end;


function check:integer;
var
  i:longint;
begin
  for i:=n downto 1 do
  begin
    if ((ans[a[i]]>=0)and(ans[b[i]]>=0)and(ans[c[i]]>=0))and((ans[c[i]]<>(ans[a[i]]+ans[b[i]]) mod n)and(ans[c[i]]<>(ans[a[i]]+ans[b[i]]+1) mod n)) then
    begin
      exit(0);
    end;
  end;
  exit(1);
end;


procedure quan(x:longint);
var
  i,jinwei:longint;
begin

  if x>n then
  begin

    jinwei:=0;

   { ans[1]:=1;
    ans[2]:=0;
    ans[3]:=3;
    ans[4]:=4;
    ans[5]:=2;}

    for i:=n downto 1 do
    begin
      if (ans[a[i]]+ans[b[i]]+jinwei)mod n<>ans[c[i]] then
        exit;
      jinwei:=(ans[a[i]]+ans[b[i]]+jinwei) div n;
    end;

    for i:=1 to n do
      write(ans[i],' ');

    outit;
  end;

  for i:=n-1 downto 0 do
  begin
    if h[i]=0 then
    begin
      ans[order[x]]:=i;
      h[i]:=1;
      if check=1 then quan(x+1);
      h[i]:=0;
      ans[order[x]]:=-1;
    end;
  end;


end;

procedure main;
var
  i:longint;
begin

  fillchar(h,sizeof(h),0);
  for i:=0 to 30 do
    ans[i]:=-1;
  quan(1);
  //for i:=1 to n do
    //write(ans[i],' ');
end;

begin
  init;
  readdata;
  main;
  outit;
end.


