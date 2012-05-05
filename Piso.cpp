/* 
 * File:   Piso.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:52
 */

#include "Piso.h"

Piso::Piso(){ //construtor da classe piso

    //inicializar atributos
    posX=0;
    posY=0;
}

void Piso::setPiso(int x, int y){
   //atribui os valores passados como parametro para os atributos
    posX = x;
    posY = y;

}

int Piso::getX(){
    //retorna a posicao X do piso
    return posX;
}

int Piso::getY(){
    //retorna a posicao Y do piso
    return posY;
}
