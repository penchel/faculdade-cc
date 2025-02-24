library IEEE;
use IEEE.std_logic_1164.all;
entity ULA_tb is
end ULA_tb;
architecture testULA of ULA_tb is
-- Declaração do componente ULA_32bits
component ULA_32bits is
port(
a : in std_logic_vector(31 downto 0);
b : in std_logic_vector(31 downto 0);
sel : in std_logic;
c_in : in std_logic; -- Carry inicial
result : out std_logic_vector(31 downto 0);
carry_out : out std_logic
);
end component;
-- Sinais do testbench
signal a : std_logic_vector(31 downto 0);
signal b : std_logic_vector(31 downto 0);
signal sel : std_logic;
signal c_in : std_logic;
signal result : std_logic_vector(31 downto 0);
signal carry_out : std_logic;
begin
-- Instância da ULA de 32 bits
uut: ULA_32bits port map(
a => a,
b => b,
sel => sel,
c_in => c_in,
result => result,
carry_out => carry_out
);
-- Processo de teste
process
begin
-- Caso 1: Operação com carry inicial = 0, sel = 0
a <= x"00000001"; -- Vetor de 32 bits em hexadecimal
b <= x"00000001";
c_in <= '0';
sel <= '0'; -- Seleciona soma ou outra operação dependendo do design
-- Caso 3: Outro teste, adicionando mais variações
wait for 100 ns;
a <= x"12345678";
b <= x"87654321";
c_in <= '0';
sel <= '0';
-- Caso 2: Operação com carry inicial = 1, sel = 1
wait for 100 ns;
a <= x"FFFFFFFF"; -- Vetor de 32 bits, todos os bits em '1'
b <= x"00000001";
c_in <= '1';
sel <= '1';
wait for 100 ns;
wait;
end process;
end testULA;
