program rqnoj661;

var
  w,s:ansistring;
  num:longint;
  k:array[0..10000000] of longint;

procedure init;
begin
end;

procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure xiao(var s:ansistring);
var
  i:longint;
begin
  for i:=1 to length(s) do
  begin
    if s[i] in ['a'..'z'] then continue;
    if s[i] in ['A'..'Z'] then
    begin
      s[i]:=chr(ord(s[i])+32);
    end;
  end;
end;

procedure readdata;
begin
  readln(w);
  readln(s);
  xiao(w);//全部转换为小写
  xiao(s);
end;

procedure main;
var
  a:ansistring;
  i:longint;
begin
  a:='';
  for i:=1 to length(s) do
  begin
    if s[i]=' ' then
    begin
      if a=w then
      begin
        inc(num);
        k[num]:=i-length(w);
      end;
      a:='';
      continue;
    end;
    a:=a+s[i];
  end;
  if num=0 then
  begin
    writeln(-1);
    outit;
  end;
  writeln(num,' ',k[1]-1);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

