program save;

var
  sum:longint;
  savemon:double;

procedure init;
begin
end;
procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure main;
var
  i,use:longint;
begin
  sum:=0;
  savemon:=0;
  for i:=1 to 12 do
  begin
    sum:=sum+300;
    readln(use);
    sum:=sum-use;
    if sum>=100 then
    begin
      savemon:=savemon+100*(sum div 100);
      sum:=sum-100*(sum div 100);
    end;
    if sum<0 then
    begin
      writeln(-i);
      outit;
    end;
  end;
  savemon:=savemon*1.2;
  writeln(sum+savemon:0:0);
end;

begin
  init;
  main;
  outit;
end.


