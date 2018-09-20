#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
};

// constrói uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padrão no final da lista
void lista::insere(Dado dado) {
    noh* novo = new noh(dado);
    if (vazia()) {
        primeiro =  novo;
        ultimo = novo;
    }
    else{
        ultimo->proximo = novo;
        ultimo = novo;
    }
    ++tamanho;
}

// insere um dado em uma determinada posição da lista
void lista::insere(Dado dado, int posicao) {
    if (posicao >= 0 and posicao <= tamanho)
    {
            noh* novo = new noh(dado);
            if (vazia()){
                primeiro = novo;
                ultimo = novo;
            }
            else{
                if (posicao == 0) {
                    novo->proximo = primeiro;
                    primeiro = novo;
                }
                else {
                    if (posicao == tamanho) {
                        ultimo->proximo = novo;
                        ultimo = novo;
                    }
                    else {
                        int posAux = 0;
                        noh* aux = primeiro;
                        while (posAux <= posicao -1){
                            aux = aux->proximo;
                            ++posAux;
                        }
                        novo->proximo = aux->proximo;
                        aux->proximo = novo;
                    }
                }
            }
            ++tamanho;
    }

}

// remove o item da posição passada por parâmetro
// Atenção - o código deve tratar de posição inválidas
void lista::remove(int posicao) {
    if (posicao >= 0 and posicao < tamanho) {
        if (posicao == 0) {
            noh* aux = primeiro;
            primeiro = primeiro->proximo;
            delete aux;
        }
        else {
                noh* aux =  primeiro->proximo;
                noh* anterior = primeiro;
                int posAux = 1;
                while ( (aux!= NULL) and (posAux < posicao)) {
                    anterior = aux;
                    aux = aux->proximo;
                    ++posAux;
                }
                if (aux == NULL) {
                    ultimo = anterior;
                    anterior->proximo = NULL;
                    delete aux;
                }
                else {
                    anterior->proximo = aux->proximo;
                    delete aux;
                }
            
        }
    }
    --tamanho;
}

// procura por um elemento e retorna a posição ou -1 se não encontrado
int lista::procura(Dado valor) {
    if (!vazia()) {
        noh* aux = primeiro;
        int posicao = 0;
        while (aux != NULL and valor != aux->dado ) {
            aux = aux->proximo;
            ++posicao;
        }
        if (valor == aux->dado) {
            return posicao;
        }
        else {
            return -1;
        }
    }
    else
    {
        return -1;
    }
    
    
    
}

// verifica se a lista está vazia
inline bool lista::vazia() {
    return (primeiro == NULL);
}

int main() { // NÃO MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}
