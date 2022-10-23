module mux2x1(w,s,f);
input [1:0]w;
input s;
output reg f;
always@(w or s)
begin
  if (s==0)
  f=w[0];
  else
  f=w[1];
end
endmodule

module ques1(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
wire [1:0]m;
mux2x1 mux1(w[1:0],s[0],m[0]);
mux2x1 mux2(w[3:2],s[0],m[1]);
mux2x1 mux3(m,s[0],f);
endmodule

