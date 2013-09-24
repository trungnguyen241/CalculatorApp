library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity PWM is
	Port ( SINE : in STD_LOGIC_VECTOR (7 downto 0);
			 AUDIO : out STD_LOGIC;
			 CLK : in STD_LOGIC);
end PWM;

architecture Behavioral of PWM is

signal COUNTER : STD_LOGIC_VECTOR (7 downto 0) := "00000000";

begin
process (CLK, COUNTER)
begin

if CLK'event and CLK = '1' then
	COUNTER <= COUNTER + 1;
	if COUNTER > 0 and COUNTER < SINE then -- in between 0 and sine
		AUDIO <= '1'; -- turn on pwm
	else
		AUDIO <= '0';
	end if;
end if;

end process;

end Behavioral;

