
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module lab5(

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
	counter ct1(CLOCK_50, cnt);
	
	seqcir sc1(cnt[25], out);
	
	assign LEDR[3:0] = out;
endmodule

module seqcir(input clk, output [3:0] o);

	reg [2:0] s;
	wire [2:0] n;
	
	//State register
	always @(posedge clk)
	begin	
		s <= n;	
	end

	//combinational circuit
	assign n[0] = (~s[0] & ~s[1]) | (~s[0] & ~s[2]);
	assign n[1] = (s[0] & ~s[1] & ~s[2]) | (~s[0] & s[1] & ~s[2]);
	assign n[2] = (s[0] & s[1] & ~s[2]) | (~s[0] & ~s[1] & s[2]);
	
	assign o[0] = (~s[0] & ~s[1] & s[2]) | (s[0] & ~s[1] & s[2]);
	assign o[1] = (~s[0] & s[1] & ~s[2]) | (s[0] & ~s[1] & s[2]) | (s[0] & s[1] & ~s[2]);
	assign o[2] = (~s[0] & ~s[1] & ~s[2]) | (s[0] & ~s[1] & ~s[2]) | (s[0] & s[1] & ~s[2]) | (~s[0] & ~s[1] & s[2]);
	assign o[3] = s[0] | s[1] | s[2];
	
endmodule

module counter(input clk, output reg[31:0] count);
	
	always @(posedge clk)
	begin
		count = count + 32'b1;
	end
	
endmodule