module ques2(a,b,c,d,f)
input a,b,c,d;
output f;
nor(a1,a,a);
nor(b1,b,b);
nor(c1,c,c);
nor(d1,d,d);
nor(e,b1,d);
nor(g,c1,d1);
nor(h,a1,b1);
nor(f,e,g,h);
endmodule
