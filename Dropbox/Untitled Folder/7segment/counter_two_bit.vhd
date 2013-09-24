----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:37:31 09/12/2011 
-- Design Name: 
-- Module Name:    counter_two_bit - Behavioral 
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
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity counter_two_bit is
		Port ( clk : in STD_LOGIC;
				 rst : in STD_LOGIC;
				 B : inout STD_LOGIC_VECTOR (1 downto 0));
end counter_two_bit;
-- Set up 2-bit counter for storing the number of time the event has occur 
architecture Behavioral of counter_two_bit is
	begin
	 process (clk, rst)
	  begin
		if rst = '1' then B <= "00";
		elsif (clk'event and clk='1') then
			B <= B + 1;
	end if;
  end process;
end Behavioral;