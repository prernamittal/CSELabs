module ques3(w,s,f);
input [0:15]w;
input [0:3]s;
output f;
wire [0:1]m;
mux8x1 mux1(w[0:7],s[0:2],m[0]);
mux8x1 mux2(w[8:15],s[0:2],m[1]);
mux2x1 mux3(m,s[3],f);
endmodule

module mux8x1(w,s,f);
input [0:7]w;
input [0:2]s;
output reg f;
always @(w or s)
case(s)
000: f=w[0];
001: f=w[1];
010: f=w[2];
011: f=w[3];
100: f=w[4];
101: f=w[5];
110: f=w[6];
111: f=w[7];
endcase
endmodule

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




