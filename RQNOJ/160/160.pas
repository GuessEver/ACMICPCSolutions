program rqnoj160;

var
  n,time:longint;
  ws,wt,ps,pt:array[0..30+10] of longint;
  f:array[0..1080000+10] of longint;

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
  i:longint;
begin
  read(n,time);
  for i:=1 to n do
    read(ws[i],wt[i],ps[i],pt[i]);
end;

procedure main;
var
  i,j:longint;
begin
  for i:=1 to n do
  begin
    for j:=time downto 0 do
    begin
      if (j>=wt[i])and(f[j]<f[j-wt[i]]+ws[i]) then f[j]:=f[j-wt[i]]+ws[i];
      if (j>=pt[i])and(f[j]<f[j-pt[i]]+ps[i]) then f[j]:=f[j-pt[i]]+ps[i];
    end;
  end;
  writeln(f[time]);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

