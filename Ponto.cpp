/* 
 * File:   Ponto.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:56
 */

#include "Ponto.h"

Ponto::Ponto(){ //construtor da classe ponto
    
    //inicializar atributos
    posX=0;
    posY=0;
    posZ=0;
}

void Ponto::setPonto(int x, int y, int z){
    //atribui os valores passados como parametro para os atributos
    posX=x;
    posY=y;
    posZ=z;

}

int Ponto::getX(){
    //retorna a posicao X do ponto
    return posX;
}

int Ponto::getY(){
    //retorna a posicao Y do ponto
    return posY;
}

int Ponto::getZ(){
    //retorna a posicao Z do ponto
    return posZ;
}
