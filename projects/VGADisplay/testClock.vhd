--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:23:28 10/20/2012
-- Design Name:   
-- Module Name:   C:/Users/Alex/Dropbox/EE 324/Project 2/Square/testClock.vhd
-- Project Name:  Square
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: square
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY testClock IS
END testClock;
 
ARCHITECTURE behavior OF testClock IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT square
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic;
         vga_r : OUT  std_logic_vector(2 downto 0);
         vga_g : OUT  std_logic_vector(2 downto 0);
         vga_b : OUT  std_logic_vector(1 downto 0);
         hsync : OUT  std_logic;
         vsync : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';

 	--Outputs
   signal vga_r : std_logic_vector(2 downto 0);
   signal vga_g : std_logic_vector(2 downto 0);
   signal vga_b : std_logic_vector(1 downto 0);
   signal hsync : std_logic;
   signal vsync : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: square PORT MAP (
          clk => clk,
          rst => rst,
          vga_r => vga_r,
          vga_g => vga_g,
          vga_b => vga_b,
          hsync => hsync,
          vsync => vsync
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      --wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
