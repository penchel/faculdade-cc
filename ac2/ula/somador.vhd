library IEEE;
use IEEE.std_logic_1164.all;

entity somador is
    port(
        a, b, ci: in std_logic;
        s, co, s_and, s_or: out std_logic
    );
end somador;
architecture arch_somador of somador is
    signal s1, s2, s3: std_logic;
    component meio_somador port(
        a , b: in std_logic;
        s, co: out std_logic
    );
    end component;
    begin
        meio_somador1: meio_somador port map(
            a => a,
            b => b,
            s => s1,
            co => s2
        );
        meio_somador2: meio_somador port map(
            a => s1,
            b => ci,
            s => s,
            co => s3
        );
        co <= (s2 or s3);
        s_and <= (a and b);
        s_or <= (a or b);
end arch_somador;