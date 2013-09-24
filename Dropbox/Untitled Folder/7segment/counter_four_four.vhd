----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:30:35 09/12/2011 
-- Design Name: 
-- Module Name: 	counter_four_four - Behavioral 
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

entity counter_four_four is
	Port ( clkin : in STD_LOGIC;
			 rst : in STD_LOGIC;
			 en_in : in STD_LOGIC;
			 Dig0,Dig1,Dig2,Dig3 : inout STD_LOGIC_VECTOR (3 downto 0)
);

	end counter_four_four;

architecture Behavioral of counter_four_four is
		signal c0,c1,c2,c3 : STD_LOGIC_VECTOR (3 downto 0):= "0000";
	-- Set up 4x4 counter to start numbers at 0 again after it get to 9
  begin
	process (clkin, rst,en_in,c0,c1,c2,c3)
	begin
		if rst = '1' then
		c0 <= "0000";
		c1 <= "0000";
		c2 <= "0000";
		c3 <= "0000";

   elsif( en_in = '1' and rst = '0') then
    if (clkin'event and clkin='1' ) then
	  c0 <= c0 + 1;
   
	 if(c0 = "1001") then c0 <= "0000";
	  c1 <= c1 + 1;

    if(c1 = "1001") then c1 <= "0000";
 	  c2 <= c2 + 1;

    if(c2 = "1001") then c2 <= "0000";
	  c3 <= c3 + 1;

    if(c3 = "1001") then c3 <= "0000";
		end if;
		end if;	
		end if;
		end if;
		end if;
	
	 else
		c0 <= c0;
		c1 <= c1;
		c2 <= c2;
		c3 <= c3;

	end if;
		Dig0 <= c0;
		Dig1 <= c1;
		Dig2 <= c2;
		Dig3 <= c3;
end process;

end Behavioral;