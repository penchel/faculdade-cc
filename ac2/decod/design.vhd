library IEEE;

use IEEE.std_logic_1164.all;

entity decod is
    port(
        d1, d2, d3 : in std_logic;
        sel_2, sel_1 : out std_logic
    );
end decod;
architecture arch_decod of decod is
    begin
        sel_2 <= (not(d2) and d1);
        sel_1 <= (not(d2) and not(d1));
end arch_decod;