`timescale 1ns/1ns
`include "q2.v"
module q2_tb();
reg t,clk,reset;
wire q;
q2 ques(t,clk,reset,q);
initial begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	clk=0;
	forever #20 clk= (~clk);
end
initial begin
	t=1; reset=1;#20;
    	t=1; reset=0;#20;
    	t=0; reset=1;#20;
    	t=0; reset=0;#20;
    	t=1; reset=1;#20;
    	t=0; reset=1;#20;
    	$display("Test complete");
end
endmodule
