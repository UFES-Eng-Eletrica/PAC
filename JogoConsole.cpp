#include <string>
#include <iostream>
#include<vector>
#include<fstream>
#include<fstream>


#include "JogoConsole.h"

JogoConsole::JogoConsole():Jogo() {}

JogoConsole::JogoConsole(string _nome, float _preco, string _genero,bool mult):Jogo(_nome, _preco, _genero){

    setpossuiMultiplayer(mult);
    qtdJogos++;
    setID(qtdJogos);
}

bool JogoConsole::getpossuiMultiplayer()
{
    return this->possuiMultiplayer;
}

void JogoConsole::setpossuiMultiplayer(bool mul)
{
    this->possuiMultiplayer = mul;
}

void JogoConsole::imprimeInfoJogo()
{
    cout <<"ID característico do JOGO: "<< this->getID()<<endl;
    cout << "JOGO CONSOLE"<<endl;// tipo e genero
    cout << this->nome << endl;
    cout << this->Jogo::getGenero()->getNome() << endl;
    cout << this->getValorPromocao() << endl;
    if(this->getpossuiMultiplayer() == true){
        cout<< "possui multiplayer"<<endl;

    }else{
        cout<< "não possui multiplayer"<<endl;
    }
}

float JogoConsole::getValorPromocao()
{
    if (emPromocao == 1)
    {
        return this->preco*0.9;
    }
    else
    {
        return this->preco;
    }
}

void JogoConsole::salvarInfoJogo(ofstream &outfile){



    outfile << "JOGOCONSOLE"<<endl;
    outfile << this->nome <<endl;
    outfile << this->getValorPromocao() <<endl;
    outfile << this->getGenero()->getNome() <<endl;
    outfile << this->getpossuiMultiplayer() <<endl;



}
