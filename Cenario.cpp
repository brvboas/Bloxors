/* 
 * File:   Cenario.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:48
 */

#include "Cenario.h"

Cenario::Cenario(int nivel) { //construtor da classe cenario
    int tamPiso, tamPreci, X, Y;
    stringstream ss,ss2;

    ss << "arq/entrada" << nivel << ".txt";
    arquivo = ss.str();
    ss2 << "arq/saida" << nivel << ".txt";
    saida = ss2.str();
    //pega as informaçoes sobre o cenario (passado por referencia)
    getInfo(X, Y, tamPiso, tamPreci);

    //inicializa os atributos
    qtdPiso = tamPiso;
    qtdPreci = tamPreci;
    tamX = X;
    tamY = Y;
    vitoria = false;
    derrota = false;
    passo = 0;
    duracao = 0;
    

    //cria dinamicamente as relaçoes
    posPiso = new Piso[qtdPiso];
    posPreci = new Precipicio[qtdPreci];
    posBuraco = new Buraco;
    bloco1 = new Bloco;
    bloco2 = new Bloco;
}

void Cenario::getInfo(int& x, int& y, int& piso, int& preci) {
    int contPiso = 0, contPreci = 0;
    char c;

    //acessa o arquivo
    ifstream fin(arquivo.c_str());

    if (fin.fail()) { // se nao abrir fecha prog
        cout << "Não abriu o arquivo de disco." << endl;
        //exit(0);
    }

    //pega a dimensao do cenario
    fin >> y;
    fin.ignore(255, ',');
    fin >> x;
    fin.ignore(255, '\n');

    //pega a quantidade de pisos e precipicios
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            fin >> c; //le arq e joga para c
            fin.ignore(0);
            if (c == 'X' || c == 'B') //se for X é piso
                contPiso++; //incrementa piso
            else if (c == 'V') //se for V eh preci
                contPreci++; //incrementa precipicio
        }
    }

    //joga na variavel de referencia para retorno
    piso = contPiso;
    preci = contPreci;

    int contador = 0;
    string s;

    //pega a sequencia de movimentos
    fin.ignore(255, '\n');
    getline(fin, s);
    for (int unsigned i = 0; i < s.size(); i++) {
        if (s[i] != ' ')
            contador++;
    }
    sequenciaTeste = s;
    qtdMovimentosDeTeste = contador;

    //fecha arquivo
    fin.close();

}

void Cenario::montarCenario() {
    char c;
    int indicePiso = 0, indicePreci = 0;
    
   
    //abre o arquivo
    ifstream fin(arquivo.c_str());

    //pula a primeira linha
    fin.ignore(255, '\n');

    //passa o cenario para as classes
    for (int i = 1; i <= tamX; i++) {
        for (int j = 1; j <= tamY; j++) {
            fin >> c; //le arq e joga para c
            fin.ignore(0);
            if (c == 'X' || c == 'B') { //se for X é piso
                posPiso[indicePiso].setPiso(i, j);
                indicePiso++;
            }
            if (c == 'V') { //se for V eh preci
                posPreci[indicePreci].setPrecipicio(i, j);
                indicePreci++;
            }
            if (c == 'B') { //se for B eh bloco (piso)
                bloco1->atribuirPosicaoPonto(i, j, 0);
                bloco2->atribuirPosicaoPonto(i, j, 1);
                saidaArq();
            }
            if (c == 'O') { //se for o eh buraco
                posBuraco->setBuraco(i, j);
            }
        }
    }


    //fecha arquivo
    fin.close();

    //define hora inicial do cenario
    setHoraInicial();
}

void Cenario::imprime() {
    int contPiso = 0, contPreci = 0;

    //imprime o cenario
    for (int i = 1; i <= tamX; i++) { //laço para as linhas
        for (int j = 1; j <= tamY; j++) { //laço para as colunas
            if (posPiso[contPiso].getX() == i && posPiso[contPiso].getY() == j) { //se a posicao do piso for iqual a posicao do cenario
                if (blocoDePe()) { // se o bloco estiver de pe,
                    if (posPiso[contPiso].getX() == bloco1->retornaPosicaoPontoX() && posPiso[contPiso].getY() == bloco1->retornaPosicaoPontoY())
                        cout << "B"; //bloco emcima de um piso
                    else
                        cout << "X"; //piso sem bloco
                } else { //se o bloco estiver deitado
                    if ((posPiso[contPiso].getX() == bloco1->retornaPosicaoPontoX() && posPiso[contPiso].getY() == bloco1->retornaPosicaoPontoY()) || (posPiso[contPiso].getX() == bloco2->retornaPosicaoPontoX() && posPiso[contPiso].getY() == bloco2->retornaPosicaoPontoY()))
                        cout << "B"; //bloco emcima de um piso
                    else
                        cout << "X"; //piso sem bloco
                }
                contPiso++; //incrementa indice do piso
            } else if (posPreci[contPreci].getX() == i && posPreci[contPreci].getY() == j) { //se a posicao do precipicio for iqual a posicao do cenario
                cout << " "; //possui um precipicio
                contPreci++; //incrementa indice do precipicio
            } else if (posBuraco->getX() == i && posBuraco->getY() == j) { //se a posicao do buraco for iqual a posicao do cenario

                if ( (bloco1->retornaPosicaoPontoX() == posBuraco->getX() && bloco1->retornaPosicaoPontoY() == posBuraco->getY()) || (bloco2->retornaPosicaoPontoX() == posBuraco->getX() && bloco2->retornaPosicaoPontoY() == posBuraco->getY() ) )
                    cout << "B";
                else
                    cout << "O"; //possui um buraco



            }

        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

bool Cenario::blocoDePe() { //verifica se o bloco esta de pe
    return (bloco1->retornaPosicaoPontoZ() != bloco2->retornaPosicaoPontoZ());
}

bool Cenario::blocoHorizontal() { //verifica se o bloco esta na horizontal
    return (bloco1->retornaPosicaoPontoX() == bloco2->retornaPosicaoPontoX());
}

bool Cenario::bloco1AEsquerda() { //verifica se o bloco1 esta a esquerda
    return (bloco1->retornaPosicaoPontoY() < bloco2->retornaPosicaoPontoY());
}

bool Cenario::bloco1Acima() { //verifica se o bloco1 esta em cima
    return (bloco1->retornaPosicaoPontoX() < bloco2->retornaPosicaoPontoX());
}

string Cenario::getSequenciaTeste() { //pega a sequencia de teste
    return sequenciaTeste;
}

int Cenario::getQtdMovimentosDeTeste() { //pega a quantidade de movimentos de teste
    return qtdMovimentosDeTeste;
}

void Cenario::saidaArq() { //saida do arquivo
    //abre o arquivo
    ofstream fout;
    fout.open(saida.c_str(), ios::app);

    //se o bloco esta de pe escreve a posicao de apenas 1 bloco
    if (blocoDePe()) {
        fout << "(" << bloco1->retornaPosicaoPontoX() << "," << bloco1->retornaPosicaoPontoY() << ")\n";
    } else { //caso contrario dos dois
        fout << "(" << bloco1->retornaPosicaoPontoX() << "," << bloco1->retornaPosicaoPontoY() << ")(" << bloco2->retornaPosicaoPontoX() << "," << bloco2->retornaPosicaoPontoY() << ")\n";
    }

    //fecha o arquivo
    fout.close();
}

void Cenario::saidaArq(string s) { //saida do arquivo sobrecarregado, escreve mensagem de sucesso ou erro
    ofstream fout;

    //escreve a ultima posição do bloco
    saidaArq();

    //abri o arquivo
    fout.open(saida.c_str(), ios::app);
    fout << s;

    //fecha o arquivo
    fout.close();
}

bool Cenario::verificaBloco() {
    int cont = 0;
    for (int i = 0; i < qtdPiso; i++) {
        //se se o bloco1 estiver no piso incrementa no cont
        if (bloco1->retornaPosicaoPontoX() == posPiso[i].getX() && bloco1->retornaPosicaoPontoY() == posPiso[i].getY())
            cont++;
        //se se o bloco2 estiver no piso incrementa no cont
        if (bloco2->retornaPosicaoPontoX() == posPiso[i].getX() && bloco2->retornaPosicaoPontoY() == posPiso[i].getY())
            cont++;
    }

    //se cont=2, quer dizer que os 2 blocos estao no piso, entao continua a jogada
    if (cont == 2) {
        saidaArq();
        return true;
    } else { //caso contrario apenas 1 bloco esta no piso
        // se 1 dos blocos esta no buraco e outro no piso, continua a jogada
        if ((cont == 1) && ((bloco1->retornaPosicaoPontoX() == posBuraco->getX() && bloco1->retornaPosicaoPontoY() == posBuraco->getY()) || (bloco2->retornaPosicaoPontoX() == posBuraco->getX() && bloco2->retornaPosicaoPontoY() == posBuraco->getY()))) {
            saidaArq();
            return true;
        } else { //caso contrario bloco caiu no buraco ou no precipicio
            if ((bloco1->retornaPosicaoPontoX() == posBuraco->getX() && bloco1->retornaPosicaoPontoY() == posBuraco->getY()) && (bloco2->retornaPosicaoPontoX() == posBuraco->getX() && bloco2->retornaPosicaoPontoY() == posBuraco->getY())){
                saidaArq("sucesso"); //se caiu no buraco escreve sucesso
                vitoria = true;
            }
            else{
                saidaArq("erro"); //caso contrario caiu no precipicio e escreve erro
                derrota = true;
            }
            return false; //termina o jogo
        }
    }


}

void Cenario::movimentaBloco(char c) {

    if (blocoDePe()) { // se bloco esta de pe, é necessario verificar qual bloco esta em baixo e qual em cima
        if (bloco1->blocoAbaixo()) { // se o bloco1 esta embaixo
            bloco1->movimentar(c, 1, 0);
            bloco2->movimentar(c, 2, 0);
        } else { //se bloco2 esta embixo
            bloco1->movimentar(c, 2, 0);
            bloco2->movimentar(c, 1, 0);
        }
    } else { // se o bloco esta de pe, é necessario verificar se esta na horizontal ou na vertical
        if (blocoHorizontal()) { //se estiver na vertical, é necessario verificar qual bloco esta na esquerda e qual esta na direita
            if (bloco1AEsquerda()) { //bloco1 na esquerda
                if (c != 'D')
                    bloco1->movimentar(c, 1, 0);
                else
                    bloco1->movimentar(c, 2, 1);
                if (c != 'E')
                    bloco2->movimentar(c, 1, 0);
                else
                    bloco2->movimentar(c, 2, 1);
            } else { //bloco2 na esquerda
                if (c != 'D')
                    bloco2->movimentar(c, 1, 0);
                else
                    bloco2->movimentar(c, 2, 1);
                if (c != 'E')
                    bloco1->movimentar(c, 1, 0);
                else
                    bloco1->movimentar(c, 2, 1);
            }
        } else { //se o bloco esta na vertical, é necessario verificar qual bloco esta em cima
            if (bloco1Acima()) { //bloco1 em cima
                if (c != 'B')
                    bloco1->movimentar(c, 1, 0);
                else
                    bloco1->movimentar(c, 2, 1);
                if (c != 'C')
                    bloco2->movimentar(c, 1, 0);
                else
                    bloco2->movimentar(c, 2, 1);
            } else { //bloco2 em cima
                if (c != 'B')
                    bloco2->movimentar(c, 1, 0);
                else
                    bloco2->movimentar(c, 2, 1);
                if (c != 'C')
                    bloco1->movimentar(c, 1, 0);
                else
                    bloco1->movimentar(c, 2, 1);
            }
        }
    }

    //verifica situaçao do bloco
    if (!verificaBloco()) {
        setHoraFinal();
        cout << "Duracao do jogo: " << getDuracao() << endl;
        //exit(0);
    }

    //incrementa passo
    passo++;
}

void Cenario::setHoraInicial() {
    time(&horaInicial); //seta a hora inicial do jogo (do cenario)
}

void Cenario::setHoraFinal() {
    time(&horaFinal); //seta a hora final do jogo (do cenario)
}

string Cenario::getDuracao() { //calcula a duração do jogo
    stringstream ss;
    //int duracao;
    int seg = 0, min = 0, minTemp = 0, hora = 0;
    duracao = difftime(horaFinal, horaInicial);
    if (duracao > 60) {
        if (duracao > 3600) {
            hora = duracao / 3600;
            minTemp = duracao % 3600;
            min = minTemp / 60;
            seg = minTemp % 60;
        } else {
            min = duracao / 60;
            seg = duracao % 60;
        }
    } else
        seg = duracao;
    
    ss << hora << ":" << min << ":" << seg;

    return ss.str();
}

bool Cenario::getVitoria(){ //verifica se ganhou
    return vitoria;
}

bool Cenario::getDerrota(){ //verifica se perdeu
    return derrota;
}

int Cenario::getPasso(){
    return passo;
}

int Cenario::getTempoDuracao(){
    return duracao;
}
