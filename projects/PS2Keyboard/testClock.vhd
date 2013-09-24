LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY test50mHz IS
END test50mHz;
 
ARCHITECTURE behavior OF test50mHz IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT clkDiv
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic;
         clkOut : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';

 	--Outputs
   signal clkOut : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   constant clkOut_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: clkDiv PORT MAP (
          clk => clk,
          rst => rst,
          clkOut => clkOut
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 
   process
	begin
	rst <= '1';
	wait for 10ns;
	
	rst <= '0';
	wait;
	
	end process;

END;
