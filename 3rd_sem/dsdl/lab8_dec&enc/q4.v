module q4(w,y,z);
input [3:0]w;
output reg [1:0]y;
output reg z;
always@(w)
begin
z=1;
case(w)
4'b0001:y=0;
4'b001X:y=1;
4'b01XX:y=2;
4'bXXXX:y=3;
default: begin
	z=0;
	y=2'bXX;
	end
endcase
end
endmodule


