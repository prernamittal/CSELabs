`timescale 1ns/1ns
`include "ques2.v"
module ques1_tb();
reg a,b,c,d;
wire f;
ques2 ques(a,b,c,d,f);
initial begin
    $dumpfile("ques2_tb.vcd");
    $dumpvars(0,ques2_tb);
    a=0;b=0;c=0;d=0;
    #20;
    a=0;b=0;c=0;d=0;
    #20;
    a=0;b=0;c=1;d=1;
    #20;
    a=0;b=0;c=1;d=0;
    #20;
    a=0;b=1;c=0;d=1;
    #20;
    a=0;b=1;c=0;d=0;
    #20;
    a=0;b=1;c=1;d=1;
    #20;
    a=0;b=1;c=1;d=0;
    #20;

    a=1;b=0;c=0;d=1;
    #20;
    a=1;b=0;c=0;d=0;
    #20;
    a=1;b=0;c=1;d=1;
    #20;
    a=1;b=0;c=1;d=0;
    #20;
    a=1;b=1;c=0;d=1;
    #20;
    a=1;b=1;c=0;d=0;
    #20;
    a=1;b=1;c=1;d=1;
    #20;
    a=1;b=1;c=1;d=0;
    #20;
        $display("Test Completed");
end
endmodule
