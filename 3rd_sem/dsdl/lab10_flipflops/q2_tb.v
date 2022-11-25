`timescale 1ns/1ns
`include "q2.v"
module q2_tb();
reg t,clk,reset;
wire q;
q2 ques(t,clk,reset,q);
always #10 clk= (~clk);
initial begin
	clk=0;
	#80 $finish;
end
initial begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	t=1; reset=0;#15;
    	t=1; reset=1;#15;
    	t=0; reset=1;#20;
    	t=1; reset=1;#30;
    	$display("Test complete");
end
endmodule
