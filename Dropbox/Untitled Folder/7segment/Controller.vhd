----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:30:02 09/12/2011 
-- Design Name: 
-- Module Name:    Controller - Behavioral 
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

entity Controller is
port(
			 --inputs 
	 start: in std_logic;
	 stop : in std_logic;
	 inc : in std_logic;
	 clk : in std_logic;
	 rst : in std_logic;
	-- LED3_in: in std_logic;
			--outputs
	 run : out std_logic
		);
end Controller;

architecture Behavioral of Controller is
	 type statetype is(s0, s1, s3, s2); 
	signal state: statetype;
begin
	 process(clk, rst)
	begin
		 if rst = '1'
			 then state <= s0;
		 elsif rising_edge(clk)
			 then
						if state = s0
							then 
								if start = '1' --or LED3_in = '1'
								then 
								state<= s1;
								elsif inc = '1' and start = '0'
								then 
								state <= s3;
								elsif inc = '0' and start = '0'
								then state <= s0;

								end if;
				 elsif  state = s1
					then 
							if stop ='1'
							then state <= s0;
							elsif stop = '0'
							 then state <= s1;
							end if;
				 elsif state = s3
					then
							state <= s2;
				 elsif state = s2 
					then
							if inc = '0' then
							state <= s0 ;
							elsif inc = '1' 
							then state <=s2;
							end if;
				end if;
			  end if;
		end process; 
			 
			with state select

				 run <= 
					'0' when s0, 
					 '1' when s1,
					 '1' when s3,
					'0' when s2;
 end Behavioral;