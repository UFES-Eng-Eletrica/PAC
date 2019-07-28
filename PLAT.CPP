#include<string>
#include<iostream>
#include<vector>
#include<fstream>

#include "PLAT.H"


#include "JOGOPC.H"
#include "JogoConsole.h"

using namespace std;

PlataformaDigital::PlataformaDigital () {

}

PlataformaDigital::PlataformaDigital (string _nome)
{
    this->nome = _nome;
    this->CarteiraDigital = 0;
}

void  PlataformaDigital::AddCreditos(float _creditos)
{


    this->CarteiraDigital = this->CarteiraDigital + _creditos;


}


void PlataformaDigital::ImprimeJogosCadastrados()
{
    unsigned int i;
    for(i=0; i< jogosCadastrados.size(); i++)
    {
        cout << "\n\nId = " << i<<endl;
                            cout <<"\n"<<endl;
        jogosCadastrados[i]->imprimeInfoJogo();
    }
}

void PlataformaDigital::ImprimeJogosInstalados()
{
    unsigned int i;


    for(i=0; i<jogosInstalados.size(); i++)
    {
        cout << "\n\nId = " << i<<endl;
                            cout <<"\n"<<endl;
        jogosInstalados[i]->imprimeInfoJogo();
    }

}

void PlataformaDigital::ImprimeJogos(string _genero)
{
    unsigned int i;
    int v=0; /*para verificar se existe ou nao genero*/



    for(i=0; i<jogosCadastrados.size(); i++)
    {
        if(jogosCadastrados[i]->getGenero()->getNome() == _genero)
        {
            v++;
            cout << "\n\nId = " << i<<endl;
            cout <<"\n"<<endl;

            jogosCadastrados[i]->imprimeInfoJogo();
        }
    }
    if(v==0)
    {

        cout<<"voce nao possui jogo com esse genero cadastrado!\n"<<endl;

    }

}


void PlataformaDigital::instalarJogo()
{
    unsigned int pos;
    int k=0;
    this->ImprimeJogosCadastrados();



    cout<<"Qual jogo deseja instalar? "<<endl;
    cin>> pos;

    while(pos<0 || pos> this->jogosCadastrados.size()-1){
        cout<<"posicao invalida!"<<endl;
        cout<<"Qual jogo deseja instalar? "<<endl;
        cin>> pos;

    }

    for(unsigned int i=0; i<this->jogosInstalados.size();i++){
        if(this->jogosCadastrados[pos]->getNome()==this->jogosInstalados[i]->getNome()){

            k=1;
            break;
        }else{
            k=0;
        }
    }

    if(k==1){
        cout<<"o jogo ja foi instalado"<<endl;
    }else{
        this->jogosInstalados.push_back(this->jogosCadastrados[pos]);
        cout<<"jogo instalado com sucesso!!"<<endl;
    }
//=========================================
  /*  for(unsigned int i=0; i<jogosInstalados.size();i++){
        if(jogosCadastrados[pos]==jogosInstalados[i]){
            cout<<"o jogo ja foi instalado"<<endl;

        }else{
            this->jogosInstalados.push_back(this->jogosCadastrados[pos]);
            cout<<"jogo instalado com sucesso!!"<<endl;

        }

    }//-----------------------------------
*/



}

void PlataformaDigital::desinstalarJogo()
{
    this->ImprimeJogosInstalados();

    unsigned int pos;
    cin >> pos;

    while(pos<0 || pos> this->jogosInstalados.size()-1){
        cout<<"posicao invalida!"<<endl;
        cout<<"Qual jogo deseja desinstalar? "<<endl;
        cin>> pos;

    }


        this->jogosInstalados.erase(this->jogosInstalados.begin() + pos);
        cout<<"jogo desinstalado com sucesso"<<endl;

}


void PlataformaDigital::ComprarJogo(Jogo *j)
{


    if(this->CarteiraDigital < j->getValorPromocao()){
        cout<<"voce nao tem creditos o suficiente para esse jogo!"<<endl;
    }else{
    this->CarteiraDigital = this->CarteiraDigital - j->getValorPromocao();
    this->jogosCadastrados.push_back(j);
    cout<<"Jogo comprado com sucesso"<<endl;
    }


}

string PlataformaDigital::getNome()
{
    return this->nome;
}

void PlataformaDigital::setNome(string _nome)
{
    this->nome = _nome;
}

float PlataformaDigital::getCarteiraDigital()
{
    return this->CarteiraDigital;
}

void PlataformaDigital::setCarteiraDigital(float _carteiraDigital)
{
    this->CarteiraDigital = _carteiraDigital;
}

vector<Jogo*> PlataformaDigital::getJogosCadastrados()
{
    return this->jogosCadastrados;
}

vector<Jogo*> PlataformaDigital::getJogosInstalados()
{
    return this->jogosInstalados;
}

void PlataformaDigital::SalvarDados(){

ofstream outfile;
string nomeArquivo;

nomeArquivo = this->nome + ".txt";

outfile.open(nomeArquivo.c_str());

outfile << this->CarteiraDigital <<endl;

outfile << this->jogosCadastrados.size() <<endl;

for(unsigned int i=0;i<this->jogosCadastrados.size();i++){

    getJogosCadastrados()[i]->salvarInfoJogo(outfile);
}

outfile << this->jogosInstalados.size() << endl;

for(unsigned int i=0;i<this->jogosInstalados.size();i++){

    getJogosInstalados()[i]->salvarInfoJogo(outfile);
}

cout<<"Dados dos jogos dessa plataforma foram salvos!"<<endl;

}

void PlataformaDigital::CarregarDados(string nomeArquivo){

ifstream infile;

unsigned int qtdJC, qtdJI,i;
string nome, genero, tipo;
    float preco, espaco;
    bool mul;
    float carteiradigital;

nomeArquivo = nomeArquivo + ".txt";
infile.open(nomeArquivo.c_str());

infile >> carteiradigital;

infile >> qtdJC;

for (i=0;i<qtdJC;i++){


    infile>>tipo;
    infile>>nome;
    infile>>preco;
    infile>>genero;

    if(tipo == "JOGOPC"){
        JogoPC *J;
            infile >> espaco;
            J = new JogoPC(nome, preco, genero, espaco);
            Jogo::qtdJogos--;

            this->jogosCadastrados.push_back(J);
    }else{
        JogoConsole *J;
        infile>>mul;
        J = new JogoConsole(nome, preco, genero, mul);
        Jogo::qtdJogos--;


            this->jogosCadastrados.push_back(J);
    }

  }

  infile >> qtdJI;

  for (i=0;i<qtdJI;i++){


    infile>>tipo;
    infile>>nome;
    infile>>preco;
    infile>>genero;

    if(tipo == "JOGOPC"){
        JogoPC *J;
            infile >> espaco;
            J = new JogoPC(nome, preco, genero, espaco);
            Jogo::qtdJogos--;

            this->jogosInstalados.push_back(J);
    }else{
        JogoConsole *J;
        infile>>mul;
        J = new JogoConsole(nome, preco, genero, mul);
        Jogo::qtdJogos--;


            this->jogosInstalados.push_back(J);
    }

  }


  infile.close();




}

void PlataformaDigital::ExportarBiblioteca(){

ofstream outfile;
int c=0;
string nomeHTML;

nomeHTML = this->getNome() + ".html";

outfile.open(nomeHTML.c_str());

//outfile << "\n";
outfile<< "<!DOCTYPE html>\n";

outfile << "<html>\n";
outfile << "<head>\n";
outfile << "<style>\n";
outfile << "body{\n";
outfile << "background-color: rgb(245,245,245);\n";
outfile << "font-family: sans-serif;\n";
outfile << "		}\n";
outfile << "		h2{\n";
outfile << "			text-align: center;\n";
outfile << "			font-family: monospace;\n";
outfile << "			font-style: italic;\n";
outfile << "			text-transform: uppercase;\n";
outfile << "		}\n";
outfile << "		th{\n";
outfile << "			background-color: darkgray;\n";
outfile << "			text-align: center;\n";

outfile << "		}\n";
outfile << "		th, td{\n";
outfile << "			border: 1px solid #dddddd;\n";
outfile << "			text-align: left;\n";
outfile << "			padding: 8px;\n";
outfile << "		}\n";
outfile << "		.divJogos{\n";
outfile << "			width: 900px;\n";
outfile << "			margin: auto;\n";
outfile << "		}\n";
outfile << "		table{\n";
outfile << "			border-collapse: collapse;\n";
outfile << "			width: 100%;\n";
outfile << "		}\n";
outfile << "	</style>\n";

outfile << "	<title>Lista de Jogos - "<<this->getNome()<<"</title>\n";
outfile << "</head>\n";
outfile << "<body>\n";
outfile << "<h2>" <<this->getNome() <<" - Biblioteca de Jogos</h2>\n";
outfile << "	<div class = \"divJogos\">\n";
outfile << "		<table>\n";
outfile << "			<tr>\n";
outfile << "				<th>N°</th>\n";
outfile << "				<th>Nome</th>\n";
outfile << "				<th>Valor</th>\n";
outfile << "				<th>Genero</th>\n";
outfile << "				<th>Instalado?</th>\n";
outfile << "			</tr>\n";

			for(unsigned int i = 0; i<this->jogosCadastrados.size();i++){
outfile << "               <tr>\n";
outfile << "				<td>"<<i+1<<"</td>\n";
outfile << "				<td>"<<jogosCadastrados[i]->getNome()<<"</td>\n";
outfile << "				<td>R$"<<jogosCadastrados[i]->getValorPromocao()<<",00</td>\n";
outfile << "				<td>"<<jogosCadastrados[i]->getGenero()->getNome()<<"</td>\n";

          if(this->jogosInstalados.empty()){
            outfile << "				<td style=\"color:red\">NAO</td>\n";
          }else{

            for(unsigned int k = 0; k<this->jogosInstalados.size();k++){



                    if(this->jogosInstalados[k]->getNome() == this->jogosCadastrados[i]->getNome()){
                             c = 1;
                             break;
                    }else{
                        c=0;
                    }



            }
            if(c==1){
                outfile << "				<td style=\"color:green\">SIM</td>\n";
            }else{
                outfile << "				<td style=\"color:red\">NAO</td>\n";
            }
          }

outfile << "			</tr>\n";


}





outfile << "		</table>\n";
outfile << "	</div>\n";

outfile << "</body>\n";
outfile << "</html>\n";


}

