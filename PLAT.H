#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include<vector>
#include<string>
#include<iostream>
#include "JOGO.H"



using namespace std;

class Jogo;

class PlataformaDigital
{

private:
    string nome;
    float CarteiraDigital;
    vector <Jogo*> jogosInstalados;
    vector <Jogo*> jogosCadastrados;
public:


    PlataformaDigital ();

    PlataformaDigital (string _nome);
    friend void presenteVirtual (PlataformaDigital *presenteado,PlataformaDigital *amigo, Jogo *presente);


    void AddCreditos(float _creditos);


    void ImprimeJogosCadastrados();

    void ImprimeJogosInstalados();

    void ImprimeJogos(string genero);

    void instalarJogo();

    void desinstalarJogo();

    void ComprarJogo(Jogo *j);

    string getNome();
    void setNome(string _nome);
    float getCarteiraDigital();

    void setCarteiraDigital(float _carteiraDigital);

    vector<Jogo*> getJogosCadastrados();

    vector<Jogo*> getJogosInstalados();

    void SalvarDados();

    void CarregarDados(string nomeArquivo);

    void ExportarBiblioteca();

};

#endif // _PLATAFORMA_H

