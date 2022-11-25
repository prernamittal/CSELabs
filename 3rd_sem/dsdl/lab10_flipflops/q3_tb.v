`timescale 1ns/1ns
`include "q3.v"
module q3_tb();
reg j,k,clk,reset;
wire q;
q3 ques(j,k,clk,reset,q);
always #10 clk= (~clk);
initial begin
	clk=0;
	#80 $finish;
end
initial begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);
	j=1;k=1; reset=1;#20;
    	j=1;k=0;reset=0;#20;
    	j=0;k=1; reset=1;#20;
    	j=0;k=0;reset=0;#20;
    	j=1;k=1;reset=1;#20;
    	$display("Test complete");
end
endmodule
