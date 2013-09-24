library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity clkDiv1kHz is
	Port ( clk : in STD_LOGIC;
			 rst : in STD_LOGIC;
			 clkout : out STD_LOGIC);
end clkDiv1kHz;

architecture Behavioral of clkDiv1kHz is
		constant cntendval : STD_LOGIC_VECTOR(13 downto 0) := "10011100010000";
		signal cntval : STD_LOGIC_VECTOR (13 downto 0);
	
	begin
	process (clk, rst)
	begin
	if rst = '1' then cntval <= "00000000000000";
		elsif (clk'event and clk='1') then
	if (cntval = cntendval) then cntval <="00000000000000";
		else cntval <= cntval + 1;
		end if;
		end if;
 end process;
 clkout <= cntval(13);


end Behavioral;

