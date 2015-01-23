program rqnoj129;

var
  n:longint;
  f:array[0..10000000] of ansistring;//题目没说范围，只好开这么大了

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

function oo(a:char):longint;
begin
  exit(ord(a)-ord('0'));
end;

function cc(a:longint):char;
begin
  exit(chr(a+ord('0')));
end;

function jia2(a:ansistring):ansistring;
var
  s,ss:ansistring;
  k,i,x:longint;
begin
  a:='0'+a;//便于进位
  k:=0;
  s:='';ss:='';
  for i:=length(a) downto 1 do
  begin
    if i=length(a) then x:=oo(a[i])+2+k
    else x:=oo(a[i])+k;
    k:=x div 10;
    x:=x mod 10;
    s:=s+cc(x);
  end;
  while (length(s)>1)and(s[length(s)]='0') do delete(s,length(s),length(s));
  for i:=length(s) downto 1 do ss:=ss+s[i];
  exit(ss);
end;

function cheng2(a:ansistring):ansistring;
var
  s,ss:ansistring;
  k,i,x:longint;
begin
  a:='0'+a;//便于进位
  k:=0;
  s:='';ss:='';
  for i:=length(a) downto 1 do
  begin
    x:=oo(a[i])*2+k;
    k:=x div 10;
    x:=x mod 10;
    s:=s+cc(x);
  end;
  while (length(s)>1)and(s[length(s)]='0') do delete(s,length(s),length(s));
  for i:=length(s) downto 1 do ss:=ss+s[i];
  exit(ss);
end;

procedure main;
var
  i:longint;
begin
  f[0]:='0';
  for i:=1 to n do
    f[i]:=jia2(cheng2(f[i-1]));
  writeln(f[n]);
end;

begin
  init;
  readdata;
  main;
  outit;
end.
