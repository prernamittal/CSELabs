module fourto2(w,y,z);
input [3:0]w;
output reg [1:0]y;
output reg z;
always@(w)
begin z=1;
casex(w)
4'b0000:z=0;
4'b0001:y=2'b00;
4'b001x:y=2'b01;
4'b01xx:y=2'b10;
4'b1xxx:y=2'b11;
endcase end
endmodule

module prio16to4(w,y,z);
input [15:0]w;
output reg [3:0]y;
output reg z;
integer i=0;
always@(w)
begin z=1;
for(i=15; i>=0; i=i-1)
begin
if(w[i]==1)
y=i;
end end
endmodule


