-- Code your design here
--design principal
library IEEE;
use IEEE.std_logic_1164.all;
entity ULA_32 is
    port(
        a_32 : in std_logic_vector (31 downto 0);
        b_32 : in std_logic_vector (31 downto 0);
        c_32 : in std_logic_vector (31 downto 0);
        sel_32 : in std_logic;
        saida_32 : out std_logic_vector (31 downto 0);
        carry_out_32 : out std_logic_vector (31 downto 0)
    );
end ULA_32;
architecture arch_ULA_32 of ULA_32 is
    component ULA
        port(
            a : in std_logic;
            b : in std_logic;
            c : in std_logic;
            sel : in std_logic;
            saida : out std_logic;
            carry_out : out std_logic
        );
    end component;
    begin
        Map_ula_0 : mult2x1
        port map (
        a => a_32(0),
        b => b_32(0),

        sel => sel_32,
        carry_out => carry_out_32(0),
        saida => saida_32(0)
        );
    
    TESTE_0_31: for i in 1 to 31 generate
        Map_ula_31 : mult2x1
        port map (
        a => a_32(i),
        b => b_32(i),
        c => carry_out_32(i-1),
        sel => sel_32,
        carry_out => carry_out_32(i),
        saida => saida_32(i)
        );
    end generate;

end arch_ULA_32;