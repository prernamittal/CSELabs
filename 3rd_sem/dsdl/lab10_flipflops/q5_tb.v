`timescale 1ns/1ns
`include "q5.v"
module q5_tb();
reg in,clk,reset;
wire out;
q5 ques(in,out,clk,reset);
always #10 clk= (~clk);
initial begin
	clk=0;
	#80 $finish;
end
initial begin
	$dumpfile("q5_tb.vcd");
	$dumpvars(0,q5_tb);
	in=1; reset=1;#15;
	in=0; reset=1;#20;
	in=0; reset=1;#20;
	in=1; reset=1;#20;
	in=1; reset=1;#15;    	
	$display("Test complete");
end
endmodule
