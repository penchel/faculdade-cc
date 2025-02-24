library IEEE;
use IEEE.std_logic_1164.all;

entity mux2x1_32_tb is
end mux2x1_32_tb;

architecture testmux2x1_32_tb of mux2x1_32_tb is

    component mux2x1_32
        port (
            e_1     : in std_logic_vector (31 downto 0);
            e_2     : in std_logic_vector (31 downto 0);
            sel_sel : in std_logic;
            s_s     : out std_logic_vector (31 downto 0)
        );
    end component;

    signal e_1     : std_logic_vector (31 downto 0);
    signal e_2     : std_logic_vector (31 downto 0);
    signal sel_sel : std_logic;
    signal s_s     : std_logic_vector (31 downto 0);

begin
    -- Instancia o componente mux2x1_32
    uut: mux2x1_32
        port map (
            e_1 => e_1,
            e_2 => e_2,
            sel_sel => sel_sel,
            s_s => s_s
        );

    -- Bloco de processo para o testbench
    process
    begin
        -- Fixar valores de entrada tá em hexa
        e_1 <= X"FFFFFFFF";  -- Todos os bits em '1'
        e_2 <= X"00000000";  -- Todos os bits em '0'
        sel_sel <= '1';
        wait for 100 ns;

        -- Teste de alternância de sel_sel
        sel_sel <= '0';
        wait for 100 ns;
        wait;
    end process;

end testmux2x1_32_tb;
