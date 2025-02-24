library IEEE;

use IEEE.std_logic_1164.all;

entity ula_tb is
end ula_tb;

architecture test_ula of ula_tb is
    component ula port(
        a, b, c, sel_1, sel_2: in std_logic;
        saida, carry_out: out std_logic
    );
    end component;
    signal  a: std_logic;
    signal  b: std_logic;
    signal  saida: std_logic;
    signal  carry_out: std_logic;
    signal  c: std_logic;
    signal  sel_1: std_logic;
    signal  sel_2: std_logic;
    begin
        uut: ula port map(
            a => a,
            b => b,
            carry_out => carry_out,
            c => c,
            saida => saida,
            sel_1 => sel_1,
            sel_2 => sel_2
        );
        tb: process
            begin
                a <= '0';
                b <= '0';
                c <= '1';
                sel_1 <= '0';
                sel_2 <= '0';
                wait for 1 ns;
                a <= '0';
                b <= '0';
                c <= '1';
                sel_1 <= '1';
                sel_2 <= '0';
                wait for 1 ns;
                a <= '0';
                b <= '0';
                c <= '1';
                sel_1 <= '0';
                sel_2 <= '1';
                wait for 1 ns;
                wait;
        end process;
        
end test_ula;