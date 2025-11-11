module MUX(input A0, input A1, input S, output Y);
	assign Y = (A0 & ~S) + (A1 & S);
	
endmodule

module MUX4_1using2_1(input A0, input A1, input A2, input A3, input S0, input S1, output Y);

	wire [1:0] outwire;
	
	MUX mux1(A0, A1, S0, outwire[0]);
	MUX mux2(A2, A3, S0, outwire[1]);
	MUX muxlast(outwire[0], outwire[1], S1, Y);

endmodule