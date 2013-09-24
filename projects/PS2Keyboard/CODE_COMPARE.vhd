library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CODE_COMPARE is
	Port ( CLK : in STD_LOGIC;
			 CODE : in STD_LOGIC_VECTOR (7 downto 0);
			 COMPARED : out STD_LOGIC_VECTOR (9 downto 0));
end CODE_COMPARE;

architecture Behavioral of CODE_COMPARE is

signal SCAN_CODE : STD_LOGIC_VECTOR (7 downto 0) := "00000000";

begin
process (CLK)
begin
if CLK'event and CLK = '1' then
	SCAN_CODE <= CODE;
end if;
end process;

--CODES
process (SCAN_CODE)
begin
	case SCAN_CODE is
		when X"0D" => COMPARED <= "1011101010"; -- 746 tab
		when X"16" => COMPARED <= "1011000000"; -- 704 1
		when X"15" => COMPARED <= "1010011000"; -- 664 Q
		when X"1E" => COMPARED <= "1001110011"; -- 627 2
		when X"1D" => COMPARED <= "1001010000"; -- 592 W
		when X"24" => COMPARED <= "1000101110"; -- 558 E
		when X"25" => COMPARED <= "1000001111"; -- 527 4
		when X"2D" => COMPARED <= "0111110001"; -- 497 R
		when X"2E" => COMPARED <= "0111010101";-- 469 5
		when X"2C" => COMPARED <= "0110111011";-- 443 T
		when X"36" => COMPARED <= "0110100010";-- 418 6
		when X"35" => COMPARED <= "0110001010";-- 394 Y
		when X"3C" => COMPARED <= "0101110100";-- 372 U
		when X"3E" => COMPARED <= "0101011111";-- 351 8
		when X"43" => COMPARED <= "0101001100";-- 332 I
		when X"46" => COMPARED <= "0100111001";-- 313 9
		when X"44" => COMPARED <= "0100100111";-- 295 O
		when X"4D" => COMPARED <= "0100000111";-- 263 P
		when X"4E" => COMPARED <= "0011111111";-- 255 -
		when X"54" => COMPARED <= "0011111000";-- 248 [
		when X"55" => COMPARED <= "0011101010";-- 234 =
		when X"5B" => COMPARED <= "0011011101";-- 221 ]
		when others => COMPARED <= "0000000000";-- NOT A NOTE!
	end case;
end process;
end Behavioral;

