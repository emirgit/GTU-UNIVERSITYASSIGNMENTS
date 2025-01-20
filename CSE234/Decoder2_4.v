module Decoder2_4(input A1, input A0, output I0, output I1, output I2, output I3);
	
	assign I0 = ~A1 + ~A0;
	assign I1 = ~A1 + A0;
	assign I2 = A1 + ~A0;
	assign I3 = A1 + A0;
	
endmodule