module q2(t,clk,reset,q);
input t,clk,reset;
output reg q;
always@(negedge clk or negedge reset)
begin
if(!reset)
	q<=0;
else if (t)
	q<=(~q);
else
	q<=q;
end
endmodule
