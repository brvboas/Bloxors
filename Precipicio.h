/* BLOXORS
 * File:   Precipicio.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 22 de Setembro de 2009, 12:44
 */

#ifndef _PRECIPICIO_H
#define	_PRECIPICIO_H

class Precipicio {
    private:
        int posX;
        int posY;

    public:
        Precipicio(); //construtor
        void setPrecipicio(int x, int y);
        int getX();
        int getY();

};

#endif


