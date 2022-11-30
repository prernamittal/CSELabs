```module mux2x1(w,s,f);
input [1:0]w;
output reg f;
always@(w or s)
begin
  if (s==0)
  f=w[0];
  else
  f=w[1];
end
endmodule

module mux4x1(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
wire[1:0]m;
mux2x1 s0(w[1:0],s[0],m[0]);
mux2x1 s1(w[3:2],s[0],m[1]);
mux2x1 s2(m,s[1],f);
endmodule

module mux16x1(w,s,f);
input [15:0]w;
input [3:0]s;
output f;
wire [3:0]m;
mux4x1 s0(w[3:0],s[1:0],m[0]);
mux4x1 s1(w[7:4],s[1:0],m[1]);
mux4x1 s2(w[11:8],s[1:0],m[2]);
mux4x1 s3(w[15:12],s[1:0],m[3]);
mux4x1 s4(m,s[3:2],f);
endmodule

module mux16x1alt(w,s,f);
input [15:0]w;
input [3:0]s;
output f;
wire [1:0]m;
mux8x1 s0(w[7:0],s[2:0],m[0]);
mux8x1 s1(w[15:8],s[2:0],m[1]);
mux2x1 s2(m,s[3],f);

module mux8x1(w,s,f);
input [7:0]w;
output reg [2:0]f;
always@(w or s)
case(s)
0:f=w[0];
1:f=w[1];
2:f=w[2];
..............
7:f=w[7];
endcase
endmodule

\\mux using 3 to 8 decoder
mux8x1dec(w,s,f);
input [7:0]w;
input[2:0]s;
output f;
wire [0:7]y;
threeto8 s0(s,1'b1,y);
and(t1,y[1],w[1]);
..................
and(t8,y[8],w[8]);
or(t1,t2,t3,.....t9);
endmodule
```