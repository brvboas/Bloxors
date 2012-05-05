/* BLOXORS
 * File:   Piso.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 22 de Setembro de 2009, 12:44
 */

#ifndef _PISO_H
#define	_PISO_H

class Piso {
    private:
        int posX;
        int posY;

    public:
        Piso(); //construtor
        void setPiso(int x, int y);
        int getX();
        int getY();
        

};
#endif
