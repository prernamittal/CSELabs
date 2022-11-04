`timescale 1ns/1ns
`include "ques2.v"
module ques2_tb();
reg [3:0] x,y;
reg cin;
wire [3:0] sum;
wire cout;
ques2 ques(x,y,sum,cin,cout);
initial begin 
	$dumpfile("ques2_tb.vcd");
	$dumpvars(0, ques2_tb);
	
	x=0011; y=0011; cin=0;
	#20;
	x=1011; y=0111;  cin=1;
	#20;
	x=1111; y=1111; cin=1;
	#20;
	
		$display("Test Complete");
		end
endmodule
