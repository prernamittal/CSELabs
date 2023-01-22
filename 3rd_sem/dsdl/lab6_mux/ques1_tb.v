`timescale 1ns/1ns
`include "ques1.v"
module ques1_tb();
reg [3:0]w;
reg [1:0]s;
wire f;
ques1 ques(w,s,f);
initial begin
	$dumpfile("ques1_tb.vcd");
	$dumpvars(0, ques1_tb);
	w=0001; s=00; #20;
	w=0010; s=01; #20;
	w=0100; s=10; #20;
	w=1000; s=11; #20;
	$display("Test Complete");
end
endmodule
