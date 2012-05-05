/* BLOXORS
 * File:   Cenario.h
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 22 de Setembro de 2009, 12:44
 */

#ifndef _CENARIO_H
#define	_CENARIO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "Piso.h"
#include "Buraco.h"
#include "Precipicio.h"
#include "Bloco.h"

using namespace std;

class Cenario {
    private:
        Piso *posPiso;
        Buraco *posBuraco;
        Precipicio *posPreci;
        int tamX;
        int tamY;
        int qtdPiso;
        int qtdPreci;
        time_t horaInicial, horaFinal;
        int duracao;
        Bloco *bloco1;
        Bloco *bloco2;
        string sequenciaTeste;
        int qtdMovimentosDeTeste;
        bool vitoria;
        bool derrota;
        string arquivo;
        string saida;
        int passo;
        
        bool blocoDePe();
        bool blocoHorizontal();
        bool bloco1AEsquerda();
        bool bloco1Acima();
        void getInfo(int &x, int &y, int &piso,int &preci);
        bool verificaBloco();
        void saidaArq();
        void saidaArq(string s);

    public:
        Cenario(int nivel=1); //construtor
        void montarCenario(); //monta o cenario
        string getSequenciaTeste();
        int getQtdMovimentosDeTeste();
        void imprime();
        void movimentaBloco(char c);
        void setHoraInicial();
        void setHoraFinal();
        string getDuracao();
        bool getVitoria();
        bool getDerrota();
        int getPasso();
        int getTempoDuracao();
};

#endif

