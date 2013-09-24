----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:26:28 09/14/2011 
-- Design Name: 
-- Module Name:    Sixteen_counter - Behavioral 
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
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Sixteen_counter2 is
 port( 
		clk, en : in std_logic; 
		compare, start : out std_logic_vector (3 downto 0));
		
 end Sixteen_counter2;
 
architecture Behavioral of Sixteen_counter2 is
		signal compare_int : std_logic_vector (3 downto 0) := "0000";
		
 begin
	process (clk, en) 
		begin -- process bcd_counting 
			if en = '1' then -- asynchronous reset (active high) 
				compare <= ( others => '0'); 
				 
			elsif clk'event and clk = '1' then -- rising clock edge 
			if compare_int = "1001" then 
				compare_int <= "0000";  
			else 
				compare_int <= compare_int + '1'; 
			end if; 
			end if; 
		end process; 
			 
				 compare <= compare_int;
			 
		end Behavioral; 