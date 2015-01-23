program rqnoj660;

var
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
begin
  readln(s);
end;

procedure main;
var
  i:longint;
begin
  if length(s)=1 then
  begin
    write(s);
    outit;
  end;
  if s[1]='-' then
  begin
    write('-');
    delete(s,1,1);
  end;
  while s[length(s)]='0' do
    delete(s,length(s),length(s));
  for i:=length(s) downto 1 do
    write(s[i]);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

