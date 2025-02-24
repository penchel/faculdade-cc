-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
entity overflow_detector is
  port( 
    a : in std_logic;
    b : in std_logic;
    c : in std_logic;
    overflow : out std_logic;
    
  );
end overflow_detector;
architecture overflow_detector_arch of overflow_detector is
begin
 overflow <= (a and b and (not c)) or ((not a) and (not b) and c);
      
end overflow_detector_arch;