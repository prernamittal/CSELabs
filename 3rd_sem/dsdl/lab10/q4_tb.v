`timescale 1ns/1ns
`include "q4.v"
module q4_tb();
reg [4:0]in;
reg clk,reset;
wire [4:0]out;
q4 ques(in,out,clk,reset);
initial begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	clk=0;
	forever #20 clk= (~clk);
end
initial begin
	in=5'd1; reset=1;#20;
    	in=5'd10; reset=0;#20;
    	in=5'd5; reset=1;#20;
    	in=5'd3; reset=0;#20;
    	in=5'd12; reset=1;#20;
    	in=5'd7; reset=1;#20;
    	$display("Test complete");
end
endmodule
