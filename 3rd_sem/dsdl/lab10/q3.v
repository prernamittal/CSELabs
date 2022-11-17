module q3(j,k,clk,reset,q);
input j,k,clk,reset;
output reg q;
always@(posedge clk)
begin
if(!reset)
	q<=0;
else
begin
	if((j==0)&&(k==0))
		q<=q;
	else if((j==0)&&(k==1))
		q<=0;
	else if((j==1)&&(k==0))
		q<=q;
	else
		q=(~q);
	
end
end
endmodule
