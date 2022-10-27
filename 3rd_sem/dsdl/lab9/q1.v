module q1(w,en,y,f);
input [3:0]w;
input en;
output reg [15:0]y;
output f;
assign f=(y[1]|y[3]|y[6]|y[7]|y[9]|y[14]|y[15]);
integer k;
always@(w or en)
begin
for(k=0;k<=15;k=k+1)
if ((w==k)&&(en==1))
	y[k]=1;
else
	y[k]=0;
end
endmodule
