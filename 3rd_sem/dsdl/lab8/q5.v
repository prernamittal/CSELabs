module q5(w,y,z);
input [15:0]w;
output reg [3:0]y;
output reg z;
integer i=0;
always@(w)
begin
z=1;
for(i=15;i>-1;i=i-1)
begin
if(w[i]==1)
y=i;
end
end
endmodule


