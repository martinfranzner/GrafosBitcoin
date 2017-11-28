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
            //j->addPeso1();
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

bool Grafo::euleriano(){
  
    int eulerCont = 0;
    for(int i = 0; i<this->tamanho; i++){
        int j=0;
        for(auto it: this->matrizAdj[i]){
            
            j++;
        }
        //cout<<"j:"<<j<<endl;
        if((j%2) != 0){
            eulerCont++;
        }
        if(eulerCont > 2){
            cout<<"Nao eh euleriano"<<endl;
            return false;
        }
    }
    if(eulerCont == 0 || eulerCont == 2){
        cout<<"Eh euleriano"<<endl;
        return true;
    }
    else{
        cout<<"Nao eh euleriano"<<endl;
        return false;
    }
    return true;
}

//float Grafo::closeness(int indexOfNode) {
//    vector<int> pesosDosCaminhos;
//    for(auto i=0; i<this->getSize();i++)
//    {
//        if(i != indexOfNode)
//            pesosDosCaminhos.push_back(this->dijkstraAlgorithm(indexOfNode,i).second);
//    }
//    float sumOfAllWeights = accumulate(pesosDosCaminhos.begin(),pesosDosCaminhos.end(),0);
//    return 1/sumOfAllWeights;
//}


void Grafo::noMaiorAdj(){
    int aux,bigger = 0, compare = -1;
    for(int i = 0; i<this->tamanho; i++){
        aux = this->matrizAdj[i].size();
        if(aux>compare){
            compare = aux;
            bigger = i;
        }
    }
    cout<<"No com mais adj: "<<bigger<< " Num de adj: "<<this->matrizAdj[bigger].size()<<endl;
}
bool Grafo::procura(int i, int j){
    for(auto it : this->matrizAdj[i]){
        if(it.getAdj() == j)
            return true;
    }
    return false;
}

void Grafo::faz_fechamento() {
    int i, j, k;

    // inicializa��o da matriz de fechamento
    fechamento = new int*[tamanho];
    for(i = 0; i<tamanho;i++){
        this->fechamento[i] =new int[tamanho];
    }
    for (i = 0; i < this->tamanho; i++){
        for (j = 0; j < this->tamanho; j++){
            
            if (this->procura(i, j))
                fechamento[i][j] = 1;
            else
                fechamento[i][j] = 0;
        }
    }
    
    // algoritmo de Warshall
    for (k = 0; k < tamanho; k++)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (fechamento[i][k])
                for (j = 0; j < tamanho; j++)
                    fechamento[i][j] = fechamento[i][j] || fechamento[k][j];
        }
    }
}


// algoritmo de dijkstra
int Grafo::melhorCaminho(int s, int t) {

    int* distancia = new int[this->tamanho];
    bool* perm = new bool[this->tamanho];
    int* caminho = new int(this->tamanho);
    int corrente, i, k = s, dc, j = 0;
    
    faz_fechamento();
    
    if (!fechamento[s][t])
        return -1;
    
    int menordist, novadist = 0; 
    //inicializa��o
    for (i = 0; i < this->tamanho; ++i) {
        perm[i] = false;
        distancia[i] = 999999;
        caminho[i] = -1;
    }
    perm[s] = true;
    distancia[s] = 0;
    corrente = s;
    while (corrente != t) {
        menordist = 999999;
        dc = distancia[corrente];
        for (i = 0; i < this->tamanho; i++) {
            if (!perm[i]) {
                // if (l[corrente].procura(i))
                novadist = dc + this->retornaPeso(corrente, i);
                if (novadist < distancia[i]) {
                    distancia[i] = novadist;
                    caminho[i] = corrente;
                }
                if (distancia[i] < menordist) {
                    menordist = distancia[i];
                    k = i;
                }
            }
        }
        corrente = k;
        
        perm[corrente] = true;
    }
    
    //imprimirDijkstra(s, t);
    return distancia[t];
}

// imprime o caminho gerado pelo dijkstra ( inverte o caminho p/ imprimir s -> t)
//void Grafo::imprimirDijkstra(int s, int t) {
//    unsigned int i = caminho[t];
//    vector<string> inverte;
//    //cout << "Caminho detalhado: ";
//    //cout << "Destino<-" << vertices[t].get_nome() << "<-";
//    inverte.push_back(vertices[t].get_nome());
//    while (i != s) {
//        //cout << vertices[i].get_nome() << "<-";
//        inverte.push_back(vertices[i].get_nome());
//        i = caminho[i];
//    }
//    
//    //cout << vertices[s].get_nome() << "<-Origem" << endl;
//    inverte.push_back(vertices[s].get_nome());
//    
//    reverse(inverte.begin(), inverte.end());
//    
//    cout << "Caminho detalhado:" << endl << "Origem: ";
//    for (i = 0; i < inverte.size(); i++)
//        cout << inverte[i] << " -> ";
//    cout << " :Destino" << endl;
//    
//}

int Grafo::retornaPeso(int corrente, int i){

    int j=0;
    for(auto it : this->matrizAdj[corrente]){
        if(it.getAdj() == i){
            return it.getPeso();
        }
        j++;
    }
    return 999999;
}

void Grafo::rankingRecebidos(){//retorna os nos que mais receberam

    vector<pair<int,int>> vet(this->tamanho);
    for(int i=0; i<this->tamanho;i++){
        vet[i].first= i;
        vet[i].second = 0;
    }
    for(int i = 0; i<this->tamanho; i++){
        for(auto it: this->matrizAdj[i]){
            vet[it.getAdj()].second++;
        }
    }
    vector<pair<int,int>> vet20;
    

    std::sort(vet.begin(), vet.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    });
    cout<<"Ranking mais receberam transacoes"<<endl;
    for(int i = this->tamanho-1;i>(this->tamanho-20);i--){
        cout<<"No: "<<vet[i].first<<"   qtd: "<<vet[i].second<<endl;
    }
    cout<<"----------------------------"<<endl;
    
}
void Grafo::rankingEnviados(){
    vector<pair<int,int>> vet(this->tamanho);
    for(int i=0; i<this->tamanho;i++){
        vet[i].first= i;
        vet[i].second = 0;
    }
    for(int i = 0; i<this->tamanho; i++){
        vet[i].second = this->matrizAdj[i].size();
    }
    std::sort(vet.begin(), vet.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    });
    
    cout<<"Ranking mais realizaram transacoes"<<endl;
    for(int i = this->tamanho-1;i>(this->tamanho-20);i--){
        cout<<"No: "<<vet[i].first<<"   qtd: "<<vet[i].second<<endl;
    }
     cout<<"----------------------------"<<endl;
}



