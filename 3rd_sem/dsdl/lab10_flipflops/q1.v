module q1(d,clk,reset,q);
input d,clk,reset;
output reg q;
always@(posedge clk or posedge reset)
begin
if(!reset)
	q<=d;
else
	q<=0;
end
endmodule
