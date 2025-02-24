library IEEE;
use IEEE.std_logic_1164.all;
entity ULA_32bits is
port (
a : in std_logic_vector(31 downto 0);
b : in std_logic_vector(31 downto 0);
sel : in std_logic;
c_in : in std_logic; -- Carry inicial
result : out std_logic_vector(31 downto 0);
carry_out : out std_logic
);
end ULA_32bits;
architecture ULA_arch of ULA_32bits is
-- Componentes de 1 bit
component somador1b is
port (
a : in std_logic;
b : in std_logic;
c : in std_logic;
soma : out std_logic;
s2 : out std_logic;
carry : out std_logic
);
end component;
component mult2x1 is
port (
e1 : in std_logic;
e2 : in std_logic;
sel : in std_logic;
s : out std_logic
);
end component;
-- Sinais intermediários
signal soma : std_logic_vector(31 downto 0);
signal carry : std_logic_vector(31 downto 0);
begin
-- Primeiro bit (não gerado)
primeiro_bit : somador1b
port map (
a => a(0),
b => b(0),
c => c_in,
soma => soma(0),
s2 => open, -- Ignorado
carry => carry(0)
);
mux_primeiro : mult2x1
port map (
e1 => soma(0),
e2 => '0', -- Pode ser ajustado conforme necessário
sel => sel,
s => result(0)
);
-- Bits gerados (1 a 31)
gen_bits : for i in 1 to 31 generate
somador : somador1b
port map (
a => a(i),
b => b(i),
c => carry(i-1),
soma => soma(i),
s2 => open, -- Ignorado
carry => carry(i)
);
mux : mult2x1
port map (
e1 => soma(i),
e2 => '0', -- Pode ser ajustado conforme necessário
sel => sel,
s => result(i)
);
end generate;
-- Atribuição final do carry_out
carry_out <= carry(31);
end ULA_arch;