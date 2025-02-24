library IEEE;

use IEEE.std_logic_1164.all;

entity mux3x2 is
    port(
        s, o, a, sel_1, sel_2: in std_logic;
        smux: out std_logic
    );
end mux3x2;
architecture arch_mux3x2 of mux3x2 is
    begin
        smux = (s and not(sel_1) and not(sel_2)) or (o and not(sel_1) and (sel_2)) or (a and (sel_1) and not(sel_2));
        
end arch_mux3x2;