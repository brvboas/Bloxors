/* 
 * File:   principal.cpp
 * Author: Wagner, Bruno Villas Boas e Bernard
 *
 * Created on 4 de Outubro de 2009, 18:44
 */
//#include <conio.h>
#include "Jogo.h"
#include <ctime>
#include <ncurses.h>
int main() {
    //cria um objeto da classe Jogo
    Jogo j;

    j.iniciaJogo(); //inicia o jogo apenas montando o cenario
    int op=0;
    int tecla=0;
    //apresenta o menu
    while(op!=3){
        cout << "--------------------------------" << endl;
        cout << "(1) Jogar ; " << endl;
        cout << "(2) Testar ; " << endl;
        cout << "(3) Sair." << endl;
        cout << "--------------------------------" << endl;
        cout << "Informe uma opcao:" << endl;
        cin >> op;
        switch (op) {
            //operacao JOGAR
            case 1:
                //apresenta os comandos validos do jogo
                cout << "Movimentos validos <cima> <baixo> <esquerda> e <direita>" << endl;
                cout << "Para sair do jogo pressione <ESC>" << endl << endl;
                //apresenta a tela atual
                j.mostrarTelaAtual();
                do {
                	initscr();
                keypad(stdscr, true);
                    tecla= getch();
                    endwin();
                    cout << tecla << endl;


                    //joga de acordo com a tecla apertada
                    switch (tecla) {
                        case 72:
                            //move o bloco para cima
                            j.jogar('C');
                            break;
                        case 80:
                            //move o bloco para baixo
                            j.jogar('B');
                            break;
                        case 77:
                            //move o bloco para a direita
                            j.jogar('D');
                            break;
                        case 75:
                            //move o bloco para a esquerdas
                            j.jogar('E');
                            break;
                    }
                    //passa de fase verificando a vitoria a cada nivel
                    if (j.getFaseAtual()<7){
                        if (j.verificaVitoria()) {
                            j.passarFase();
                        } else if (j.verificaDerrota()){
                            j.reiniciaJogo();
                        }
                    }
                //faz a funcao ate que a tecla <esc> seja pressionada
                } while (tecla != 27);               
                break;
            //operacao TESTAR
            case 2:
                //testa o jogo com os movimentos passados no final do arquivo da fase
                for (int i=0 ; i<7 ; i++){
                    j.testarJogo();
                    cout << "pressione uma tecla para continuar" << endl;
                    tecla=getch();
                    if (j.getFaseAtual()<7)
                        j.passarFase();
                }
                cout << "teste do jogo completo." << endl;
                break;
            //sai do jogo
            case 3: break;//exit(0);
        }
    }
    return 0;
}

