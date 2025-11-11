module MUX2_1(input A0, input A1, input S, output Y);
	assign Y = (A0 & ~S) + (A1 & S);
	
endmodule