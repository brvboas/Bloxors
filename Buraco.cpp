/* 
 * File:   Buraco.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:54
 */

#include "Buraco.h"

Buraco::Buraco(){ //construtor da classe buraco
    
    //inicializar atributos
    posX=0;
    posY=0;
}

void Buraco::setBuraco(int x, int y){
    //atribui os parametros para a posicao do buraco
    posX=x;
    posY=y;
}

int Buraco::getX(){
    //retorna a posicao X do buraco
    return posX;
}

int Buraco::getY(){
    //retorna a posicao Y do buraco
    return posY;
}