module full_adder(
    input a, 
    input b, 
    input cin, 
    output sum, 
    output cout
    );
    
	 wire abxor;
	 
	 assign abxor = a ^ b;
    assign sum = abxor ^ cin;
    assign cout = (abxor & cin) | (a & b);
    
endmodule

module fullAdder(
    input [3:0] A, 
    input [3:0] B, 
	 input cin,
    output [3:0] SUM, 
    output cout
    );
    
    wire c1, c2, c3;
    
    full_adder FA1(A[0], B[0], cin, SUM[0], c1);
    full_adder FA2(A[1], B[1], c1, SUM[1], c2);
    full_adder FA3(A[2], B[2], c2, SUM[2], c3);
    full_adder FA4(A[3], B[3], c3, SUM[3], cout);
    
endmodule

module fullsubtractor(
    input [3:0] A, 
    input [3:0] B, 
	 input S,
    output [3:0] SUB, 
    output cout
    );
	 
	 wire [3:0] Bxor;
	 
	 xor not1(Bxor[0], S, B[0]);
	 xor not2(Bxor[1], S, B[1]);
	 xor not3(Bxor[2], S, B[2]);
	 xor not4(Bxor[3], S, B[3]);
	 
	 fullAdder(A, Bxor, S, SUB, cout);
	 
endmodule