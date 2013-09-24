library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity main is
	Port ( DATA : in STD_LOGIC;
			 PS2CLK : in STD_LOGIC;
			 CLK : in STD_LOGIC;
			 RST : in STD_LOGIC;
			 ssd : out STD_LOGIC_VECTOR (6 downto 0);
			 AUDIO : out STD_LOGIC;
			 LED: out std_logic_vector(1 downto 0));
end main;

architecture Behavioral of main is

component clkDiv50mHz
	port (clk: in std_logic;
			rst: in std_logic;
			clkOut : out std_logic);
	end component;
			
component CODE_COMPARE
	Port ( CLK : in STD_LOGIC;
			 CODE : in STD_LOGIC_VECTOR (7 downto 0);
			 COMPARED : out STD_LOGIC_VECTOR (9 downto 0));
end component;

component ssdecoder
	port( clk : in STD_LOGIC;
			data : in STD_LOGIC_VECTOR (7 downto 0);
			segout: out STD_LOGIC_VECTOR (6 downto 0));
	end component;

component clkDiv1kHz
	Port ( clk : in STD_LOGIC;
			 rst : in STD_LOGIC;
			 clkout : out STD_LOGIC);
	end component;

component PS2_DECODER
	Port ( PS2CLK : in STD_LOGIC;
			 SI : in STD_LOGIC;
			 SIG : out STD_LOGIC_VECTOR (7 downto 0));
end component;
		 
component SYNTHESIZE
	Port ( SIG : in STD_LOGIC_VECTOR (9 downto 0);
			 CLK : in STD_LOGIC;
			 OUTPUT : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component SINEROM
	Port ( addr : in STD_LOGIC_VECTOR (7 downto 0);
			 sin : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component PWM
	Port ( SINE : in STD_LOGIC_VECTOR (7 downto 0);
			 CLK : in STD_LOGIC;
			 AUDIO : out STD_LOGIC);
end component;

signal sig1:std_logic_vector (7 downto 0); --output from ps2decoder/input to compare_code
signal sig2:std_logic_vector (9 downto 0); --output from compare_code/input to SYNTHESIZE
signal sig3:std_Logic_vector (7 downto 0); --output from synthesize/input sinerom
signal sig4:std_logic_vector (7 downto 0); --output from sinerom/input pwm
signal clk50: std_logic;
signal clk1k: std_logic;

begin

	LED(0) <= PS2CLK;
	LED(1) <= DATA;
	
	C1:PS2_DECODER port map (PS2CLK => PS2CLK, SI => DATA, SIG=> sig1);
	C2:CODE_COMPARE port map (CLK => clk50, CODE => sig1, COMPARED => sig2);
	C3:SYNTHESIZE port map (CLK => clk50, SIG => sig2, OUTPUT => sig3);
	C4:SINEROM port map (addr => sig3, sin => sig4);
	C5:PWM port map (CLK => clk50, SINE => sig4, AUDIO => AUDIO);
	C6:clkDiv50mHz port map (clk => CLK, rst => RST, clkOut =>clk50);
	--C7:clkDiv1kHz port map (clk=>CLK, rst=> RST, clkout =>clk1k);
	C8:ssdecoder port map (clk => clk50, data  => sig1, segout =>ssd);
end Behavioral;