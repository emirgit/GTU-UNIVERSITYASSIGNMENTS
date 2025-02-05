
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module LabFinal(

	//////////// CLOCK //////////
	input 		          		CLOCK_50,

	//////////// KEY //////////
	input 		     [3:0]		KEY,

	//////////// LED //////////
	output		     [9:0]		LEDR,

	//////////// SW //////////
	input 		     [9:0]		SW
);

	wire [3:0] out;
	wire [31:0] cnt;
	register_4bit(cnt[25], ~KEY[1], ~KEY[0], SW[9:6], out);
	assign LEDR[3:0] = out;
	
	counter ct1(CLOCK_50, cnt);

endmodule

/*

module register_4bit(input clk, input s1, input s0, input [3:0] I, output reg [3:0] Q);
	wire [3:0] out;
	
	//4bit
	MUX(s1, s0, 0, Q[2], I[3], out[3]);
	register_1bit(clk, out[0], Q[0]);
	
	MUX(s1, s0, Q[2], Q[1], I[2], out[2]);
	register_1bit(clk, out[1], Q[1]);

	MUX(s1, s0, Q[1], Q[0], I[1], out[1]);
	register_1bit(clk, out[2], Q[2]);
	
	MUX(s1, s0, Q[0], Q[2], I[0], out[0]);
	register_1bit(clk, out[3], Q[3]);
	
endmodule

module MUX(input s1, input s0, input A, input B, input C, input D, input load, output Y);
	assign out = s1 ?  (s0 ?  A : B)  : (s0 ? C : D); 
	
endmodule

*/
module register_4bit(input clk, input s1, input s0, input [3:0] I, output reg [3:0] Q);
	wire [3:0]out;
	wire [3:0] shr;
	wire [3:0] shl;
	
	
	MUX(s1, s0, Q[2])
	register_1bit()
	
	shift_r(Q, shr);
	shift_l(Q, shl);
	MUX(s1, s0, shr, shl, I, Q, out);
	
	always @(posedge clk)
	begin	
		Q <= out;
	end
	
endmodule

module MUX(input s1, input s0, input [3:0] shr, input [3:0] shl, input [3:0] I, input [3:0] Q, output [3:0] out);
	assign out = s1 ?  (s0 ?  shr : shl)  : (s0 ? I : Q); 
endmodule

module counter(input clk, output reg[31:0] count);
	
	always @(posedge clk)
	begin
		count = count + 32'b1;
	end
endmodule

module register_1bit(input clk, input I, input shr, input shl, output reg Q);

	
	
	always @(posedge clk)
	begin	
		Q <= I;
	end

end module


module shift_r(input [3:0] I, output [3:0] out);
	
	assign out[0] = I[1];
	assign out[1] = I[2];
	assign out[2] = I[3];
	assign out[3] = 0;
endmodule

module shift_l(input [3:0] I, output [3:0] out);
	
	assign out[0] = 0;
	assign out[1] = I[0];
	assign out[2] = I[1];
	assign out[3] = I[2];
endmodule
	