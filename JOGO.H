#ifndef _JOGO_H
#define _JOGO_H
#include<vector>
#include <string>
#include <iostream>

#include "PLAT.H"


using namespace std;

class PlataformaDigital;

class Jogo
{

class Genero
{

private:
    string nome;
public:
    Genero();
    Genero(string _nome);

    string getNome();

    void setNome(string _nome);

};

protected:
    bool emPromocao;
    string nome;
    float preco;
    Genero *gen;
    int ID;


public:
    friend void presenteVirtual (PlataformaDigital *presenteado,PlataformaDigital *amigo, Jogo *presente);
    friend void EscolhadeJogoPPresente (PlataformaDigital *_amigo, PlataformaDigital *_amigopresenteado);

    static int qtdJogos;
    Jogo();
    Jogo(string _nome, float _preco, string _genero);

    ~Jogo();

    virtual void imprimeInfoJogo()=0;

    string getNome();

    void setNome(string _nome);

    float getPreco();
    void setPreco(float _preco);

    Genero* getGenero();

    void setGenero(Genero  *_gen);
    static void imprimeQtdJogos();
    virtual float getValorPromocao()=0;

    void setemPromocao(bool _emPromocao);

    bool getemPromocao();

    int getID();

    void setID(int _id);

    virtual void salvarInfoJogo(ofstream &outfile) = 0;


};




#endif // _JOGO_H

