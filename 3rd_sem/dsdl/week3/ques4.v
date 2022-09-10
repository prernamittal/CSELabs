module ques4(a,b,c,d,f)
input a,b,c,d;
output f;
nor(a1,a,a);
nor(c1,c,c);
nor(e,a1,c1);
nor(f,d,e);
endmodule
