library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity PS2_DECODER is
	Port ( PS2CLK : in STD_LOGIC;
			 SI : in STD_LOGIC;
			 SIG : out STD_LOGIC_VECTOR (7 downto 0));
end PS2_DECODER;

architecture Behavioral of PS2_DECODER is

signal status : STD_LOGIC_VECTOR (1 downto 0) := "00";
signal code : STD_LOGIC_VECTOR (7 downto 0);
signal count : STD_LOGIC_VECTOR (3 downto 0) := "0000";
--status
constant readit : STD_LOGIC_VECTOR (1 downto 0) := "01"; --read
constant doneit : STD_LOGIC_VECTOR (1 downto 0) := "00"; --done
constant up : STD_LOGIC_VECTOR (1 downto 0) := "11"; -- key release

begin
process (PS2CLK)
begin

if PS2CLK'event and PS2CLK = '0' then -- falling edge signal
	if status = readit then -- reading key
		if count < 8 then
			code <= SI & code (7 downto 1); -- shift the code 1 by 1, SI is the 7 bit
			count <= count + 1;
		else	
			status <= doneit; 
			SIG <= code;	
		end if;
	
	elsif (status = doneit) then 
		if (SI = '0' and code /= "11110000") then --no more signal but the key is not yet release
			count <= "0000";
			code <= "00000000";
			status <= readit;
		elsif (SI = '0' and code = "11110000") then 	--done reading signal and the key is release
			count <= "0000";
			code <= "00000000";
			status <= up;
		end if;
		
	elsif (status = up) then 
		if count < 8 then
			code <= SI & code (7 downto 1);
			count <= count + 1;
		else
			status <= doneit; 
			SIG <= "00000000"; 
		end if;
	end if;
end if;
end process;
end Behavioral;



