`timescale 1ns/1ns
`include "q2.v"
module q2_tb();
reg [3:0]w;
reg en;
wire [15:0]y;
wire f,g,h;
q2 q(w,en,y,f,g,h);
initial begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	en=1;
	w=4'd0; #20;
	w=4'd1; #20;
	w=4'd2; #20;
	w=4'd3; #20;
	w=4'd4; #20;
	w=4'd5; #20;
	w=4'd6; #20;
	w=4'd7; #20;
	w=4'd8; #20;
	w=4'd9; #20;
	w=4'd10; #20;
	w=4'd11; #20;
	w=4'd12; #20;
	w=4'd13; #20;
	w=4'd14; #20;
	w=4'd15; #20;
	$display("Test Complete");
end
endmodule

	
