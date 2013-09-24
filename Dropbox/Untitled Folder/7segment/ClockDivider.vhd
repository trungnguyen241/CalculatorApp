----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:34:30 09/12/2011 
-- Design Name: 
-- Module Name:    ClockDivider - Behavioral 
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

entity clkdiv is
	Port ( clk : in STD_LOGIC;
			 rst : in STD_LOGIC;
			 clkout : out STD_LOGIC);
end clkdiv;

--Set up clock divider 
architecture Behavioral of clkdiv is
	-- Set up frequency for clock divider to determine how fast refresh rate on seven segment will be
		constant cntendval : STD_LOGIC_VECTOR(17 downto 0) := "111100000000000000";
		signal cntval : STD_LOGIC_VECTOR (17 downto 0);
	
	begin
	process (clk, rst)
begin
	-- Stop when press the reset button, and keep going if reset is not being press.
	if rst = '1' then cntval <= "000000000000000000";
		elsif (clk'event and clk='1') then
	if (cntval = cntendval) then cntval <="000000000000000000";
		else cntval <= cntval + 1;
		end if;
		end if;
 end process;
 clkout <= cntval(17);
end Behavioral;