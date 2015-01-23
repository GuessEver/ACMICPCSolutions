program rqnoj16;

var
  n:longint;
  a:array[0..100+10] of string;
  sum:array[0..100+10] of longint;
  qimo,pingshi,lunwen:array[0..100+10] of longint;
  xibu,ganbu:array[0..100+10] of char;

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
  ch:char;
  i:longint;
  best,k,total:longint;
begin
  readln(n);
  best:=-maxlongint;k:=0;
  for i:=1 to n do
  begin
    read(ch);a[i]:='';
    while ch<>' ' do
    begin
      a[i]:=a[i]+ch;
      read(ch);
    end;
    read(qimo[i],pingshi[i],ch,ganbu[i],ch,xibu[i],lunwen[i]);
    
    if (qimo[i]>80)and(lunwen[i]>=1) then inc(sum[i],8000);
    if (qimo[i]>85)and(pingshi[i]>80) then inc(sum[i],4000);
    if (qimo[i]>90) then inc(sum[i],2000);
    if (qimo[i]>85)and(xibu[i]='Y') then inc(sum[i],1000);
    if (pingshi[i]>80)and(ganbu[i]='Y') then inc(sum[i],850);
    
    if sum[i]>best then
    begin
      best:=sum[i];
      k:=i;
    end;
    
    readln;
  end;
  {for i:=1 to n do
    writeln(qimo[i],' ',pingshi[i],' ',ganbu[i],' ',xibu[i],' ',lunwen[i]);}
  writeln(a[k]);
  writeln(best);
  total:=0;
  for i:=1 to n do inc(total,sum[i]);
  writeln(total);
end;


begin
  init;
  readdata;
  main;
  outit;
end.

