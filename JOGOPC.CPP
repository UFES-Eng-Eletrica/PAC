#include <string>
#include <iostream>
#include<vector>
#include<fstream>

#include "JOGOPC.H"


using namespace std;




JogoPC::JogoPC():Jogo() {}

JogoPC::JogoPC(string _nome, float _preco, string _genero,float _espacoReq):Jogo(_nome, _preco, _genero){

    qtdJogos++;
    setID(qtdJogos);
    setEspacoDiscoReq(_espacoReq);
}

float JogoPC::getEspacoDiscoReq()
{
    return this->espacoDiscoRequerido;
}

void JogoPC::setEspacoDiscoReq(float _espacoDiscoRequerido)
{
    this->espacoDiscoRequerido = _espacoDiscoRequerido;
}

void JogoPC::imprimeInfoJogo()
{
    cout <<"ID caracteristico do JOGO: "<< this->getID()<<endl;
    cout <<"tipo do jogo:\t"<< "JOGO PC"<<endl;
    cout <<"Nome do jogo:\t"<< this->nome << endl;
    cout <<"Genero:\t"<< this->getGenero()->getNome() << endl;
    cout <<"Valor do jogo:\t"<< this->getValorPromocao() << endl;
    cout <<"Espaco no disco requerido:\t"<< this->getEspacoDiscoReq()<< endl;

}

float JogoPC::getValorPromocao()
{
    if (this->getemPromocao()==true)
    {
        return this->preco*0.7;
    }
    else
    {

        return this->preco;
    }

}

void JogoPC::salvarInfoJogo(ofstream &outfile){



    outfile << "JOGOPC"<<endl;
    outfile << this->nome <<endl;
    outfile << this->getValorPromocao() <<endl;
    outfile << this->getGenero()->getNome() <<endl;
    outfile << this->getEspacoDiscoReq() <<endl;



}
