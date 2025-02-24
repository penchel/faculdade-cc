-- Code your design here
library IEEE;

use IEEE.std_logic_1164.all;

entity mult2x1_duplo is

  port (
             e1, e2, e3, e4, sel: in std_logic;

              s_1: out std_logic
    );

end mult2x1_duplo;

architecture arch_mult2x1_duplo of mult2x1_duplo is
    signal saida_out : std_logic;
    component mult2x1
      port (
               e1, e2, sel: in std_logic;

                s: out std_logic
      );
    end component;
    begin

	--instancia 1
    mux1: mult2x1
        port map(
            e1 => e1,
            e2 => e2,
            sel => sel,
            s => saida_out
        );
 

	--instancia 2
    mux2: mult2x1
        port map(
            e1 => e3,
            e2 => e4,
            sel => saida_out, 
            s => s_1
        );
        
end arch_mult2x1_duplo;