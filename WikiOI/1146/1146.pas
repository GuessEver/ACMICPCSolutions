program rqnoj485;


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

function tonum(s:char):longint;
begin
  exit(ord(s)-ord('0'));
end;

procedure main;
var
  s:string;
  i:longint;
  sum,num:longint;
begin
  read(s);
  sum:=0;num:=0;
  for i:=1 to 12 do
  begin
    if s[i]='-' then continue;
    inc(num);
    sum:=sum+(ord(s[i])-ord('0'))*num;
  end;
  sum:=sum mod 11;
  
  if sum=10 then
  begin
    if s[13]='X' then write('Right')
    else begin
      for i:=1 to 12 do write(s[i]);
      write('X');
    end;
  end;
  if sum<10 then
  begin
    if tonum(s[13])=sum then write('Right')
    else begin
      for i:=1 to 12 do write(s[i]);
      write(sum);
    end;
  end;
end;


begin
  init;
  readdata;
  main;
  outit;
end.

