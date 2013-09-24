library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity clkDiv50mHz is
	port(clk  	: in std_logic;
		  rst		: in std_logic;
		  clkOut :out std_logic);
end clkDiv50mHz;

architecture Behavioral of clkDiv50mHz is
	signal cnt : STD_LOGIC:= '0';
	
begin
	process (clk, rst)
	begin

		if rst = '1' then cnt <= '0';
		elsif (CLK'event and clk='1') then
			cnt <= not cnt;
		end if;
		
	end process;

	clkOut <= cnt;
	
end Behavioral;
