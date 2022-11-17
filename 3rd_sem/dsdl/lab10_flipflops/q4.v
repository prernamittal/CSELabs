module q4(in,out,clk,reset);
input [4:0]in;
input clk, reset;
output out;
q1 stage0(in[0],clk,reset,out[0]);
q1 stage1(in[1],clk,reset,out[1]);
q1 stage2(in[2],clk,reset,out[2]);
q1 stage3(in[3],clk,reset,out[3]);
q1 stage4(in[4],clk,reset,out[4]);
endmodule

//Register can be made using only D-type flip-Flops, one flip-Flop for each data bit.

module q1(d,clk,reset,q);
input d,clk,reset;
output reg q;
always@(posedge clk)
begin
if(!reset)
	q<=0;
else
	q<=d;
end
endmodule
