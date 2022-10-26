`timescale 1ns/1ns
`include "q5.v"
module q5_tb();
reg [15:0]w;
wire [3:0]y;
q5 ques(w,y,z);
initial begin
	$dumpfile("q5_tb.vcd");
	$dumpvars(0,q5_tb);
	w=0001000000000000; #20;
	w=0010000000000000; #20;
	w=0100000000000000; #20;
	w=1000000000000000; #20;	
	$display("Test Complete");
end
endmodule

