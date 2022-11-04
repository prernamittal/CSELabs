`timescale 1ns/1ns
`include "ques1a.v"
module ques1a_tb();
reg x,y;
wire sum,carry;
ques1 ques(x,y,sum,carry);
initial begin 
	$dumpfile("ques1a_tb.vcd");
	$dumpvars(0, ques1a_tb);
	x=0; y=0; 
	#20;
	x=0; y=1; 
	#20;
	x=1; y=0; 
	#20;
	x=1; y=1; 
	#20;
		$display("Test Complete");
		end
endmodule
