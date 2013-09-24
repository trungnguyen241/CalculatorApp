----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:11:53 09/12/2011 
-- Design Name: 
-- Module Name:    Four_Four_mux - Behavioral 
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

entity Four_Four_mux is
	port (i3,i2,i1,i0: in std_logic_vector (3 downto 0);
			sel	 :in std_logic_vector (1 downto 0);
			Y 		 :out std_logic_vector (3 downto 0));
end Four_Four_mux;
	-- Set up mux that switches logic signals
architecture Behavioral of Four_Four_mux is 

begin
	with sel select
	 Y<=  i0 when "00",
			i1 when "01",
			i2 when "10",
			i3 when others;
end Behavioral;

