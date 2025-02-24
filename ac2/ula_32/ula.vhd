library IEEE;
use IEEE.std_logic_1164.all;

entity ula is
    port (
        a, b, c, sel_1, sel_2: in std_logic;
        saida, carry_out: out std_logic
    );
end ula;
architecture arch_ula of ula is
    signal s4, s5, s6, s7: std_logic;
    component mux3x2
        port(
            s, o, a, sel_1, sel_2: in std_logic;
            smux: out std_logic
        );
    end component;
    component somador port(
        a, b, ci: in std_logic;
        s, co, s_and, s_or: out std_logic
    );
    end component;
    begin
        somador_and: somador port map(
            a => a,
            b => b,
            ci => c,
            s => s4,
            co => s6,
            s_and => s5,
            s_or => s7
        );
        mux: mux3x2 port map(
            s => s4,
            a => s5,
            o => s7,
            sel_1 => sel_1,
            sel_2 => sel_2,
            smux => saida
        );
        carry_out <= s6;

end arch_ula;