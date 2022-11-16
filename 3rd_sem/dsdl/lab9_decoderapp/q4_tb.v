`timescale 1ns/1ns
`include "q4.v"
module q4();
reg [7:0] w;
reg [2:0] s;
wire f;
q4 ques(w,s,f);
initial begin 
    $dumpfile("q4_tb.vcd");
    $dumpvars(0,q4_tb);
    w = 8'd50; 
    s = 3'd1;#20;
    s = 3'd0;#20;
    s = 3'd6;#20;
    s = 3'd5;#20;
    $display("Test Complete");
end
endmodule