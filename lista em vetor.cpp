#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
#define TAM 20

template <class MeuTipo> class Lista {
private:
    MeuTipo *vet;
    int tamanho, fim, ini;
public:
    Lista (const int &tam) {
        tamanho = tam + 1;
        vet = new MeuTipo[tamanho];
        ini = 0;
        fim = 0;
    }
    ~Lista () {
        delete [] vet;
    }
    bool vazia(void) {
        return (ini == fim);
    }
    bool cheia(void) {
        return ( ( (fim + 1) % tamanho ) == ini );
    }
    bool inserir(const int& indice, const MeuTipo& valor) {
        if(cheia()) {
            cout << "Lista Cheia!" << endl;
            return false;
        }
        if(indice >= 0 && indice < tamanho) {
            fim = (fim + 1) % tamanho;
            int ajuste = fim;
            for(ajuste = fim; ajuste != indice; ajuste = (ajuste + tamanho - 1) % tamanho){
                int anterior = (ajuste - 1 + tamanho) % tamanho;
                vet[ajuste] = vet[anterior];
            }
            vet[indice] = valor;
        }
        else{
            cout << "Posicao invalida!" << endl;
        }
        return true;
    }
    bool inserirnoinicio(const MeuTipo &valor) {
        if(cheia()) {
            cout << "Lista Cheia!" << endl;
            return false;
        }
        ini = (ini + tamanho - 1) % tamanho;
        vet[ini] = valor;
        return true;
    }
    bool inserirnofim(const MeuTipo &valor) {
        if(!cheia()) {
            vet[fim] = valor;
            fim = (fim + 1) % tamanho;
            return true;
        }
        return false;
    }
    bool excluir(const int& indice) {
        if(vazia()) {
            cout << "Lista Vazia!" << endl;
            return false;
        }
        int i;
        bool pertece = false;
        for(i = ini; i != fim; i = (i + 1) % tamanho) {
            if(i == indice) {
                pertece = true;
            }
            if(pertece) {
                int prox = (i + 1) % tamanho;
                vet[i] = vet[prox];
            }
        }
        if(pertece) {
            fim = (fim + tamanho - 1) % tamanho;
        } else {
            cout << "Não existe valor nessa posicao!" << endl;
        }
        return pertece;
    }
    bool excluirdoinicio() {
        if(vazia()) {
            return false;
        }
        ini = (ini + 1) % tamanho;
        return true;
    }
    bool excluirdofim(void) {
        if(vazia()) {
            return false;
        }
        fim = (fim + tamanho - 1) % tamanho;
        return true;
    }
    void mostrar() {
        int i;
        if(vazia()){
            cout << "A Lista esta vazia!" << endl;
        } else {
            string espaco = "";
            for(i = ini; i != fim; i = (i + 1) % tamanho) {
                cout << espaco << vet[i] << "(" << i << ")";
                espaco = " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Lista<int> L1(10);
    L1.inserirnofim(7);
    L1.inserirnoinicio(2);
    L1.inserirnofim(14);
    L1.inserirnoinicio(13);
    L1.inserirnofim(12);
    L1.inserirnoinicio(30);
    L1.mostrar();
    L1.inserir(9, 22);
    L1.mostrar();
    L1.excluir(3);
    L1.mostrar();
}