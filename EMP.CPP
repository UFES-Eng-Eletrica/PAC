#include<string>
#include<iostream>
#include<vector>
#include<fstream>

#include "EMP.H"

using namespace std;

EmpresaDesenvolvedora::EmpresaDesenvolvedora()
{

}

EmpresaDesenvolvedora::EmpresaDesenvolvedora(string _nome)
{
    this->nome = _nome;

}

void EmpresaDesenvolvedora::CriarJogo(int tipo)
{


    string s, g;
    float v;

    cout<<"Qual o nome do jogo? "<<endl;
    cin >> s;
    cout<<"Qual o preco do jogo? "<<endl;
    cin >> v;
    cout<<"Qual o genero do jogo? "<<endl;
    cin >> g;

    if (tipo==1)
    {
        cout<<"Qual o espaco de disco requerido"<<endl;
        float Disco;
        cin>>Disco;
        while(Disco<=0)
        {
            cout<<"Qual o espaco de disco requerido"<<endl;

            cin>>Disco;
        }

        JogoPC *JPC;
        JPC = new JogoPC(s,v,g,Disco); //Ler se vai ter mult
        this->jogosDesenvolvidos.push_back(JPC);
    }

    else if (tipo==2)
    {
        cout<<"Possui multiplayer?(s) para sim e (n) para nao"<<endl;
        bool mul;
        char _mul;
        cin>>_mul;

        while(_mul!='s' && _mul!='n')
        {
            cout<<"Opçao digitada da forma errada!"<<endl;
            cout<<"Possui multiplayer?(s) para sim e (n) para nao"<<endl;
            cin>>_mul;
        }
        if(_mul == 's'){
            mul = true;
        }
        if(_mul == 'n'){
            mul = false;
        }
        JogoConsole *JC;
        JC = new JogoConsole(s,v,g,mul); //Ler se vai ter mult
        this->jogosDesenvolvidos.push_back(JC);
    }
    cout<<"Jogo criado com sucesso!!"<<endl;
}
string EmpresaDesenvolvedora::getNome()
{
    return this->nome;
}

void EmpresaDesenvolvedora::setNome(string _nome)
{
    this->nome = _nome;
}

vector<Jogo*> EmpresaDesenvolvedora::getJogosDesenvolvidos()
{
    return this->jogosDesenvolvidos;
}

void EmpresaDesenvolvedora::colocarPromo()
{
    unsigned int i;


    for (i=0; i<getJogosDesenvolvidos().size(); i++)
    {
        if(getJogosDesenvolvidos()[i]->getemPromocao()==0)
        {
            cout << "Id = " << i  <<endl;
        cout <<"\n"<<endl;
            getJogosDesenvolvidos()[i]->imprimeInfoJogo();
        }
    };
    unsigned int pos;
    cout<<"qual jogo deseja?Selecione o valor Id:"<<endl;
    cin>>pos;

    while(pos<0 || pos>getJogosDesenvolvidos().size()-1)
    {
        cout<<"qual jogo deseja?Selecione o valor Id :"<<endl;
        cin>>pos;
    }


    cout << "o jogo "<< jogosDesenvolvidos[pos]->getNome() << " custa " << jogosDesenvolvidos[pos]->getValorPromocao() << endl;

}

void EmpresaDesenvolvedora::tirarJogoPromocao()
{
    unsigned int i;



    for(i=0; i<getJogosDesenvolvidos().size(); i++)
    {
       cout << "Id = " << i  <<endl;
        cout <<"\n"<<endl;

        if(getJogosDesenvolvidos()[i]->getemPromocao()==1)
        {
            getJogosDesenvolvidos()[i]->imprimeInfoJogo();
        }


    }

    cout<<"Qual jogo deseja tirar da promocao? "<<endl;
    unsigned int pos;
    cin>>pos;

    while(pos<0 || pos>this->jogosDesenvolvidos.size()-1)
    {
        cout<<"Qual jogo deseja tirar da promocao? "<<endl;

        cin>>pos;
    }


    cout << "o jogo "<< jogosDesenvolvidos[pos]->getNome() << " custa " << jogosDesenvolvidos[pos]->getValorPromocao() << endl;





}

void EmpresaDesenvolvedora::salvarDados()
{
    unsigned int i;
    ofstream outfile;
    string nomeArquivo;

    nomeArquivo = this->nome + ".txt";
    outfile.open(nomeArquivo.c_str());

    unsigned int tamanho;

    tamanho = getJogosDesenvolvidos().size();

    outfile << tamanho <<endl;

    for(i=0; i<getJogosDesenvolvidos().size(); i++)
    {
        getJogosDesenvolvidos()[i]->salvarInfoJogo(outfile);
    }

    cout<<"Dados do jogo salvos"<<endl;

    outfile.close();
}

void EmpresaDesenvolvedora::carregarDados(string nomeArquivo)
{
    ifstream infile;
    unsigned int tam;
    string nome, genero, tipo;
    float preco, espaco;
    bool mul;

    nomeArquivo = nomeArquivo + ".txt";
    infile.open(nomeArquivo.c_str());


    infile>>tam;



    for (unsigned int i=0; i<tam; i++)
    {


        infile>>tipo;
        infile>>nome;
        infile>>preco;
        infile>>genero;

        if(tipo == "JOGOPC")
        {
            JogoPC *J;
            infile >> espaco;
            J = new JogoPC(nome, preco, genero, espaco);

            this->jogosDesenvolvidos.push_back(J);
        }
        else
        {
            JogoConsole *J;
            infile>>mul;
            J = new JogoConsole(nome, preco, genero, mul);


            this->jogosDesenvolvidos.push_back(J);
        }

    }


    infile.close();

}
