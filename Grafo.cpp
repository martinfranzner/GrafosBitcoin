//
//  Grafo.cpp
//  ListaAdjacenciaGrafos
//
//  Created by Martin Franzner on 22/08/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Grafo.hpp"
#include <algorithm>
#include <list>
using namespace std;
Grafo::Grafo(int tamanho) {
    
    //list<string> * L = new list<string>();
    this->tamanho = tamanho;
    
    //this->matrizAdj = new list<int>[tamanho];
    
    this->matrizAdj = new list<No>[tamanho];
    
//    this->vertice[tamanho];
//    for(int i = 0; i < tamanho; ++i) {
//        this->vertice[i] = *new NoGrafo();
//    }

}
void Grafo::setaInformacao(){
    string nom = "";
    for(int i=0; i<tamanho; ++i){
        cout<<"Digite a informacao do no"<<endl;
        cin>>nom;
        this->vertice[i].addAdjNome(nom);
    }
}

void Grafo::imprimeInformacao(){
    for(int i=0; i<tamanho; ++i){
        cout<<i<<" - "<<this->vertice[i].getAdjNome()<<endl;
    }
}

int Grafo::existeAdjascencia(int lin, int adjasen){
    No p;
    int verifica;
    list<No>::iterator j = matrizAdj[lin].begin();
    while(j != matrizAdj[lin].end()){
        p = *j;
        verifica = p.getAdj();
        if(verifica == adjasen){
            j->addPeso1();
            return 1;
            //break;
        }
        j++;
    }
    return 0;
}

void Grafo::criaAdjacencia(int lin, int adjasen){
    //list<No>::iterator it=this->matrizAdj[adj].begin();
    No p;
    p.addPeso(1);
    p.addAdj(adjasen);
    
  
    
    this->matrizAdj[lin].push_back(p);

}
void Grafo::criaAdjacenciaPeso(int lin, int adjasen, int peso){
    //list<No>::iterator it=this->matrizAdj[adj].begin();
    No p;
    p.addPeso(peso);
    p.addAdj(adjasen);
    
    
    
    this->matrizAdj[lin].push_back(p);
    
}

void Grafo::removeAdjacencia(int lin, int col){
//        for(list<int>::iterator it=this->matrizAdj[lin].begin();it != this->matrizAdj[lin].end(); ++it){
//            advance(it,col);
//            this->matrizAdj[lin].erase(it);
//    }
    for(list<No>::iterator it=this->matrizAdj[lin].begin();it != this->matrizAdj[lin].end(); ++it){
        advance(it,col);
        this->matrizAdj[lin].erase(it);
    }
}


void Grafo::imprimeAdjacencia(){
    cout<<"-----------------------------------"<<endl;
    for(int adj=0; adj < tamanho; adj++){
        cout<<"Linha: "<<adj<<"|| ";
//        for(list<int>::iterator it=this->matrizAdj[adj].begin(); it != this->matrizAdj[adj].end(); ++it) {
//            cout<<"("<<*it<<")"<<" - ";
//
//        }
//        cout<<"\r";
        for(list<No>::iterator it=this->matrizAdj[adj].begin(); it != this->matrizAdj[adj].end(); ++it) {
            
            cout<<"("<<it->getAdj()<<")"<<(it->getPeso())<<" - ";
            
        }
        cout<<"\r";
    }
}

int Grafo::adjacentes(int linha, int v[]){
    int count = 0;
//    for(list<int>::iterator it=this->matrizAdj[linha].begin(); it != this->matrizAdj[linha].end(); ++it){
//        v[count] = *it;
//        count++;
//    }
    for(list<No>::iterator it=this->matrizAdj[linha].begin(); it != this->matrizAdj[linha].end(); ++it){
        v[count] = it->getAdj();
        count++;
    }
    return count;
}

void Grafo::DFS(int origem, bool visitado[]){
    
   
    visitado[origem] = true; //seta como true e printa
    cout << origem << " ";
    
//    list<int>::iterator it;
//    for (it = this->matrizAdj[origem].begin(); it != this->matrizAdj[origem].end(); ++it){
//        if (!visitado[*it]){
//            DFS(*it, visitado);
//        }
//    }
    list<No>::iterator it;
    for (it = this->matrizAdj[origem].begin(); it != this->matrizAdj[origem].end(); ++it){
        if (!visitado[it->getAdj()]){
            DFS(it->getAdj(), visitado);
        }
    }
    
}
bool Grafo::ciclo(int origem, bool visitado[]){
    
    if(visitado[origem] == false){
        visitado[origem] = true; //seta como true e printa
        cout << origem << " ";
        
//        list<int>::iterator it;
//        for (it = this->matrizAdj[origem].begin(); it != this->matrizAdj[origem].end(); ++it){
//            if(ciclo(*it, visitado)){
//                return true;
//            }
//       }
        list<No>::iterator it;
        for (it = this->matrizAdj[origem].begin(); it != this->matrizAdj[origem].end(); ++it){
            if(ciclo(it->getAdj(), visitado)){
                return true;
            }
        }
   }
    else {
        cout<<"Grafo Ciclico"<<endl;
        return true;
    }
    cout<<"Grafo Aciclico"<<endl;
    return true;
}

bool Grafo::conexo(int origem, bool visitado[]){
    //conex[tamanho];
    
    
    visitado[origem] = true; //seta como true e printa
    cout << origem << " ";
    
//    list<int>::iterator it;
//    for (it = this->matrizAdj[origem].begin(); it != this->matrizAdj[origem].end(); ++it){
//        if (!visitado[*it]){
//            DFS(*it, visitado);
//        }
//    }
    list<No>::iterator it;
    for (it = this->matrizAdj[origem].begin(); it != this->matrizAdj[origem].end(); ++it){
        if (!visitado[it->getAdj()]){
            DFS(it->getAdj(), visitado);
        }
    }
    
    for (int i = 0; i < tamanho; i++){
        if(visitado[i] == false){
            cout<<"Grafo nao conexo"<<endl;
            return false;
        }
    }
    cout<<"Grafo Conexo"<<endl;
    
    return true;
    
}

void Grafo::PRIM(int start){
    struct arestaPeso {
        int orig, dest, peso;
    };

    vector<arestaPeso> A;
    vector<arestaPeso> L;
    vector<int> X;
    int aux = 0;
    
    list<No>::iterator it;
    arestaPeso ap;
    arestaPeso menorPeso;
    menorPeso.peso = 99999999;
    //int itWhile = 0;
    X.push_back(start);
    int flagOrigDest = 0;
    while(X.size() < this->tamanho){
        //cout<<"X size: "<< X.size()<<endl;
        for (it = this->matrizAdj[start].begin(); it != this->matrizAdj[start].end(); ++it){
            ap.orig = start;
            ap.dest = it->getAdj();
            ap.peso = it->getPeso();
            for (int i = 0; i < L.size(); i++){
                if(L[i].dest == ap.orig && L[i].orig == ap.dest){
                    flagOrigDest = 1;
                }
            }
            if(flagOrigDest != 1){
//                if(std::find(L.begin(), L.end(), ap) != L.end()) { //checa se nao contem ja o elemento em X
//
//                } else {
//                    L.push_back(ap); /* X does not contain x */
//                }
                L.push_back(ap);
            }
            flagOrigDest = 0;
        }
        flagOrigDest = 0;
        //fazer um while que enquanto nao acrescenta nada no X
        for (int i = 0; i < L.size(); i++){
            if(L[i].peso < menorPeso.peso){
                menorPeso=L[i];
                aux = i;
            }
        }

       
        A.push_back(menorPeso);
        L.erase(L.begin()+(aux)); //eh pra remover

        
         X.push_back(menorPeso.dest);
        start = X.back();
        cout<<X.back()<<endl;
        menorPeso.peso = 999999;
        
    }

    for(int i=0; i<=A.size();i++){
        cout<<"Origem: "<<A[i].orig<<" Destino: "<<A[i].dest<<" Peso: "<<A[i].peso<<endl;
    }
    
    
}





