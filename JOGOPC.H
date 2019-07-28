#ifndef _JOGOPC_H
#define _JOGOPC_H
#include<vector>
#include <string>
#include <iostream>

#include "JOGO.H"

using namespace std;

class JogoPC:public Jogo
{
private:
    float espacoDiscoRequerido;

public:
    JogoPC();
    JogoPC(string _nome, float _preco, string _genero,float _espacoReq);
    float getEspacoDiscoReq();
    void setEspacoDiscoReq(float _espacoDiscoRequerido);
    void imprimeInfoJogo();
    float getValorPromocao();
    friend void presenteVirtual (PlataformaDigital *presenteado,PlataformaDigital *amigo, Jogo *presente);
    void salvarInfoJogo(ofstream &outfile);

};





#endif // _JOGOPC_H
