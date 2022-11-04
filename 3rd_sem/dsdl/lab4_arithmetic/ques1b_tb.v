`timescale 1ns/1ns
`include "ques1b.v"
module ques1b_tb();
reg x,y,cin;
wire sum,cout;
ques1 ques(x,y,sum,cin,cout);
initial begin 
	$dumpfile("ques1b_tb.vcd");
	$dumpvars(0, ques1b_tb);
	
	x=0; y=0; cin=0;
	#20;
	x=0; y=0;  cin=1;
	#20;
	x=0; y=1; cin=0;
	#20;
	x=0; y=1; cin=1;
	#20;
	
	x=1; y=0; cin=0;
	#20;
	x=1; y=0; cin=1;
	#20;
	x=1; y=1; cin=0;
	#20;
	x=1; y=1; cin=1;
	#20;
		$display("Test Complete");
		end
endmodule
