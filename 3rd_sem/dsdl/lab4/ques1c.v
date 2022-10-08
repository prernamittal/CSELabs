module ques1c(x,y,sum,cin,cout);
input x,y,cin;
output sum,cout;
wire s1,c1,c2;
halfadd stage0 (s1,c1,x,y);
halfadd stage1 (sum,c2,s1,cin);
or (cout,c2,c1);
endmodule

module halfadd(x,y,sum,carry);
input x,y;
output sum,carry;
assign sum=(x^y);
assign carry=(x&y);
endmodule


