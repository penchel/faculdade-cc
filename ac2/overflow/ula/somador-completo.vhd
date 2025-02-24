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