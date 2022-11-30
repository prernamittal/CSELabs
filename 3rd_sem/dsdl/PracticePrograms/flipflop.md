module dff(d,clk,reset,q);
input d,clk,reset;
output reg q;
always@(posedge clk or posedge reset)
if(!reset)
q<=d;
else
q<=0;
endmodule

module tff(t,clk,reset,q);
input t,clk,reset;
output reg q;
always@(negedge clk or negedge reset)
if(!reset)
q<=0;
else if(t)
q<=(~q);
endmodule

module jkff(j,k,clk,reset,q);
input j,k,clk,reset;
output reg q;
always@(posedge clk)
if(!reset)
q<=0;
else begin
if((j==0)&&(k==0))
q<=q;
else if((j==0)&&(k==1))
q<=0;
else if((j==1)&&(k==0))
q<=q;
else
q=~q;
end end 
endmodule

