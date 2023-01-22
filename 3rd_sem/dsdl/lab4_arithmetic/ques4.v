module ques4(S, C, A, B, C0);
input [3:0] A, B;
input C0;
output [3:0] S;
output C;
wire C1, C2, C3, C4, C5;
wire [3:0]X, Z;
and (C1, Z[3], Z[2]);
and (C2, Z[3], Z[1]);
or (C, C3, C1,C2);
xor (C5, C, C);
assign X[2] = C;
assign X[1] = C;
assign X[3] = C5;
assign X[0] = C5;
adder4 stage0(Z,C3,A,B,C0);
adder4 stage1(S,C4,X,Z,C0);
endmodule

module adder4(S, C, A, B, C0);
input C0;
input [3:0] A, B;
output [3:0] S;
output C;
wire [3:1] c1;
wire [3:0] c2;
assign c2[0]=B[0]^C;
assign c2[1]=B[1]^C;
assign c2[2]=B[2]^C;
assign c2[3]=B[3]^C;
fulladd stage0(C[0], c1[0], A[0], S[0], c1[1]);
fulladd stage1(c2[1],c1[1],A[1],S[1],c1[2]);
fulladd stage2(c2[2],c1[2],A[2],S[2],c1[3]);
fulladd stage3(c2[3],c1[3],A[3],S[3],cout);
endmodule

module fulladd(S, C, A, B, C0);
input A, B, C0;
output S, C;
assign S = A ^ B ^ C0;
assign C = (A & B) | (A & C0) | (B & C0);
endmodule
