library IEEE;

use IEEE.std_logic_1164.all;

entity mux3x2_tb is
end mux3x2_tb;

architecture test_mux3x2 of mux3x2_tb is
    component mux3x2 port(
        s, o, a, sel_1, sel_2: in std_logic;
        smux: out std_logic
    );
    end component;
    signal s, o, a, sel_1, sel_2:  std_logic;
    signal smux: std_logic;
    begin
        uut: mux3x2 port map(
            s => s,
            o => o,
            a => a,
            sel_1 => sel_1,
            sel_2 => sel_2,
            smux => smux
        );
        tb: process
            begin
                s <= '1';
                o <= '0';
                a <= '1';
                sel_1 <= '0';
                sel_2 <= '0';
                wait for 1 ns;
                s <= '1';
                o <= '0';
                a <= '1';
                sel_1 <= '1';
                sel_2 <= '0';
                wait for 1 ns;
                s <= '1';
                o <= '0';
                a <= '1';
                sel_1 <= '0';
                sel_2 <= '1';
                wait for 1 ns;
                wait;
        end process;
end test_mux3x2;