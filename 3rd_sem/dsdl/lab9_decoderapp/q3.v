module q3(w,f);
input [2:0]w;
output f;
wire [3:0]y;
dec stage0(w[2:1],1'b1,y);
and(t1,w[0],y[1]);
and(t2,y[1],y[2]);
and(t3,w[0],y[2]);
or(f,t1,t2,t3,y[3]);
endmodule

module dec(w,en,y);
input [1:0] w;
input en;
output reg [3:0] y;
integer k;
always @(w or en)
for (k=0;k<=3;k=k+1)
    if((w==k)&&(en==1))
        y[k] = 1;
    else
        y[k] = 0;
endmodule 
