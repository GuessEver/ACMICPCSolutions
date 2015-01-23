program rqnoj20;


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
end;

procedure main;
var
  i,a,b,k,max:longint;
begin
  max:=0;k:=0;
  for i:=1 to 7 do
  begin
    read(a,b);
    if (a+b>8)and(a+b>max) then
    begin
      max:=a+b;
      k:=i;
    end;
  end;
  writeln(k);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

