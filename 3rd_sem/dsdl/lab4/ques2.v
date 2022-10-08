module ques2(cin,x,y,s,cout)
input cin;
input [3:0] x,y;
output [3:0] s;
output cout;
wire [3:1] c1;
wire [3:0] c2;
assign c2[0]=y[0]^cin;
assign c2[1]=y[1]^cin;
assign c2[2]=y[2]^cin;
assign c2[3]=y[3]^cin;
fulladd stage0(cin,x[0],c1[0],s[0],c1[1]);
fulladd stage1(c2[1],x[1],c1[1],s[1],c1[2]);
fulladd stage2(c2[2],x[2],c1[2],s[2],c1[3]);
fulladd stage3(c2[3],x[3],c1[3],s[3],cout);
endmodule

module fulladd(x,y,sum,cin,cout);
input x,y,cin;
output sum,cout;
assign sum=(x^y^cin);
assign cout=(x&y)|(x&cin)|(y&cin);
endmodule


