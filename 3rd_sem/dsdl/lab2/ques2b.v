module ques2b(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=((a|~c|d)&(~b|c|d)&(~a|b|~d)&(b|~c|d));
endmodule