program kk3;
const xx:array[1..4]of longint=(1,-1,2,-2);
      yy:array[1..4]of longint=(2,2,1,1);
type numtype=array[1..20]of longint;
     node=record l:longint; d:numtype; end;
var n,m,i,j,t,testtype,x1,x2,y1,y2:longint;
    a:array[1..100]of record x,y:longint; end;
    flag:boolean;
    f:array[-2..53,-2..53]of node;
procedure otry(k:longint);
var r,i,j,tx,ty:longint;
begin
      if (a[k].x=n) and (a[k].y=m)
       then begin
        flag:=true; exit;
       end;
      for r:=1 to 4 do begin
       tx:=a[k].x+xx[r];
       ty:=a[k].y+yy[r];
       if (tx>=1) and (tx<=n) and (ty>=1) and (ty<=m) then begin
        a[k+1].x:=tx; a[k+1].y:=ty;
        otry(k+1);
        if flag then exit;
       end;
      end;
end;
procedure add(var k1,k2:node);
var ti,tj:longint;
begin
      tj:=k1.l; if k2.l>tj then tj:=k2.l;
      for ti:=1 to tj do begin
       k1.d[ti+1]:=k1.d[ti+1]+(k1.d[ti]+k2.d[ti]) div 10;
       k1.d[ti]:=(k1.d[ti]+k2.d[ti]) mod 10;
      end;
      if k1.d[ti+1]<>0 then k1.l:=tj+1 else k1.l:=tj;
end;
begin
      while not eof do begin
          fillchar(f,sizeof(f),0);
          readln(n,m); readln(x1,y1,x2,y2);
          f[x1,y1].l:=1; f[x1,y1].d[1]:=1;
          for i:=x1+1 to x2 do
           for j:=1 to n do begin
            f[i,j].l:=f[i-yy[1],j-xx[1]].l;
            for t:=1 to f[i,j].l do f[i,j].d[t]:=f[i-yy[1],j-xx[1]].d[t];
            add(f[i,j],f[i-yy[2],j-xx[2]]);
            add(f[i,j],f[i-yy[3],j-xx[3]]);
            add(f[i,j],f[i-yy[4],j-xx[4]]);
            n:=n;
           end;
          if f[x2,y2].l>0
           then begin
            for i:=f[x2,y2].l downto 1 do write(f[x2,y2].d[i]);
            writeln;
           end
           else writeln(0);
         end;
end.
