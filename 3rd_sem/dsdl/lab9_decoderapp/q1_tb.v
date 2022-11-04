`timescale 1ns/1ns
`include "q1.v"
module q1_tb();
reg [3:0]w;
reg en;
wire [15:0]y;
wire f;
q1 q(w,en,y,f);
initial begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	en=1;
	w=4'b0011; #20;
	w=4'b0101; #20;
	w=4'b0110; #20;
	w=4'b1001; #20;
	$display("Test Complete");
end
endmodule

	
