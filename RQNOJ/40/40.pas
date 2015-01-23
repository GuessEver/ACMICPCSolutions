program rqnoj40;

var
  a:array[1..1000000] of string;
  //h:array[1..1000000] of boolean;
  top,tt:longint;

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
  s,ss:string;
  i:longint;
begin
  a[1]:='http://www.acm.org/';
  top:=1;tt:=1;s:='';
  while true do
  begin
    readln(s);
    if s='QUIT' then outit
    else if s='BACK' then
    begin
      if top-1>0 then
      begin
        dec(top);
        writeln(a[top]);
      end
      else begin
        writeln('Ignored');
      end;
    end
    else if s='FORWARD' then
    begin
      if top+1<=tt then
      begin
        inc(top);
        writeln(a[top]);
      end
      else begin
        writeln('Ignored');
      end;
    end
    else begin//VISIT
      ss:=s;s:='';
      for i:=7 to length(ss) do s:=s+ss[i];
      inc(top);tt:=top;
      a[top]:=s;
      writeln(a[top]);
    end;
  end;
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

