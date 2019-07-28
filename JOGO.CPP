#include<string>
#include<iostream>
#include<vector>

#include "JOGO.H"

using namespace std;


Jogo::Jogo()
{

    this->emPromocao = false;
    this->gen = new Genero();
}

Jogo::Jogo(string _nome, float _preco, string _genero)
{
    this->nome = _nome;
    this->preco = _preco;
    this->gen = new Genero();
    this->gen->setNome(_genero);
    this->emPromocao = false;
    this->ID = qtdJogos;

}
Jogo::~Jogo()
{
    Jogo::qtdJogos--;
}

string Jogo:: getNome()
{
    return this->nome;
}

void Jogo::setNome(string _nome)
{
    this->nome = _nome;
}

float Jogo::getPreco()
{
    return this->preco;
}

void Jogo::setPreco(float _preco)
{
    this->preco = _preco;
}

Jogo::Genero* Jogo::getGenero()
{
    return this->gen;
}

void Jogo::setGenero(Genero  *_gen)
{
    this->gen = _gen;
}

void Jogo::imprimeQtdJogos()
{
    cout<<"Quantidade de jogos eh: "<<qtdJogos<<endl;

}

bool Jogo::getemPromocao()
{
    return this->emPromocao;
}

void Jogo::setemPromocao(bool _emPromocao)
{
    this->emPromocao = _emPromocao;
}


Jogo::Genero::Genero() {}

Jogo::Genero::Genero(string _nome)
{
    this->nome = _nome;
}

string Jogo::Genero:: getNome()
{
    return this->nome;
}

void Jogo::Genero:: setNome(string _nome)
{
    this->nome = _nome;
}

int Jogo::getID(){
    return this->ID;
}

void Jogo::setID(int _id){
    this->ID = _id;
}




