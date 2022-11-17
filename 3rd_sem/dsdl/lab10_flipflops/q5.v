module q5(in,out,clk,reset);
input in;
input clk, reset;
output out;
wire [4:0]t;
q1 stage0(in,clk,reset,t[0]);
q1 stage1(t[0],clk,reset,t[1]);
q1 stage2(t[1],clk,reset,t[2]);
q1 stage3(t[2],clk,reset,t[3]);
q1 stage4(t[3],clk,reset,t[4]);
q1 stage4(t[4],clk,reset,out);
endmodule

//Shift Register can be made using only D-type flip-Flops, one flip-Flop for each data bit.

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
