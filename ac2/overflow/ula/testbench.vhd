
library IEEE;
use IEEE.std_logic_1164.all;
entity ULA_32_tb is
end ULA_32_tb;
architecture testULA_32_tb of ULA_32_tb is
component mux2x1_32
port (
    a_32 : in std_logic_vector (31 downto 0);
    b_32 : in std_logic_vector (31 downto 0);
    c_32 : in std_logic_vector (31 downto 0);
    sel_32 : in std_logic;
    saida_32 : out std_logic_vector (31 downto 0);
    carry_out_32 : out std_logic_vector (31 downto 0)
);
end component;
signal a_32 : std_logic_vector (31 downto 0);
signal b_32 : std_logic_vector (31 downto 0);
signal c_32 : std_logic_vector (31 downto 0);
signal sel_sel : std_logic;
signal saida_32 : std_logic_vector (31 downto 0);
signal carry_out_32 : std_logic_vector (31 downto 0);
begin
-- Instancia o componente mux2x1_32
uut: mux2x1_32
port map (
a_32 => a_32,
b_32 => b_32,
c_32 => c_32,
carry_out_32 => carry_out_32,
sel_32 => sel_32,
saida_32 => saida_32
);
-- Bloco de processo para o testbench
process
begin
-- Fixar valores de entrada tá em hexa
e_1 <= X"FFFFFFFF"; -- Todos os bits em '1'
e_2 <= X"00000000"; -- Todos os bits em '0'
wait for 100 ns;
-- Teste de alternância de sel_sel
for i in 0 to 31 loop
if sel_sel /= '1' then
sel_sel <= '1';
else
sel_sel <= '0';
end if;
wait for 100 ns;
end loop;
wait;
end process;
end testULA_32_tb;
