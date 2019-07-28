
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include <windows.h>
#include "EMP.H"
#include "PLAT.H"

using namespace std;

void menu()
{
    system("cls");
    cout << "\n\n\t\t\t O que deseja fazer?\n\n\n\n"<<endl;
    cout << "\t\t\t 1 - Criar Jogo(empresa desenvolvedora)"<<endl;
    cout << "\t\t\t 2 - Colocar Jogo em Promocao"<<endl;
    cout << "\t\t\t 3 - Tirar Jogo na Promocao"<<endl;
    cout << "\t\t\t 4 - Comprar Jogo(plataforma)"<<endl;
    cout << "\t\t\t 5 - Adicionar creditos na carteira"<<endl;
    cout << "\t\t\t 6 - Instalar Jogo"<<endl;
    cout << "\t\t\t 7 - Desinstalar Jogo"<<endl;
    cout << "\t\t\t 8 - Imprimir Jogos cadastrados"<<endl;
    cout << "\t\t\t 9 - Imprimir jogos Instalados"<<endl;
    cout << "\t\t\t 10 - Imprimir Jogos Cadastrados por genero"<<endl;
    cout << "\t\t\t 11 - Presentear Plataforma"<<endl;
    cout << "\t\t\t 12 - Imprime Quantidade de Jogos"<<endl;
    cout << "\t\t\t 13 - Salvar dados(empresa)"<<endl;
    cout << "\t\t\t 14 - Salvar dados(plataforma)"<<endl;
    cout << "\t\t\t 15 - Carregar dados(empresa)"<<endl;
    cout << "\t\t\t 16 - Carregar dados(plataforma)"<<endl;
    cout << "\t\t\t 17 - Exportar Biblioteca(plataforma)"<<endl;
    cout << "\t\t\t 18 - Sair\n\n"<<endl;
}

void presenteVirtual(PlataformaDigital *presenteado, PlataformaDigital *amigo, Jogo *presente)//amigo eh quem manda o presente
{
    int k=0;//verificador
    if(amigo->getCarteiraDigital() < presente->getValorPromocao())
    {

        cout<<"saldo insuficiente"<<endl;

    }
    else
    {
        for(unsigned int i=0; i<presenteado->jogosCadastrados.size(); i++)
        {
            if(presenteado->jogosCadastrados[i]->getNome() == presente->getNome())
            {


                k = 1;
            }
        }

        if(k==1)
        {
            presenteado->AddCreditos(presente->getValorPromocao());
            amigo->AddCreditos(-presente->getValorPromocao());
            cout<<"O jogo ja esta na plataforma, o valor sera convertido em creditos!\n\n"<<endl;
        }
        else
        {
            presenteado->jogosCadastrados.push_back(presente);
            amigo->AddCreditos(-presente->getValorPromocao());
            cout<<"O jogo foi add na lista de jogos cadastrados do seu amigo"<<endl;
        }




    }

}

int retornaEmpresa(){
    cout << "Selecione uma empresa:"<<endl;
    cout << "1- Fabrizgames"<<endl;
    cout << "2- Marinagames"<<endl;
    cout << "3- Bandeiragames"<<endl;
    int opc;
    cin >> opc;
    while (opc < 1 || opc >3){
        cout << "Selecione uma empresa:"<<endl;
        cout << "1- Fabrizgames"<<endl;
        cout << "2- Marinagames"<<endl;
        cout << "3- Bandeiragames"<<endl;
        cin >> opc;
    }
    return opc-1;
}

int retornaPlataforma(){
    cout<<"selecione uma plataforma:"<<endl;
    cout<< "1 - Fabriz"<<endl;
    cout<< "2 - Marina"<<endl;
    cout<< "3 - Bandeira"<<endl;
    int opc;
    cin>>opc;
    while(opc<1 || opc>3){
    cout<<"selecione uma plataforma:"<<endl;
    cout<< "1 - Fabriz"<<endl;
    cout<< "2 - Marina"<<endl;
    cout<< "3 - Bandeira"<<endl;

    cin>>opc;
    }
    return opc-1;
}







int Jogo::qtdJogos = 0;

int main ()
{


int platSel;
int empSel;





    vector<PlataformaDigital*> plataformas;
    vector<EmpresaDesenvolvedora*> empresas;
    PlataformaDigital *plat1;
    plat1 = new PlataformaDigital("Fabriz");
    PlataformaDigital *plat2;
    plat2 = new PlataformaDigital("Marina");
    PlataformaDigital *plat3;
    plat3 = new PlataformaDigital("Bandeira");
    plataformas.push_back(plat1);
    plataformas.push_back(plat2);
    plataformas.push_back(plat3);


    EmpresaDesenvolvedora *Emp1;
    Emp1 = new EmpresaDesenvolvedora("Fabrizgames");
    EmpresaDesenvolvedora *Emp2;
    Emp2 = new EmpresaDesenvolvedora("Marinagames");
    EmpresaDesenvolvedora *Emp3;
    Emp3 = new EmpresaDesenvolvedora("Bandeiragames");
    empresas.push_back(Emp1);
    empresas.push_back(Emp2);
    empresas.push_back(Emp3);



    unsigned int x;
    while(true)
    {


        menu();
        cin>>x;

//---------------------------------------------------------------------
        if(x==1)
        {
            int tipo;

            cout<< "Qual o tipo do jogo? PC(1) ou Console (2) " << endl;
            cin >> tipo;

            while(tipo<1||tipo>2){
            cout<< "Qual o tipo do jogo? PC(1) ou Console (2) " << endl;
            cin >> tipo;
            }


            empSel = retornaEmpresa();

            empresas[empSel]->CriarJogo(tipo);



           Sleep(2000);

        }

//----------------------Funçao criar jogo logo em cima-----------------------------------------------


        if(x==4)
        {
            int k=0;
            platSel = retornaPlataforma();
            empSel = retornaEmpresa();
            if(plataformas[platSel]->getCarteiraDigital()==0){
                cout<<"voce esta com 0 creditos em sua plataforma"<<endl;

            }else if(empresas[empSel]->getJogosDesenvolvidos().empty()==true){
                cout<<"nao ha jogos desenvolvidos por essa empresa"<<endl;
            }else{

                 for(unsigned int i=0;i<empresas[empSel]->getJogosDesenvolvidos().size();i++){

                    cout << "\n\nId = " << i<<endl;
                            cout <<"\n"<<endl;
                    empresas[empSel]->getJogosDesenvolvidos()[i]->imprimeInfoJogo();

                    cout<<"\n\n"<<endl;

            }
                    unsigned int pos;
                    cout<<"Qual jogo deseja comprar?"<<endl;
                    cin>>pos;
                while(pos<0 || pos>empresas[empSel]->getJogosDesenvolvidos().size()-1){
                    cout<<"Qual jogo deseja comprar?"<<endl;
                    cin>>pos;
                }

                for(unsigned int c=0;c<plataformas[platSel]->getJogosCadastrados().size();c++){
                    if(plataformas[platSel]->getJogosCadastrados()[c]->getNome()==empresas[empSel]->getJogosDesenvolvidos()[pos]->getNome()){
                        k=1;
                        break;
                    }else{
                        k=0;
                    }
                }
                if(k==1){
                    cout<<"esse jogo ja foi comprado"<<endl;
                }else{


                plataformas[platSel]->ComprarJogo(empresas[empSel]->getJogosDesenvolvidos()[pos]);

                }
            }






   Sleep(2000);





        };
        //Todos esse condicionais foram para selecionar as plataformas e Empresas que o usuário escolheu, para comprar o jOGO.
//------------------------------------------------------------------------------





        if(x==5)
        {

            float Valor;
            cout<<"Quanto deseja add na carteira? "<<endl;
            cin >> Valor;

            while(Valor < 0){
                cout<<"valor digitado incorreto"<<endl;
                cout<<"Quanto deseja add na carteira? "<<endl;
            cin >> Valor;
            }

            platSel = retornaPlataforma();

            plataformas[platSel]->AddCreditos(Valor);

            cout <<"Seu saldo agora eh: "<< plataformas[platSel]->getCarteiraDigital()<<endl;


           Sleep(2000);

            //---------------------------------------------------------------------------------------------


        };

        if(x==6)
        {
            platSel = retornaPlataforma();

            if(plataformas[platSel]->getJogosCadastrados().empty()){
                cout<<"nao ha jogos cadastrados para instalar"<<endl;
            }else{



        plataformas[platSel]->instalarJogo();
            }
        //--------------------------------------------------------------


       Sleep(2000);
        };
        //-------------------------------------------------------
        if(x==7)
        {
            platSel = retornaPlataforma();



        plataformas[platSel]->desinstalarJogo();



           Sleep(2000);

        };
        //---------------------------------------------
        if(x==8)
        {
            platSel = retornaPlataforma();
            if(plataformas[platSel]->getJogosCadastrados().empty()==true){
            cout<<"Nao tem jogos cadastrados p imprimir"<<endl;
        }else{

        plataformas[platSel]->ImprimeJogosCadastrados();

        }
           Sleep(2000);

        };
        //---------------------------------------------------------------------------
        if(x==9)
        {
            platSel = retornaPlataforma();
        if(plataformas[platSel]->getJogosInstalados().empty()){
            cout<<"Nao tem jogos instalados p imprimir"<<endl;
        }else{

        plataformas[platSel]->ImprimeJogosInstalados();
        }

       Sleep(2000);
        }
        //------------------------------------------------------------------------------
        if(x==10)
        {
            platSel = retornaPlataforma();

            if(plataformas[platSel]->getJogosCadastrados().empty()==true){
            cout<<"Nao tem jogos cadastrados p imprimir"<<endl;
        }else{
            string g;
            cout << "Infome o genero desejado: ";
            cin >> g;
        plataformas[platSel]->ImprimeJogos(g);

        }
           Sleep(2000);

        };

        //--------------------------------------------------------------------------------------

        if(x==11)//***********
        {
            int platpresente;
            unsigned int pos;

            platSel = retornaPlataforma();
            cout<<"qual plataforma será presenteada?"<<endl;
            platpresente = retornaPlataforma();

            empSel = retornaEmpresa();
            while(empresas[empSel]->getJogosDesenvolvidos().size()==0){

              empSel = retornaEmpresa();
            }

            if(empresas[empSel]->getJogosDesenvolvidos().empty()){
                cout<<"nao tem jogos desenvolvidos nessa empresa"<<endl;
            }else{



            for(unsigned int i=0;i<empresas[empSel]->getJogosDesenvolvidos().size();i++){
                            cout << "\n\nId = " << i<<endl;
                            cout <<"\n"<<endl;
                        empresas[empSel]->getJogosDesenvolvidos()[i]->imprimeInfoJogo();
                    }
                            cout<<"Qual jogo voce deseja mandar como presente?"<<endl;
                            cin>>pos;
                        while(pos<0 || pos>empresas[empSel]->getJogosDesenvolvidos().size()-1){
                            cout<<"Qual jogo você deseja mandar como presente?"<<endl;
                            cin>>pos;
                        }

                        presenteVirtual(plataformas[platpresente], plataformas[platSel], empresas[empSel]->getJogosDesenvolvidos()[pos]);

            }
            //---------------------------------------------

               Sleep(2000);
            };






        if(x==12)
        {
            Jogo::imprimeQtdJogos();
           Sleep(2000);

        };

        if(x==2)
        {


            empSel = retornaEmpresa();

            if(empresas[empSel]->getJogosDesenvolvidos().empty()){
                cout<<"nao ha jogos desenvolvidos pela empresa selecionada"<<endl;
            }else{
                empresas[empSel]->colocarPromo();
            }

           Sleep(2000);
            //main();

        };
        if(x==18)//**********
        {
            cout << "\nFim do programa!\n\n";
            delete plat1;
            delete plat2;
            delete plat3;
            delete Emp1;
            delete Emp2;
            delete Emp3;
            return 0; //encerra o programa
        }
        if(x==13){
            empSel = retornaEmpresa();

            empresas[empSel]->salvarDados();


            Sleep(2000);
        }

        if(x==15){
            empSel = retornaEmpresa();

            ifstream infile;
            string nomedoarquivo;

            nomedoarquivo = empresas[empSel]->getNome() + ".txt";

            infile.open(nomedoarquivo.c_str());



            if (!infile.is_open()){
                cout << "erro na hora de abrir o arquivo" << endl;

                cout << "nao tem dados p carregar nessa empresa!" << endl;
                exit(1);
                        }
                        else{

                            infile.close();

                            Jogo::qtdJogos = Jogo::qtdJogos - empresas[empSel]->getJogosDesenvolvidos().size();
                            nomedoarquivo = empresas[empSel]->getNome();
                            delete empresas[empSel];
                            empresas[empSel] = new EmpresaDesenvolvedora(nomedoarquivo);
                            empresas[empSel]->carregarDados(nomedoarquivo);
                            cout << "Jogos carregados para a empresa " << endl;



                        }
                         Sleep(2000);

        }
        if(x==14){
            platSel = retornaPlataforma();

            plataformas[platSel]->SalvarDados();

            Sleep(2000);
        }
        if(x==16){

            platSel = retornaPlataforma();

            ifstream infile;
            string nomeArquivo;

            nomeArquivo = plataformas[platSel]->getNome() + ".txt";

            infile.open(nomeArquivo.c_str());

            if (!infile.is_open()){
                cout << "erro na hora de abrir o arquivo" << endl;

                cout << "nao tem dados p carregar nessa empresa!" << endl;
                exit(1);
                        }
                        else{

                            infile.close();


                            nomeArquivo = plataformas[platSel]->getNome();
                            delete plataformas[platSel];
                            plataformas[platSel] = new PlataformaDigital(nomeArquivo);
                            plataformas[platSel]->CarregarDados(nomeArquivo);
                            cout << "Jogos carregados para a plataforma" << endl;



                        }
                         Sleep(2000);
        }
        if(x==17){
            platSel = retornaPlataforma();

            plataformas[platSel]->ExportarBiblioteca();

            cout<<"Arquivo HTML salvo no diretorio!!!"<<endl;
            Sleep(2000);
        }
        if(x==3){
            empSel = retornaEmpresa();

            if(empresas[empSel]->getJogosDesenvolvidos().empty()){
                cout<<"nao ha jogos desenvolvidos pela empresa selecionada"<<endl;
            }else{
                empresas[empSel]->tirarJogoPromocao();
            }

           Sleep(2000);
        }




    }

    }



