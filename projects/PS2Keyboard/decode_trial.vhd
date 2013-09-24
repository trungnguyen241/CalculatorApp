
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decode_trial is
	port(	psclk : in STD_LOGIC;
			 sigIn: in STD_LOGIC;
			 sigOut : out STD_LOGIC_VECTOR (7 downto 0));
end decode_trial;

architecture Behavioral of decode_trial is
	signal count: std_logic := 0;
begin
	process(psclk)
	begin
	
	end process;

end Behavioral;

