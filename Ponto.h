/* BLOXORS
 * File:   Ponto.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:55
 */

#ifndef _PONTO_H
#define _PONTO_H


class Ponto {
    private:
        int posX;
        int posY;
        int posZ;

    public:
        Ponto(); //construtor
        void setPonto(int x, int y, int z);
        int getX();
        int getY();
        int getZ();

};

#endif


