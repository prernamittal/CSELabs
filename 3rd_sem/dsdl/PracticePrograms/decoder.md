```
module twotofour(w,en,y);
input [1:0]w;
input en;
outputreg [0:3]y;
always@(w or en)
begin
y=4'b0000;
if(en==1)
begin
if(w==0)
y[0]=1;
if(w==1)
y[1]=1;
if(w==2)
y[2]=1;
if(w==3)
y[3]=1;
end end
endmodule

module twotofourfor(w,en,y);
input [1:0]w;
input en;
output reg [0:3]y;
integer k;
always@(w or en)
for(k=0;k<=3;k=k+1)
if((w==k)&&(en==1))
y[k]=1;
else y[k]=0;
endmodule

module twotofourswitch(w,en,y);
input [1:0]w;
input en;
output reg [0:3]y;
always@(w or en)
begin y=4'b0000;
if(en==1)
begin
case(w)
0:y[0]=1;
1:y[1]=1;
2:y[2]=1;
3:y[3]=1;
endcase
end end 
endmodule

module threeto8(w,en,y);
input [2:0]w;
input en;
output [0:7]y;
wire t1,t2;
assign t1=~w[2]&en;
assign t2=w[2]&en;
twotofour s0(w[1:0],t1,y[0:3]);
twotofour s1(w[1:0],t2,y[4:7]);
endmodule

module threeto8(w,en,y);
input [2:0]w;
input en;
output reg [0:7]y;
integer k;
always@(w or en)
for(k-0;k<=7;k=k+1)
if((w==k)&&(en==1))
y[k]=1;
else y[k]=0;
endmodule

module fourto16(w,en,y);
input [3:0]w;
input en;
output [0:15]y;
wire t1,t2;
assign t1=~w[3]&en;
assign t2=w[3]&en;
threeto8 s0(w[2:0],t1,y[0:7]);
threeto8 s1(w[2:0],t2,y[8:15]);
endmodule

```


