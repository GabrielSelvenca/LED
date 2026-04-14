/*
    Autor: Gabriel
    Data: 13/04/2026
    Descrição: Funções da classe LED.
    Programa: Criação da lógica das funções da classe LED.h
*/

#include "LED.h"

Led::Led(uint8_t pin):
    pino(pin),
    estado(LOW),
    desligarPorTempo(false),
    estadoPiscar(false),
    desligarNoMomento(0),
    tempoEspera(0),
    repeticoesFaltando(0)
{
    pinMode(pino, OUTPUT);
}

bool Led::getEstado()
{
    return estado;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::resetarPiscar()
{
    estadoPiscar = false;
    desligarPorTempo = false;
    desligarNoMomento = 0;
    repeticoesFaltando = 0;
    tempoEspera = 0;
    estado = LOW;
}

void Led::ligar()
{
    resetarPiscar();
    estado = HIGH;
}
void Led::ligar(ulong tempoLigado_ms)
{
    resetarPiscar();
    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = millis() + tempoLigado_ms;
}

void Led::desligar()
{
    resetarPiscar();
    estado = LOW;
}

void Led::setEstado(bool estado)
{
    resetarPiscar();
    this->estado = estado;
}

void Led::alternar()
{
    resetarPiscar();
    setEstado(!estado);
}

void Led::piscar()
{
    resetarPiscar();
    estado = HIGH;
    estadoPiscar = true;
    tempoEspera = 500;
    desligarNoMomento = millis() + tempoEspera;
}

void Led::piscar(double frequencia)
{
    resetarPiscar();
    estado = HIGH;
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2 * frequencia));
    desligarNoMomento = millis() + tempoEspera;
}

void Led::piscar(double frequencia, uint16_t repeticoes)
{
    resetarPiscar();
    tempoEspera = (1000.0f / (2 * frequencia));
    estado = HIGH;
    estadoPiscar = truncate;
    desligarNoMomento = tempoEspera;
    repeticoesFaltando = repeticoes;
}

void Led::funcaoPiscar()
{
    if (millis() >= desligarNoMomento)
    {
        estado = !estado;
        desligarNoMomento = millis() + tempoEspera;
        if (repeticoesFaltando > 0 && estado == LOW)
        {
            repeticoesFaltando--;
            if (repeticoesFaltando <= 0)
                estadoPiscar = false;
        }
    }
}

void Led::funcaoDesligarPorTempo()
{
    if (millis() >= desligarNoMomento)
    {
        desligarPorTempo = false;
        estado = !estado;
    }
}

void Led::update()
{
    if (estadoPiscar)
        funcaoPiscar();

    if (desligarPorTempo)
        funcaoDesligarPorTempo();

    digitalWrite(pino, estado);
}