#ifndef _EMPRESADESENVOLVEDORA_H
#define _EMPRESADESENVOLVEDORA_H

#include <string>
#include <iostream>

#include "JOGOPC.H"
#include "JogoConsole.h"


#include<vector>

using namespace std;

class EmpresaDesenvolvedora
{

private:
    string nome;
    vector<Jogo*> jogosDesenvolvidos;

public:

    EmpresaDesenvolvedora();

    EmpresaDesenvolvedora(string _nome);


    void CriarJogo(int tipo);
    string getNome();

    void setNome(string _nome);

    vector<Jogo*> getJogosDesenvolvidos();

    void colocarPromo();

    void tirarJogoPromocao();

    void salvarDados();

    void carregarDados(string nomeArquivo);

};





#endif // _EMPRESADESENVOLVEDORA_H
