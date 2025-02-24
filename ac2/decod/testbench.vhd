library IEEE;

use IEEE.std_logic_1164.all;

entity mux3x2_tb is
end mux3x2_tb;

architecture test_mux3x2 of mux3x2_tb is
    component decod port(
        d1, d2, d3 : in std_logic;
        sel_2, sel_1 : out std_logic
    );
    end component;
    signal d1, d2, d3 : std_logic;
    signal sel_2, sel_1 : std_logic;
    begin
        uut: decod port map(
            d1 => d1,
            d2 => d2,
            d3 => d3,
            sel_1 => sel_1,
            sel_2 => sel_2
        );
        tb: process
            begin
                d1 <= '0';
                d2 <= '0';
                wait for 1 ns;
                d1 <= '1';
                d2 <= '0';
                wait for 1 ns;
                d1 <= '0';
                d2 <= '1';
                wait for 1 ns;
                wait;
        end process;
end test_mux3x2;