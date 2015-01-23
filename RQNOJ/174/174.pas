program rqnoj174;

var
  a,b:string;

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
  ch:char;
begin
  read(ch);if ch in ['a'..'z'] then ch:='a' else ch:='A'; a:=ch;
  read(ch);if ch in ['a'..'z'] then ch:='a' else ch:='A'; a:=a+ch;
  read(ch);
  read(ch);if ch in ['a'..'z'] then ch:='a' else ch:='A'; b:=ch;
  read(ch);if ch in ['a'..'z'] then ch:='a' else ch:='A'; b:=b+ch;
end;

procedure main;
begin
  if (a='AA')and(b='AA') then
  begin
    writeln('4:0');
    outit;
  end;
  if (a='AA')and(b='aa') then
  begin
    writeln('4:0');
    outit;
  end;
  if (a='AA')and(b='Aa') then
  begin
    writeln('4:0');
    outit;
  end;
  if (a='aa')and(b='Aa') then
  begin
    writeln('1:1');
    outit;
  end;
  if (a='aa')and(b='aa') then
  begin
    writeln('0:4');
    outit;
  end;
  if (a='Aa')and(b='Aa') then
  begin
    writeln('3:1');
    outit;
  end;
end;

begin
  init;
  readdata;
  main;
  outit;
end.

