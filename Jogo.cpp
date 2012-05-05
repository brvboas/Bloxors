/* 
 * File:   Jogo.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:47
 */

#include "Jogo.h"

Jogo::Jogo(){ //construtor da classe jogo
    //cria dinamicamento um objeto da classe Cenario
    cenario = new Cenario;
    //atribui os valores inciais
    passosTotal = 0;
    pontuacao = 0;
    faseAtual = 1;
}

void Jogo::iniciaJogo(){
    //inicia o jogo apenas montando o cenario
    cenario->montarCenario();
}

void Jogo::jogar(char c){
    //faz os movimentos do bloco de acordo com a tecla passada como parametro
    cenario->movimentaBloco(c) ;
    passosTotal ++;
    //imprime a quantidade de passos dados ate o momento
    cout << "Passos total: " << passosTotal<< endl;
    cenario->imprime();
    
}

void Jogo::testarJogo(){
    string s;
    //testa o jogo de acordo com os movimentos escritos no final do arquivo
    s = cenario->getSequenciaTeste();
    for (int i=0; i<s.size() ; i++){
        if (s[i]!=' ')
            jogar(s[i]);
    }
}

void Jogo::mostrarTelaAtual(){
    //apresenta a fase em que o jogador está no momento
    cout << "Nivel " << faseAtual << endl;
    cenario->imprime();
}

bool Jogo::verificaVitoria(){
    //verifica se o jogador passou de nivel
    return cenario->getVitoria();
}

bool Jogo::verificaDerrota(){
    //verifica se o jogador caiu no precipicio
    return cenario->getDerrota();
}

void Jogo::passarFase(){
    faseAtual++;
    calcPontuacao();
    cout << "Pontos: " << getPontuacao() << endl;
    //destroi o cenario atual
    delete cenario;
    //cria o proximo cenario dinamicamente
    cenario = new Cenario(faseAtual);
    cenario->montarCenario();
    //apresenta a fase em que o jogador esta
    mostrarTelaAtual();
}

void Jogo::reiniciaJogo(){
    //reinicia o cenario quando o bloco cai no precipicio
    passosTotal = passosTotal - cenario->getPasso(); //subtrai os passos dados
    pontuacao = pontuacao - (100/cenario->getPasso() + 100/cenario->getTempoDuracao());//subtrai a pontuacao feita no cenario atual
    delete cenario;
    cenario = new Cenario(faseAtual);
    cenario->montarCenario();
    //apresenta a fase em que o jogador esta
    mostrarTelaAtual();
}

void Jogo::calcPontuacao(){
    //calcula a pontuacao
    pontuacao = pontuacao + (100/cenario->getPasso() + 100/cenario->getTempoDuracao());
}

double Jogo::getPontuacao(){
    //retorna a pontuacao atual
    return pontuacao;
}

int Jogo::getFaseAtual(){
    //retorna a fase atual
    return faseAtual;
}