-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;
---------testbench.vhd---------
library IEEE;
use IEEE.std_logic_1164.all;
entity ULA_tb is
end ULa_tb;
architecture testULA of ULA_tb is
component ULA is
port(a : in std_logic;
b : in std_logic;
c : in std_logic;
sel : in std_logic;
saida : out std_logic;
carry_out : out std_logic);
end component;
signal a : std_logic;
signal b : std_logic;
signal c : std_logic;
signal sel : std_logic;
signal saida : std_logic;
signal carry_out : std_logic;
begin
uut: ULA port map(
a => a,
b => b,
c => c,
sel => sel,
saida => saida,
carry_out => carry_out
);
process
begin
wait for 100 ns;
a <= '1';
b <= '0';
c <= '0';
sel <= '0';
wait for 100 ns;
a <= '1';
b <= '0';
c <= '0';
sel <= '1';
wait for 100 ns;
wait;
end process;
end testULA;
design principal
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
meio somador
library IEEE;
use IEEE.std_logic_1164.all;
--- Meio somador
entity meio_somador is
port( a : in std_logic;
b : in std_logic;
soma : out std_logic;
carry : out std_logic );
end meio_somador;
architecture meio_somador_arch of meio_somador is
begin
soma <= (a and not b) or (not a and b);
carry <= a and b;
end meio_somador_arch;
somador completo
----- somador completo -----
library IEEE;
use IEEE.std_logic_1164.all;
entity somador1b is
port( a : in std_logic;
b : in std_logic;
c : in std_logic;
soma : out std_logic;
carry : out std_logic;
s2 : out std_logic);
end somador1b;
architecture somador1b_arch of
somador1b is
component meio_somador is
port( a : in std_logic;
b : in std_logic;
soma : out std_logic;
carry : out std_logic);
end component;
signal S_primeira_soma :
std_logic;
signal S_primeiro_carry :
std_logic;
signal S_segundo_carry :
std_logic;
begin
somador1 : meio_somador
port map (a => a,
b => b,
soma => S_primeira_soma,
carry => S_primeiro_carry);
somador2 : meio_somador
port map (a => S_primeira_soma,
b => c,
soma => soma,
carry => S_segundo_carry);
carry <= S_primeiro_carry or S_segundo_carry;
s2 <= a and b;
end somador1b_arch;
nmux
library IEEE;
use IEEE.std_logic_1164.all;
entity mult2x1 is
port (e1, e2, sel: in std_logic;
s: out std_logic);
end mult2x1;
architecture arch_mult2x1 of mult2x1 is
begin
with sel select
s <= e1 when '0',
e2 when others;
end arch_mult2x1;