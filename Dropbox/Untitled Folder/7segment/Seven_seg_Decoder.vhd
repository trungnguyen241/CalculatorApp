----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:57:36 09/12/2011 
-- Design Name: 
-- Module Name:    Seven_seg_Decoder - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Seven_seg_Decoder is
	port( --LED3_in: in STD_LOGIC;
			--LED3_out: out STD_LOGIC;
			bin : in STD_LOGIC_VECTOR (3 downto 0);
			segout: out STD_LOGIC_VECTOR (6 downto 0));
		
end Seven_seg_Decoder;

architecture Behavioral of Seven_seg_Decoder is
begin

-- Set up numbers to show on seven segment
	with bin select
					-- 0 is high and 1 is low for Seven Segment decoder since it's anode.
					-- Set up number 0 to 9.
 
		segout <="0000001" when "0000",
					"1001111" when "0001",
					"0010010" when "0010",
					"0000110" when "0011",
					"1001100" when "0100",
					"0100100" when "0101",
					"0100000" when "0110",
					"0001111" when "0111",
					"0000000" when "1000",
					"0000100" when "1001",
					"1111111" when others;
end Behavioral;

