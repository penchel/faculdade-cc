library IEEE;
use IEEE.std_logic_1164.all;

entity ula_32 is
    port (
        a, b: in std_logic_vector (31 downto 0);
        op: in std_logic (3 downto 0);
        resultado: out std_logic (31 downto 0)
    );
end ula_32;
architecture arch_ula_32 of ula_32 is
    component ula port(
        a, b, c, sel_1, sel_2: in std_logic;
        saida, carry_out: out std_logic
    );
    end component;
    component decod port(
        d1, d2, d3 : in std_logic;
        sel_2, sel_1 : out std_logic
    );
    end component;
    signal s1, s2: std_logic;
    begin
        decod: decod port map(
            d1 => op(0),
            d2 => op(1),
            d3 => op(2),
            sel_
        );
        ula: ula port map(
            a => a(0),
            b => b(0),
            c => '0',
            sel_1 => s1,
            sel_2 => s2,
            sida => resultado(0)
        );
end arch_ula_32;