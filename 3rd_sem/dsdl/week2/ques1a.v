module ques1a(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=((c&d)|(~a&b)|(~b)&c|b&(~c)&(~d));
endmodule