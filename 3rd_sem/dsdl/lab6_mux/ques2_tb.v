`timescale 1ns/1ns
`include "ques2.v"
module ques2_tb();
reg [0:15] w;
reg [0:3] s;
wire f;
ques2 ques(w,s,f);
initial begin
	$dumpfile("ques2_tb.vcd");
	$dumpvars(0, ques2_tb);
	w=16'b1010101010101010; s=4'b1000; #20;
	w=16'b1000100010001000; s=4'b0000; #20;
	w=16'b1001100110011001; s=4'b1111; #20;
	w=16'b1111111110001000; s=4'b0001; #20;
	$display("Test Complete");
end
endmodule
