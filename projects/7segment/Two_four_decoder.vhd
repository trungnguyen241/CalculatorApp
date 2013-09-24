library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;
----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:41:20 09/12/2011 
-- Design Name: 
-- Module Name:    Two_four_decoder - Behavioral 
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
entity decoder is
port ( insignal: in std_logic_vector (1 downto 0);
		Y: out std_logic_vector (3 downto 0));
end decoder;
architecture behavioral of decoder is
Begin
			-- 0 is high and 1 is low for 2:4 Decoder since it's anode.
			-- Set up number 0 to 4. (1 to 4 are for start, stop, increment, reset and display nothing when no buttons are being press)
	with insignal select
Y <= "1110" when "00",
	  "1101" when "01",
     "1011" when "10",
     "0111" when "11",
	  "1111"	when others;
end behavioral;