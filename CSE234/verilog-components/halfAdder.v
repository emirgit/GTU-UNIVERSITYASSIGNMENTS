module HA(
	input A,
	input B,
	output SUM,
	output COUT);
	
	assign SUM = A ^ B;
	assign COUT = A & B;
	
endmodule
	

module full_adder(
    input a, 
    input b, 
    input cin, 
    output sum, 
    output cout
    );
    
	 wire SUM, COUT, lastco;
	 HA half1(a, b, SUM, COUT);
	 HA half2(SUM, cin, sum, lastco);
    assign cout = lastco | COUT;
    
endmodule

module halfAdder(
    input [3:0] A, 
    input [3:0] B, 
	 //input cin;
    output [3:0] SUM, 
    output cout
    );
    
    wire c1, c2, c3;
    
	 //1 bit with value 0 means = 1'b0
    full_adder FA1(A[0], B[0], 1'b0/*cin*/, SUM[0], c1);
    full_adder FA2(A[1], B[1], c1, SUM[1], c2);
    full_adder FA3(A[2], B[2], c2, SUM[2], c3);
    full_adder FA4(A[3], B[3], c3, SUM[3], cout);
    
endmodule