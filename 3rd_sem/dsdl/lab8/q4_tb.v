`timescale 1ns/1ns
`include "q4.v"
module q4_tb();
reg [3:0]w;
wire [1:0]y;
q4 ques(w,y,z);
initial begin
	$dumpfile("q4.vcd");
	$dumpvars(0,q4_tb);
	w=0001; #20;
	w=0010; #20;
	w=0100; #20;
	w=1000; #20;	
	$display("Test Complete");
end
endmodule

