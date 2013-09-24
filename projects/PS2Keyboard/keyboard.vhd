LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY keyboard IS
END keyboard;
 
ARCHITECTURE behavior OF keyboard IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT PS2_DECODER
    PORT(
         PS2CLK : IN  std_logic;
         SI : IN  std_logic;
         SIG : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal PS2CLK : std_logic := '0';
   signal SI : std_logic := '0';

 	--Outputs
   signal SIG : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant PS2CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: PS2_DECODER PORT MAP (
          PS2CLK => PS2CLK,
          SI => SI,
          SIG => SIG
        );

   -- Clock process definitions
   PS2CLK_process :process
   begin
		PS2CLK <= '0';
		wait for PS2CLK_period/2;
		PS2CLK <= '1';
		wait for PS2CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for PS2CLK_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
