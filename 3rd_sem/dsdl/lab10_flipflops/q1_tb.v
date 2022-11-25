`timescale 1ns/1ns
`include "q1.v"
module q1_tb();
reg d,clk,reset;
wire q;
q1 ques(d,clk,reset,q);
always #10 clk= (~clk);
initial begin	
	clk=0;
	#80 $finish;
end
initial begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	d=1; reset=1;#20;
    	d=1; reset=0;#20;
    	d=0; reset=1;#20;
    	d=0; reset=0;#20;
    	d=1; reset=1;#20;
    	d=0; reset=1;#20;
    	$display("Test complete");
end
endmodule
