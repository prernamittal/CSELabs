module q2(w,en,y,f,g,h);
input [3:0]w;
input en;
output reg [15:0]y;
output f,g,h;
assign f=(y[3]|y[7]|y[10]|y[11]|y[14]);
assign g=(y[2]|y[3]|y[10]|y[14]);
assign h=(y[2]|y[3]|y[7]|y[14]|y[15]);
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
