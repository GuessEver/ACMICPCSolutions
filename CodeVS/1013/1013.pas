program rqnoj;

var
  zhong,hou:string;

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
  readln(zhong);
  readln(hou);
end;

procedure tree(zhong,hou:string);
var
  r:string;
  k,len:longint;
begin
  if zhong<>'' then
  begin
    len:=length(zhong);
    r:=hou[len];
    k:=pos(r,zhong);
    write(hou[len]);
    tree(copy(zhong,1,k-1),copy(hou,1,k-1));
    tree(copy(zhong,k+1,len-k),copy(hou,k,len-k));
  end;

end;

procedure main;
begin
  tree(zhong,hou);
end;

begin
  init;
  readdata;
  main;
  outit;
end.
