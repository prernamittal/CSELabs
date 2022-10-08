module ques1(a,b,c,d,f)
input a,b,c,d;
output f;
nand(a1,a,a);
nand(b1,b,b);
nand(c1,c,c);
nand(d1,d,d);
nand(e,a1,c);
nand(g,b,c1);
nand(h,a1,d);
nand(i,b,d);
nand(f,e,g,h,i);
endmodule
