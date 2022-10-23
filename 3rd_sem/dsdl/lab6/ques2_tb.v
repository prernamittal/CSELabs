`timescale 1ns/1ns
`include "ques2.v"
module ques2_tb();
reg a, b, c, d, s0, s1;
wire out;
ques2 ques2(a, b, c, d, s0, s1, out);
initial begin
	$dumpfile("ques2_tb.vcd");
	$dumpvars(0, ques2_tb);
	a=1010101010101010; s=1000; #20;
	a=1000100010001000; s=0000; #20;
	a=1001100110011001; s=1111; #20;
	a=1111111110001000; s=0001; #20;
	$display("Test Complete");
end
endmodule
