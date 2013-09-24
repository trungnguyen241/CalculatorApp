library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ssdecoder is
	port( clk : in STD_LOGIC;
			data : in STD_LOGIC_VECTOR (7 downto 0);
			segout: out STD_LOGIC_VECTOR (6 downto 0));
end ssdecoder;

architecture Behavioral of ssdecoder is
	
begin

		with data select 
		segout <="1000010" when "00001101",
					"1100000" when "00010110",
					"0100100" when "00010101",
					"0110000" when "00011110",
					"1001100" when "00100100",
					"1111111" when others;
end Behavioral;

