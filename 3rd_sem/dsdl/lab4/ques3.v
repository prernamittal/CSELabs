module ques3(x,y,m);
input[1:0]x,y;
output[3:0]m;
wire[1:0]c1,b;
assign b[0]=x2[1]&y2[0];
assign a[0]=x2[0]&y2[1];
assign a[1]=x2[1]&y2[1];
assign m[0]=x2[0]&y2[0];
adder2 stage0(a,b,1'b0,m[2:1],p[3]);
endmodule

module adder2(x,y,cin,s,cout);
input[1:0]x,y;
input cin;
output [1:0]s;
output cout;
wire c1;
//incomplete
