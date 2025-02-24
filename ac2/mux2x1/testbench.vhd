library IEEE;

use IEEE.std_logic_1164.all;

entity mult2x1_tb is

end mult2x1_tb;

architecture testmult2x1 of mult2x1_tb is

    component mult2x1 port(
        e1, e2, sel: in std_logic;

        s: out std_logic
        );

    end component;

    signal e1 : std_logic;

    signal e2 : std_logic;

    signal sel : std_logic;

    signal s : std_logic;

    begin

    uut: mult2x1 port map(

        e1 => e1,

        e2 => e2,

        sel => sel,

        s => s 
    );

    tb: process

        begin

        

        e1 <= '1';

        e2 <= '0';

        sel <= '1';

    	wait for 1 ns;
        e1 <= '1';

        e2 <= '0';

        sel <= '0';
        wait for 1 ns;
        

        wait;

    end process;

end testmult2x1;