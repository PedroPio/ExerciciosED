#include <iostream>
#include <cstring>
using namespace std;
 

class Noh {
    friend class Deque;
    private:
        string dado;
        Noh* mPtProx;
        Noh* mPtAnt;
};

class Deque {
    public:
        // Constroi uma Deque vazia.
        Deque(unsigned int capacidade);
        // Desaloca memória de todos os nós da Deque.
        ~Deque();
        // Remove e retorna o primeiro item da Deque.
        string Remover();
        // Insere um item no final da Deque.
        void Inserir(const string& d);
        // Consulta a quantidade de itens na Deque.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a Deque está vaiza.
        bool Vazia() const;
        string RemoverFinal();
    private:
        Noh* mPrimeiro;
        Noh* mUltimo;
        unsigned int mTamanho;
        unsigned int mCapacidade;
};



Deque::Deque(unsigned int capacidade) {
    mPrimeiro = NULL;
    mUltimo = NULL;
    mTamanho = 0;
    mCapacidade = capacidade;
}

Deque::~Deque() {
    while (!Vazia()){
         Remover();
    }
    mUltimo = NULL;
    mPrimeiro = NULL;
}

void Deque::Inserir(const string& d) {
    
    if (mTamanho == mCapacidade) {
        cout << "esqueci: " << Remover() << endl;

    }
    Noh* novo  = new Noh;
    novo->mPtAnt = NULL;
    novo->mPtProx = NULL;
    novo->dado = d;
    if (Vazia()){
        mUltimo = novo;
        mPrimeiro = novo;
    }
    else {
        novo->mPtAnt = mUltimo;
        mUltimo->mPtProx = novo;
        mUltimo = novo;
    }
    ++mTamanho;
}

string Deque::Remover() {
    if (Vazia()) {
        return "ERRO";
    }
    else{
        
                
        Noh* aux = mPrimeiro;
        string retorno = aux->dado;
        if (mPrimeiro == mUltimo) {
            mPrimeiro =  NULL;
            mUltimo = NULL;
        }
        else{
            mPrimeiro = mPrimeiro->mPtProx;
            mPrimeiro->mPtAnt = NULL;
        }
        delete aux;
        --mTamanho;
        return retorno;
        
    }

    
}
string Deque::RemoverFinal(){
    if (Vazia()) {
        cout << "ERRO";
        return "ERRO";
    }
    else{
        
        Noh* aux = mUltimo;
        string retorno = aux->dado;
        
        if (mPrimeiro == mUltimo) {
            mPrimeiro  = NULL;
            mUltimo = NULL;
        }
        else{
        mUltimo = mUltimo->mPtAnt;
        mUltimo->mPtProx = NULL;
        }
        delete aux;
        --mTamanho;
        cout << "desfazer: " << retorno << endl;
        return retorno;
        
    }
}

bool Deque::Vazia() const {
    return mTamanho == 0;
}

int main() {
    unsigned int capacidade;
    cin >> capacidade;
    cin.ignore();
    Deque deque(capacidade);
    string comando;
    getline(cin,comando);
    while (comando!= "sair") {
            if (comando == "undo") {
                deque.RemoverFinal();
            }
            else {
                deque.Inserir(comando);
            }
            getline(cin,comando);
    }
              
    return 0;
}