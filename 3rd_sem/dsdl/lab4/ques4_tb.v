`timescale 1ns/1ns
`include "ques4.v"
module ques4_tb();
reg [3:0] A,B;
reg C0;
wire [3:0] S;
wire C;
ques4 ques(S,C,A,B,C0);
initial begin 
	$dumpfile("ques4_tb.vcd");
	$dumpvars(0, ques4_tb);
	
	x=0011; y=0011; cin=0;
	#20;
	x=1011; y=0111;  cin=1;
	#20;
	x=1111; y=1111; cin=1;
	#20;
	
		$display("Test Complete");
		end
endmodule
