program rqnoj493;

var
  d,n:longint;
  t,l,h:array[0..125+10] of longint;
  f:array[0..1000+10,0..125+10] of boolean;

procedure init;
begin
end;

procedure outit;
begin
  close(input);
  close(output);
  halt;
end;

procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure readdata;
var
  i,j,tmp:longint;
begin
  read(d,n);
  for i:=1 to n do
  begin
    read(t[i],l[i],h[i]);
  end;

  for i:=1 to n-1 do
  begin
    for j:=i+1 to n do
    begin
      if t[i]>t[j] then
      begin
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        tmp:=l[i];l[i]:=l[j];l[j]:=tmp;
        tmp:=h[i];h[i]:=h[j];h[j]:=tmp;
      end;
    end;
  end;

end;

procedure awriteans(i:longint);
begin
  writeln(t[i]);
  outit;
end;

procedure main;
var
  i,j,k,sum:longint;
begin
  fillchar(f,sizeof(f),0);
  f[10,0]:=true;

  for i:=1 to n do
    for j:=1000 downto t[i] do
      for k:=d+25 downto 0 do
      begin
        //堆
        if (j>=t[i])and(k-h[i]>=0)and(f[j,k-h[i]]) then
        begin
          f[j,k]:=true;
          if k>=d then awriteans(i);
        end;
        //吃
        if (j-l[i]>=t[i])and(f[j-l[i],k]) then
        begin
          f[j,k]:=true;
          if k>=d then awriteans(i);
        end;
      end;

  sum:=10;
  for i:=1 to n do
  begin
    if sum<t[i] then
    begin
      writeln(sum);
      outit;
    end;
    inc(sum,l[i]);
  end;
  writeln(sum);
end;

begin
  init;
  readdata;
  main;
  outit;
end.

