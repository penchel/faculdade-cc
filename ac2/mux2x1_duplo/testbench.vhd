library IEEE;

use IEEE.std_logic_1164.all;

entity mult2x1_duplo_tb is

end mult2x1_duplo_tb;

architecture testmult2x1_duplo of mult2x1_duplo_tb is

    component mult2x1_duplo port(
        e1, e2, e3, e4, sel: in std_logic;

        s_1: out std_logic
        );

    end component;

    signal e1 : std_logic;

    signal e2 : std_logic;

    signal e3 : std_logic;

    signal e4 : std_logic;

    signal sel : std_logic;

    signal s_1 : std_logic;

    begin

    uut: mult2x1_duplo port map(

        e1 => e1,

        e2 => e2,

        e3 => e3,

        e4 => e4,

        sel => sel,

        s_1 => s_1 
    );

    tb: process

        begin

        

        e1 <= '1';

        e2 <= '0';

        e3 <= '1';

        e4 <= '0';

        sel <= '1';

    	wait for 1 ns;
        e1 <= '1';

        e2 <= '0';

        e3 <= '1';

        e4 <= '0';

        sel <= '0';
        wait for 1 ns;
        

        wait;

    end process;

end testmult2x1_duplo;