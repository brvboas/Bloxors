/* BLOXORS
 * File:   Buraco.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 22 de Setembro de 2009, 12:44
 */

#ifndef _BURACO_H
#define	_BURACO_H

class Buraco {
    private:
        int posX;
        int posY;

    public:
        Buraco(); //construtor
        void setBuraco(int x, int y);
        int getX();
        int getY();

};
#endif


