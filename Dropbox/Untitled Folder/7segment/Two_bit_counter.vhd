----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:37:31 09/12/2011 
-- Design Name: 
-- Module Name:    Two_bit_counter - Behavioral 
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
entity counter is
Port ( clk : in STD_LOGIC;
rst : in STD_LOGIC;
B : inout STD_LOGIC_VECTOR (1 downto 0));
end counter;
architecture Behavioral of counter is
begin
process (clk, rst)
begin
if rst = '1' then B <= "00";
elsif (clk'event and clk='1') then
B <= B + 1;
end if;
end process;
end Behavioral;