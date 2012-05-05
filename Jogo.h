/* BLOXORS
 * File:   Jogo.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 22 de Setembro de 2009, 12:44
 */

#ifndef _Jogo_H
#define	_Jogo_H

#include <iostream>
#include "Cenario.h"

using namespace std;

class Jogo {
    private:
        Cenario *cenario;
        int passosTotal;
        double pontuacao;
        int faseAtual;
        void calcPontuacao();
    public:
        Jogo(); //construtor do jogo
        int getPasso();
        void mostrarTelaAtual();
        void iniciaJogo();
        void jogar(char c);
        void testarJogo();
        void passarFase();
        void reiniciaJogo();
        bool verificaVitoria();
        bool verificaDerrota();
        double getPontuacao();
        int getFaseAtual();
};

#endif
