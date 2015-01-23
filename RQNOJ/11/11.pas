program rqnoj11;

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
  n,m:longint;
  i,x:longint;
  a:array[0..9] of longint;
begin
  read(m,n);
  fillchar(a,sizeof(a),0);
  for i:=m to n do
  begin
    x:=i;
    repeat
      inc(a[x mod 10]);
      x:=x div 10;
    until x=0;
  end;
  for i:=0 to 9 do
    write(a[i],' ');
end;


begin
  init;
  readdata;
  main;
  outit;
end.

