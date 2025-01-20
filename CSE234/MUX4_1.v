module Decoder(input A1, input A0, output I0, output I1, output I2, output I3);
	
	assign I0 = ~A1 + ~A0;
	assign I1 = ~A1 + A0;
	assign I2 = A1 + ~A0;
	assign I3 = A1 + A0;
	
endmodule

module MUX4_1(input I0, input I1, input I2, input I3, input S0, input S1, output Y);
	wire [3:0] outs;
	Decoder(S1, S0, outs[0], outs[1], outs[2], outs[3]);
	
	assign Y = (I0 & outs[0]) | (I1 & outs[1]) | (I2 & outs[2]) | (I3 & outs[3]);

endmodule