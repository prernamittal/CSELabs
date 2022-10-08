module ques1(x,y,sum,cin,cout);
input x,y,cin;
output sum,cout;
assign sum=(x^y^cin);
assign cout=(x&y)|(x&cin)|(y&cin);
endmodule


