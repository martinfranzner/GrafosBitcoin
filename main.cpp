//
//  main.cpp
//  GrafosTrabalho2Bimestre
//
//  Created by Martin Franzner on 14/11/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "ReadFile.hpp"
#include "Organizer.hpp"
#include "Grafo.hpp"
#include "Pajek.hpp"
#include "GrafoAleatorio.hpp"


int menu(){
    int escolha=-1;
    cout<< "Escolha uma das opcoes"<<endl;
    cout<< "1-Gravar Grafo em Pajek"<< "      "<<"2-Ler Grafo em Pajek"<<endl;
    cout<< "3-Verificar se conexo" <<  "      "<<"4-Verificar se Euleriano"<<endl;
    cout<< "5-verificar se ha ciclo"<< "      "<<"6-Gerador de Grafo aleatorio"<<endl;
    cout<< "7-Ranking das Transacoes"<<"      "<<"0-Para encerrar o programa"<<endl;
    cin>>escolha;
    return escolha;
    
}

using namespace std;
int main(int argc, const char * argv[]) {
 
    ifstream file;
    string instructionsPath = "/Users/martinfranzner/Documents/XcodeC++/GrafosTrabalho2Bimestre/bitcoinotc.csv";
    string instructionsPath2 = "/Users/martinfranzner/Documents/XcodeC++/GrafosTrabalho2Bimestre/baseBigVoos.txt";

    vector<string> linesOfTheFile;
    ReadFile r;
    linesOfTheFile = r.readByLine(instructionsPath);
    //vector<pair<int,string>> vertices;
    vector<int> vertices;
    vector<pair<int,string>>verticesMap;
    vector<Adjacencias> adjVet;
    Organizer p;
    vertices = p.preparaVerticesAero(linesOfTheFile);
    adjVet = p.preparaAdjacencias(linesOfTheFile);
    sort(vertices.begin(), vertices.end());
    vertices.erase( unique( vertices.begin(), vertices.end() ), vertices.end() );

    int i =0;
    for(auto m :vertices){
        verticesMap.push_back(make_pair(i,to_string(m)));
        i++;
    }
    Grafo *g = new Grafo((int)vertices.size());

    for(auto it : adjVet){
        int origem = p.getOrigem(it.orig, verticesMap);
        int destino = p.getDestino(it.dest, verticesMap);
        g->criaAdjacenciaPeso(origem, destino, it.peso);


    }
    //g->imprimeAdjacencia();
    //g->euleriano();
    //g->rankingRecebidos();
    //g->rankingEnviados();
    
//    int mc;
//    mc = g->melhorCaminho(5865, 24);
//    cout<<mc<<endl;
    //Pajek pj;
    Pajek pj;
    pj.createPajek(g, verticesMap, adjVet);
    
    Grafo *gp = pj.readPajek();
    //gp->imprimeAdjacencia();
    

//        bool *visited = new bool[g->getTamanho()];
//        for (int i = 0; i < g->getTamanho(); i++)
//            visited[i] = false;
//    g->ciclo(0, visited);
//    bool *visited2 = new bool[g->getTamanho()];
//    for (int i = 0; i < g->getTamanho(); i++)
//        visited2[i] = false;
//    g->conexo(0, visited2);
//
//    g->noMaiorAdj();

    
//    //criar o grafo aleatorio conexo ou nao conexo
//    int tam=0;
//    int conex=0;
//    cout<<"Digite o numero de nos do grafo"<<endl;
//    cin>>tam;
//    cout<<"Digite 1 para conexo - 2 nao conexo"<<endl;
//    cin>>conex;
//    GrafoAleatorio ga;
//    if(conex == 1){
//        Grafo *gcon = new Grafo(tam);
//        ga.criaGrafoConexo(gcon);
//        gcon->imprimeAdjacencia();
//            bool *visited2 = new bool[tam];
//            for (int i = 0; i < tam; i++)
//                visited2[i] = false;
//        gcon->conexo(0, visited2);
//        
//    }else{
//        Grafo *gcon = new Grafo(tam);
//        ga.criaGrafoNaoConexo(gcon);
//        gcon->imprimeAdjacencia();
//        bool *visited2 = new bool[tam];
//        for (int i = 0; i < tam; i++)
//            visited2[i] = false;
//        gcon->conexo(0, visited2);
//    }
    
    int esc=menu();
    while(esc!=-1){
        if(esc==0){
            break;
        }
        if(esc==1){
            vertices = p.preparaVerticesAero(linesOfTheFile);
            adjVet = p.preparaAdjacencias(linesOfTheFile);
            sort(vertices.begin(), vertices.end());
            vertices.erase( unique( vertices.begin(), vertices.end() ), vertices.end() );
            
            int i =0;
            for(auto m :vertices){
                verticesMap.push_back(make_pair(i,to_string(m)));
                i++;
            }
            Grafo *g = new Grafo((int)vertices.size());
            
            for(auto it : adjVet){
                int origem = p.getOrigem(it.orig, verticesMap);
                int destino = p.getDestino(it.dest, verticesMap);
                g->criaAdjacenciaPeso(origem, destino, it.peso);
                
                
            }
            
            pj.createPajek(g, verticesMap, adjVet);
            
        }
        if(esc==2){// le pajek
            Grafo *gp = pj.readPajek();
        }
        if(esc==3){// verifica se conexo
            //    bool *visited2 = new bool[g->getTamanho()];
            //    for (int i = 0; i < g->getTamanho(); i++)
            //        visited2[i] = false;
            //    g->conexo(0, visited2);
        }
        if(esc==4){// verifica euler
            g->euleriano();
        }
        if(esc==5){//verifica ciclo
            bool *visited = new bool[g->getTamanho()];
            for (int i = 0; i < g->getTamanho(); i++)
                visited[i] = false;
            g->ciclo(0, visited);
        }
        if(esc==6){// gera grafo aleatorio
                //criar o grafo aleatorio conexo ou nao conexo
                int tam=0;
                int conex=0;
                cout<<"Digite o numero de nos do grafo"<<endl;
                cin>>tam;
                cout<<"Digite 1 para conexo - 2 nao conexo"<<endl;
                cin>>conex;
                GrafoAleatorio ga;
                if(conex == 1){
                    Grafo *gcon = new Grafo(tam);
                    ga.criaGrafoConexo(gcon);
                    gcon->imprimeAdjacencia();
                        bool *visited2 = new bool[tam];
                        for (int i = 0; i < tam; i++)
                            visited2[i] = false;
                    gcon->conexo(0, visited2);
            
                }else{
                    Grafo *gcon = new Grafo(tam);
                    ga.criaGrafoNaoConexo(gcon);
                    gcon->imprimeAdjacencia();
                    bool *visited2 = new bool[tam];
                    for (int i = 0; i < tam; i++)
                        visited2[i] = false;
                    gcon->conexo(0, visited2);
                }
        }
        if(esc==7){// nosso ranking
            g->rankingRecebidos();
            g->rankingEnviados();
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//
//        int size = 3;
//        Grafo *a = new Grafo(size);
//        a->criaAdjacencia(0, 1);
//        //a->criaAdjacencia(1, 0);
//        a->criaAdjacencia(0,2);
//        //a->criaAdjacencia(2,0);
//        a->criaAdjacencia(1, 2);
//        //a->criaAdjacencia(2, 1);
//        a->euleriano();
//        a->imprimeAdjacencia();
//
//        bool *visited = new bool[size];
//        for (int i = 0; i < size; i++)
//            visited[i] = false;
//    a->conexo(0, visited);
//        //a->ciclo(0, visited);
    
    
    // como o peso nao vai ser o numero de vezes que ocorre o link e sim outro paramentro nao vai mais precisar disso
    //        if(origem != -1 && destino != -1){
    //            if(g->existeAdjascencia(origem, destino)==1){
    //                //verificou a adjascencia e ja adicionou um peso a mais
    //            }
    //            else{ // aqui vai criar a adjascencia
    //                g->criaAdjacencia(origem, destino);
    //            }
    //        }
    
    return 0;
}
