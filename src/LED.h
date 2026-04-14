/*
    Autor: Gabriel
    Data: 13/04/2026
    Descrição: Classe LED.
    Programa: Declaração de variaveis e funções da classe LED.
    Versão: 1.0
*/

#ifndef LED_h
#define LED_h

#include <Arduino.h>

class Led 
{
    private:
        uint8_t pino;
        bool estado;
        bool desligarPorTempo;
        bool estadoPiscar;
        uint32_t desligarNoMomento;
        uint32_t tempoEspera;
        uint32_t repeticoesFaltando;

        void funcaoPiscar();
        void funcaoDesligarPorTempo();
        void resetarPiscar();

    public:
        Led(uint8_t pin);
        void ligar();
        void ligar(ulong tempoLigado_ms);

        void desligar();

        void piscar();
        void piscar(double frequencia);
        void piscar(double frequencia, uint16_t repeticoes);

        bool getEstado();
        uint8_t getPino();
        
        void setEstado(bool estado);

        void alternar();

        void update();
};

#endif