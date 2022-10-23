module ques2(w,s,f);
input [0:15]w;
output [0:3]s;
output f;
wire [0:3]m; 
mux4x1 mux1(w[0:3],s[1:0],m[0]);
mux4x1 mux1(w[4:7],s[1:0],m[1]);
mux4x1 mux1(w[8:11],s[1:0],m[2]);
mux4x1 mux1(w[12:15,s[1:0],m[3]);
mux4x1 mux1(m[0:3],s[3:2],f);
endmodule

module mux4x1(w,s,f);
input [0:3]w;
input[0:1]s;
output reg f;
always@(w or s)
f=s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
endmodule