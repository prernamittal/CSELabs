module ques1c(x,y,sum,cin,cout);
input x,y,cin;
output sum,cout;
halfadd stage0 (x, y, s, c1);
halfadd stage1 (s, cin, sum, c2);
or(cout,c1,c2);
endmodule

module halfadd(xi,yi,sumi,carryi);
input xi,yi;
output sumi,carryi;
assign sumi=(xi^yi);
assign carryi=(xi&yi);
endmodule


