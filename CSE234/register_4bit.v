module MUX(input load, output Y);
	assign Y = load ? 1 : 0;
endmodule

module register_4bit(input clk, input load, input [3:0] I, output reg [3:0] Q);
	wire out;
	//assign out = load ? 1 : 0;
	MUX(load, out);
	
	always @(posedge clk or posedge out)
	begin	
		Q <= I;
	end
	
endmodule

