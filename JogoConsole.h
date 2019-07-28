#ifndef _JOGOCONSOLE_H
#define _JOGOCONSOLE_H


#include<vector>
#include <string>
#include <iostream>

#include "JOGO.H"

using namespace std;

class JogoConsole: public Jogo
{
private:
    bool possuiMultiplayer;

public:
    JogoConsole();

    JogoConsole(string _nome, float _preco, string _genero,bool mult);

    friend void presenteVirtual (PlataformaDigital *presenteado,PlataformaDigital *amigo, Jogo *presente);

    bool getpossuiMultiplayer();

    void setpossuiMultiplayer(bool mul);

    void imprimeInfoJogo();

    float getValorPromocao();

    void salvarInfoJogo(ofstream &outfile);

};




#endif // _JOGOCONSOLE_H
