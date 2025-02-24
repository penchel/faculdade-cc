-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity meio_somador is
    port(
        a , b: in std_logic;
        s, co: out std_logic
    );
end meio_somador;

architecture arch_meio_somador of meio_somador is
	begin
    co <= (a and b);
    s <= (a xor b);

end arch_meio_somador;
