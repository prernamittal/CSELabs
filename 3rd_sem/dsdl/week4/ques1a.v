module ques1a(x,y,sum,carry);
input x,y;
output sum,carry;
assign sum=(x^y);
assign carry=(x&y);
endmodule


