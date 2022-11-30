module fivebitreg(in, clk, reset,out);
input [4:0]in;
input clk,reset;
output [4:0]out;
dff s0(in[4],clk,reset,out[4]);
dff s0(in[3],clk,reset,out[3]);
dff s0(in[2],clk,reset,out[2]);
dff s0(in[1],clk,reset,out[1]);
dff s0(in[0],clk,reset,out[0]);
endmodule

module sixshiftreg(in,clk,out);
input in;
input clk;
output out;
wire [4:0]t;
dff s0(inp,clk,t[4]);
dff s1(t[4],clk,t[3]);
dff s1(t[3],clk,t[2]);
dff s1(t[2],clk,t[1]);
dff s1(t[1],clk,t[0]);
dff s1(t[0],clk,out);
endmodule

module twobitcounter(clk,reset,out);
input clk,reset;
output [0:1]out;
dff s0(~out[1],clk,reset,out[1]);
dff s1(~out[0],~out[1],reset,out[0]);
endmodule

module ringcounter(clk,reset,q);
input clk,reset;
output[0:3]q;
wire [1:0]t;
twobitcounter c(clk,reser,t);
twotofour d(t,1'b1,q);
endmodule

module johnsoncounter(clk,reset,q);
input clk,reset;
output[4:0]q;
dff s0(~q[0],clk,reset,q[4]);
dff s1(q[4],clk,reset,q[3]);
dff s2(q[3],clk,reset,q[2]);
dff s3(q[2],clk,reset,q[1]);
dff s4(q[1],clk,reset,q[0]);
endmodule
