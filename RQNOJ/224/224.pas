program rqnoj224;

const
  a:array['a'..'z'] of longint=(1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4);

var
  sum:longint;
  s:ansistring;

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
  ch:char;
begin
  read(s);
  for i:=1 to length(s) do
  begin
    if s[i] in ['a'..'z'] then
      inc(sum,a[s[i]])
    else inc(sum);
  end;
  writeln(sum);
end;

procedure main;
begin
end;

begin
  init;
  readdata;
  main;
  outit;
end.

