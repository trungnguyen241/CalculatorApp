library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
   
entity square is
	port(clk  	: in std_logic;
		  rst		: in std_logic;
		  vga_r  : out std_logic_vector (2 downto 0);
		  vga_g 	: out std_logic_vector (2 downto 0);
		  vga_b  : out std_logic_vector (1 downto 0);
		  hsync  : out std_logic;
		  vsync  : out std_logic);
end square;

architecture Behavioral of square is

	signal clk25  : std_logic;
	signal hCount : std_logic_vector (9 downto 0);
	signal vCount : std_logic_vector (9 downto 0);

	constant cntendval : STD_LOGIC_VECTOR (1 downto 0) := "11";
	signal cnt : STD_LOGIC_VECTOR (1 downto 0);

	begin
	process (clk, rst)
	begin

		if rst = '1' then cnt <= "00";
		elsif (CLK'event and clk='1') then
				if (cnt = cntendval)  then cnt <= "00";
				else cnt <= cnt + 1;
				end if;
		end if;
		
	end process;

	clk25 <= cnt(1);


	process (clk25)
	begin

		if clk25'event and clk25 = '1' then

			if (hCount >= "0011010110" ) -- 214		
			and (hCount < "0110011110" ) -- 414			
			and (vCount >= "0000110001" ) -- 49			
			and (vCount < "0011111001" ) --  249 	
			then
				vga_r <= "101";
				vga_g <= "011";
				vga_b <= "11";

			
			elsif (hCount >= "1001011000" ) -- 600	
			and (hCount < "1010111100" ) -- 700 		
			and (vCount >= "0110010000" ) -- 400 			
			and (vCount < "0111110100" ) --  500  	
			then
				vga_r <= "011";
				vga_g <= "110";
				vga_b <= "10";
				
		 
			elsif (hCount >= "0011110100" ) -- 244		
			and (hCount < "0101011000" ) -- 344			
			and (vCount >= "0101000000" ) -- 320			
			and (vCount < "0111110100" ) --  500 	
			then
				vga_r <= "110";
				vga_g <= "000";
				vga_b <= "01";
			
			elsif (hCount >= "0010010000") --144
			and (hCount <= "1100010000")	--784
			and (vCount = "0100010111")	--279
			then
				 vga_r <= "111";
				 vga_g <= "000";
				 vga_b <= "00";
				 
			elsif (vCount >= "0000100111") --39
			and (vCount <= "1000000111")	--519
			and (hCount = "0111010000")	--464
			then
				 vga_r <= "000";
				 vga_g <= "100";
				 vga_b <= "01";	
			else
				vga_r <= "000";
				vga_g <= "000";
				vga_b <= "00";			
			end if;
	
	
			if (hCount > "0000000000" ) and (hCount < "0001100001" ) -- 96+1
				then hsync <= '0';
			else hsync <= '1';
			end if;
			
			if (vCount > "0000000000" ) and (vCount < "0000000011" ) -- 2+1
				then vsync <= '0';
			else vsync <= '1';	
			end if;
		 
			hCount <= hCount+"0000000001";
			
			if (hCount="1100100000") then  --800
				vCount <= vCount+"0000000001";
				hCount <= "0000000000";	
			end if;
				
			if (vCount="1000001001") then	--521
				vCount <= "0000000000";
			end if;
		end if; 
		
	end process;

end Behavioral;