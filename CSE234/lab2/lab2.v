module HA(
	input A,
	input B,
	output SUM,
	output cout);
	
	assign SUM = A ^ B;
	assign cout = A & B;
	
endmodule

module FA(
	input a,
	input b,
	input cin,
	output sum,
	output cout);
	
	wire AxorB, AandB, bef;
	HA ha1(a, b, AxorB, AandB);
	HA ha2(AxorB, cin, sum, bef);
	
	assign cout = AandB | bef;
	
endmodule

module lab2(
	input [4:0] A,
	input [4:0] B,
	output [4:0] Result,
	output cout1
	);
	
	
	
	wire [3:0] c;
	FA Fa1(A[0], ~B[0], 1, Result[0], c[0]);
	FA Fa2(A[1], ~B[1], c[0], Result[1], c[1]);
	FA Fa3(A[2], ~B[2], c[1], Result[2], c[2]);
	FA Fa4(A[3], ~B[3], c[2], Result[3], c[3]);
	FA Fa5(A[4], ~B[4], c[3], Result[4], cout1);
	
endmodule