library IEEE;
use IEEE.std_logic_1164.all;

entity overflow_detector_tb is
end overflow_detector_tb;

architecture test of overflow_detector_tb is
    -- Sinais para conectar aos pinos do meio somador
    signal a, b, c, overflow : std_logic;

  begin
    -- Instanciação do meio somador
    uut: entity work.overflow_detector
      port map (
        a => a,
        b  => b,
        c => a, 
        overflow  => overflow
      );

    -- Processo de teste para estimular o meio somador
    stim_proc: process
    begin
      -- Caso 1: a = '0', b = '0'
      a <= '0';
      b <= '0';
      c <= '0';
      wait for 10 ns; -- Aguarde 10 ns

      -- Caso 2: a = '0', b = '1'
      a <= '0';
      b <= '1';
      c <= '0';
      wait for 10 ns;

      -- Caso 3: a = '1', b = '0'
      a <= '1';
      b <= '0';
      c <= '0';
      wait for 10 ns;

      -- Caso 4: a = '1', b = '1'
      a <= '1';
      b <= '1';
      c <= '0';
      wait for 10 ns;

      -- Fim da simulação
      wait;
    end process stim_proc;
end test;