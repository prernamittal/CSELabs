`timescale 1ns/1ns
`include "ques3.v"
module ques3_tb();
wire f;
reg [15:0]w;
reg [3:0]s;
ques3 ques3(w,s,f);
initial begin
	$dumpfile("ques3_tb.vcd");
	$dumpvars(0, ques3_tb);
	w=1010101010101010; s=0000; #20;
	w=1010100000101010; s=1110; #20;
	w=1111111010101010; s=0110; #20;
	w=1010101010111111; s=1001; #20;	
	$display("Test Complete");
end
endmodule
