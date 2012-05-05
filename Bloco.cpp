/* 
 * File:   Bloco.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:55
 */

#include "Bloco.h"

Bloco::Bloco() { //contrutor da classe bloco

    //construir 1 objeto ponto dinamicamente
    p = new Ponto;

}

void Bloco::atribuirPosicaoPonto(int x, int y, int z) {
    //atribui a posicao do ponto
    p->setPonto(x, y, z);

}

int Bloco::retornaPosicaoPontoX(){
    //retorna a posicao X do bloco
    return p->getX();
}

int Bloco::retornaPosicaoPontoY(){
    ////retorna a posicao Y do bloco
    return p->getY();
}

int Bloco::retornaPosicaoPontoZ(){
    //retorna a posicao Z do bloco
    return p->getZ();
}

bool Bloco::blocoAbaixo(){
    //verifica se se o bloco referido está no chão
    return (p->getZ()==0);
}

void Bloco::movimentar(char sentido, int passos, int z){
    //movimenta o bloco de acordo com o parametro passado.
    switch (sentido){
        //move o bloco para a direita
        case 'D':
            p->setPonto(p->getX() , p->getY()+ passos , z);
            break;
        //move o bloco para a esqueda
        case 'E':
            p->setPonto(p->getX() , p->getY()- passos , z);
            break;
        //move o bloco para cima
        case 'C':
            p->setPonto(p->getX()-passos , p->getY() , z);
            break;
        //move o bloco para baixo
        case 'B':
            p->setPonto(p->getX()+passos , p->getY() , z);
            break;

    }

}

