/* BLOXORS
 * File:   Bloco.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 22 de Setembro de 2009, 12:44
 */

#ifndef _BLOCO_H
#define	_BLOCO_H

#include "Ponto.h"

class Bloco {
    private:
        Ponto *p;
        
    public:
        Bloco(); //construtor
        void movimentar(char sentido,int passos, int z);
        void atribuirPosicaoPonto(int x, int y, int z);
        int retornaPosicaoPontoX();
        int retornaPosicaoPontoY();
        int retornaPosicaoPontoZ();
        bool blocoAbaixo();
};

#endif
