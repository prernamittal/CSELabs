module ques2a(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=((c|d)&(b|c)&(~b|~c|d));
endmodule