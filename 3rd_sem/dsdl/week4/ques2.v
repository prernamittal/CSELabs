module ques2(cin,x,y,s,cout)
input cin;
input [3:0] x,y;
output [3:0] s;
output cout;
wire [3:1] c;
fulladd stage0(cin,x[0],y[0],s[0],c[1]);
fulladd stage1(c[1],x[1],y[1],s[1],c[2]);
fulladd stage2(c[2],x[2],y[2],s[2],c[3]);
fulladd stage3(c[3],x[3],y[3],s[3],cout);
endmodule

module fulladd(x,y,sum,cin,cout);
input x,y,cin;
output sum,cout;
assign sum=(x^y^cin);
assign cout=(x&y)|(x&cin)|(y&cin);
endmodule


