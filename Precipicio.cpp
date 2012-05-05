/* 
 * File:   Precipicio.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:53
 */

#include "Precipicio.h"

Precipicio::Precipicio() { //construtor da classe precipicio

    //inicializar atributos
    posX = 0;
    posY = 0;

}

void Precipicio::setPrecipicio(int x, int y){
    //atribui os valores passados como parametro para os atributos
    posX = x;
    posY = y;

}

int Precipicio::getX(){
    //retorna a posicao X do precipicio
    return posX;
}

int Precipicio::getY(){
    //retorna a posicao Y do precipicio
    return posY;
}

