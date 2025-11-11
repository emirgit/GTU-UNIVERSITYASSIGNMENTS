module Encoder2_4(input I0, input I1, input I2, input I3, output A1, output A0);
	assign A1 = I3 + I2;
	assign A0 = I3 + I1;

endmodule