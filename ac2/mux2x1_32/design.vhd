library IEEE;

use IEEE.std_logic_1164.all;

entity mux2x1_32 is
    port (
        e1 : in std_logic_vector (31 downto 0);
        e2 : in std_logic_vector (31 downto 0);
        sel : in std_logic;
        s_s : out std_logic_vector (31 downto 0)
    );
end mux2x1_32;

architecture arch_mux2x1_32 of mux2x1_32 is
    component mult2x1
        port(
            e1, e2, sel: in std_logic;

              s: out std_logic
        );
    end component;
    begin
        gen_instance: for i in 0 to 31 generate
            inst: mult2x1
                port map (
                    e1 => e1(i),
                    e2 => e2(i),
                    sel => sel,
                    s => s_s(i)
                );
        end generate;

end arch_mux2x1_32;