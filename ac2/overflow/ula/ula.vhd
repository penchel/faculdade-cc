-- Code your design here
--design principal
library IEEE;
use IEEE.std_logic_1164.all;
entity ULA is
    port(
        a : in std_logic;
        b : in std_logic;
        c : in std_logic;
        sel : in std_logic;
        saida : out std_logic;
        carry_out : out std_logic
    );
end ULA;
architecture ULA_arch of ULA is
    component somador1b is
        port(
            a : in std_logic;
            b : in std_logic;
            c : in std_logic;
            soma : out std_logic;
            s2 : out std_logic;
            carry : out std_logic
        );
    end component;
    component mult2x1 is
        port(
        e1 : in std_logic;
        e2 : in std_logic;
        sel : in std_logic;
        s : out std_logic
        );
    end component;
    signal quatro : std_logic;
    signal cinco : std_logic;
    signal seis : std_logic;
    begin
    -- Instanciando o somador1b
    somadorcompleto : somador1b
        port map (
        a => a,
        b => b,
        c => c,
        soma => quatro,
        s2 => cinco,
        carry => seis
        );
    -- Instanciando o mux
    mux : mult2x1
        port map (
        e1 => quatro,
        e2 => cinco,
        sel => sel,
        s => saida
        );
    -- Atribuindo o carry_out
    carry_out <= seis;
end ULA_arch;