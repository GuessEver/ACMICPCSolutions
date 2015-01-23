program rqnoj109;

var
  n,m:longint;
  a,p:array[0..500+10] of longint;
  s:array[0..5000+10] of string;
  f:array[0..5000+10] of longint;

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
  i,x,y,z:longint;
begin
  read(n,m);
  for i:=1 to n do
  begin
    read(x,y,z);
    a[i]:=x*z;
    p[i]:=y*z;
  end;
end;

function sssss(x:longint):string;
var
  k,kk:string;
  a,i:longint;
begin
  k:='';
  while x<>0 do
  begin
    a:=x mod 10;
    k:=k+chr(a+ord('0'));
    x:=x div 10;
  end;
  kk:='';
  for i:=length(k) downto 1 do
  begin
    kk:=kk+k[i];
  end;
  exit(kk);
end;

procedure main;
var
  i,j:longint;
begin
  for i:=1 to n do
    for j:=m downto a[i] do
    begin
      if f[j]<f[j-a[i]]+p[i] then
      begin
        f[j]:=f[j-a[i]]+p[i];
        s[j]:=s[j-a[i]]+' '+sssss(i);
      end;
    end;
  writeln(f[m]);
  for i:=2 to length(s[m]) do write(s[m][i]);
  //writeln(sssss(51));
end;

begin
  init;
  readdata;
  main;
  outit;
end.

