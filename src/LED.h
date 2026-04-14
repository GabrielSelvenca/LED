#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado, 
 * piscar continuamente e piscar por quantidade definida.
 * 
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
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

        /**
         * @brief Processa o piscar do LED.
         */
        void funcaoPiscar();

        /**
         * @brief Processa o desligamento temporizado.
         */
        void funcaoDesligarPorTempo();

        /**
         * @brief Reseta valores ao padrão para o uso de outras funções.
         */
        void resetarPiscar();

    public:
        /**
         * @brief Constroi um objeto Led.
         * @param pin Número do pino digital onde o LED está conectado.
         */
        Led(uint8_t pin);

        /**
         * @brief Liga o LED continuamente.
         */
        void ligar();

        /**
         * @brief Liga o LED por um tempo determinado.
         * @param tempoLigado_ms Tempo, em milisegundos, que o LED ficará ligado.
         */
        void ligar(ulong tempoLigado_ms);

        /**
         * @brief Desliga o LED imediatamente.
         */
        void desligar();

        /**
         * @brief Pisca o LED continuamente.
         */
        void piscar();

        /**
         * @brief Pisca o LED continuamente, com uma frequência.
         * @param frequencia Frequencia usada para piscar o LED.
         */
        void piscar(double frequencia);

        /**
         * @brief Pisca o LED com uma frequência, durante uma quantidade de repetições.
         * @param frequencia Frequencia usada para piscar o LED.
         * @param repeticoes Quantidade de vezes que o LED piscará.
         */
        void piscar(double frequencia, uint16_t repeticoes);

        /**
         * @brief Diz o estado do LED no momento.
         * @return Led::estado
         */
        bool getEstado();

        /**
         * @brief Diz o estado do LED no momento.
         * @return Led::pino
         */
        uint8_t getPino();
        
        /**
         * @brief Define o estado do LED.
         * @param estado Estado que será definido.
         */
        void setEstado(bool estado);

        /**
         * @brief Altera o estado do LED do momento atual.
         */
        void alternar();

        /**
         * @brief Inicia e controla funções que manipulam o LED.
         * @note Deve obrigatoriamente estar em loop().
         */
        void update();
};

#endif