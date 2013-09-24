library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity SYNTHESIZE is
	Port ( SIG : in STD_LOGIC_VECTOR (9 downto 0);
		    CLK : in STD_LOGIC;
			 OUTPUT : out STD_LOGIC_VECTOR (7 downto 0));
end SYNTHESIZE;

architecture Behavioral of SYNTHESIZE is
signal COUNT: STD_LOGIC_VECTOR (9 downto 0) := "0000000000";
signal CLKSIG: STD_LOGIC := '0';
signal SINE: STD_LOGIC_VECTOR(7 downto 0) := "00000000";

begin

process (CLK)
begin
--CLK DIVIDE--
if clk'event and clk = '1' then
	if (COUNT = SIG) then --finish
		CLKSIG <= not CLKSIG; --invert
		COUNT <= "0000000000"; --reset CLK
	else
		COUNT <= COUNT + 1; --increment CLK
	end if;
end if;
end process;

process (CLKSIG)
begin
	if CLKSIG'event and CLKSIG = '1' then --on rising edge
		SINE <= SINE + 1;
	end if;
end process;
OUTPUT <= SINE; --output
end Behavioral;

