module MUX(input mux0, input mux1, input s, output o);
	assign o = (mux0 & ~s) | (mux1 & s);

endmodule





module lab3(input I0, input I1, input I2, input I3, input I4, input I5, input SEL0,
	output O0, output O1, output O2);
	
	
	wire [1:0] outs;
	
	
	nand nand1(outs[0], I0, I1, I2);
	nor nor1(outs[1], I3, I4, I5);
	MUX mux1(outs[0], outs[1], SEL0, O2);
	assign O0 = outs[0];
	assign O1 = outs[1];


endmodule