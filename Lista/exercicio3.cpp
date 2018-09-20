#include <iostream>

using namespace std;
struct Aluno{
    string nome;
    unsigned int matricula;
};

class noh{
    friend class lista;
    private:
        Aluno aluno;
        noh* proximo;
        noh* anterior;
    public:
        noh(unsigned int matricula, string nome);
};
noh::noh(unsigned int matricula, string nome) {
    proximo =  NULL;
    anterior = NULL;
    aluno.matricula = matricula;
    aluno.nome = nome;
}

class lista{
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
        int retornaPosicao(unsigned int matricula);
    public:
        lista();
        ~lista();
        void insere(unsigned int matricula, string nome);
        void remove(unsigned int posicao);
        void escreve();
        void escreveInverso();
};
lista::lista(){
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

lista::~lista(){
    noh* aux = primeiro;
    noh* temporario = aux;
    
    while(aux != NULL){
        temporario = aux;
        aux = aux->proximo;
        delete temporario;
    }
    primeiro =  NULL;
    ultimo = NULL;
}
void lista::insere(unsigned int matricula, string nome){
    noh* novo =  new noh(matricula, nome);
    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;
    }
    
    else {
        primeiro->anterior = novo;
        novo->proximo = primeiro;
        primeiro =  novo;
    }
    ++tamanho;
    
}
int lista::retornaPosicao(unsigned int matricula){
    noh* aux =  primeiro;
    bool nEncontrou = true;
    int posAux = 0;
    
    while(nEncontrou and (aux != NULL) ){
        if(matricula == aux->aluno.matricula){
            nEncontrou = false;
        }
        aux = aux->proximo;
        ++posAux;
    }
    
    if (nEncontrou) {
        return -1;
    }
    
    else{
        return posAux;
    }
    
    
}
void lista::remove(unsigned int matricula){
    
    int posicao =  retornaPosicao(matricula);
    if (posicao == -1) {
        cout << "ERRO" << endl;
    }
    else {
        noh* aux;
        
        if (posicao == 0) {
            aux = primeiro;
            primeiro->proximo->anterior = NULL;
            delete aux;
        }
        else {
            
            if (posicao == tamanho-1) {
                aux =  ultimo;
                ultimo->anterior->proximo = NULL;
                delete aux;
            }
            else {
                aux =  primeiro;
                int posAux = 0;
                
                while((posAux != posicao) and (aux != NULL)){
                    aux = aux->proximo;
                    ++posAux;
                }
                aux->proximo->anterior = aux->anterior;
                aux->anterior->proximo = aux->proximo;
                delete aux;                
            }
        }
        --tamanho;
    }
    
}
void lista::escreve(){
    noh* aux = primeiro;
    
    while(aux != NULL){
        cout << aux->aluno.matricula << ' ' << aux->aluno.nome << ' ';
        aux = aux->proximo;
    }
    cout << endl;
    
}
void lista::escreveInverso(){
    noh* aux =  ultimo;
    while(aux != NULL){
        cout << aux->aluno.matricula << ' ' << aux->aluno.nome << ' ';
        aux = aux->anterior;
    }
    cout << endl;
    
}

int main(){
    lista minhaLista;
    char opcao;
    unsigned int matricula;
    string nome;
    cin >> opcao;
    while (opcao != 't') {
        switch(opcao) {
            case 'i':
                cin >> matricula;
                cin >> nome;
                minhaLista.insere(matricula,nome);
                break;
            case 'r':
                cin >> matricula;
                minhaLista.remove(matricula);
                break;
            case 'e':
                cin >> opcao;
                
                if (opcao == 'd') {
                    minhaLista.escreve();
                }
                else{
                    if (opcao == 'r') {
                        minhaLista.escreveInverso();    
                    }
                
                }
                
                
                break;
        }
        cin >> opcao;
    }



   // "i" para inserir um aluno, seguido do número de matrícula e do nome (sem espaços)
    //"r" para remover um aluno, seguido do número de matrícula
    //"ed" para escrever o conteúdo da lista na ordem direta (do início para o fim)
    //"er" para escrever o conteúdo da lista na ordem reversa (do fim para início)
    //"t" para terminar a execução do programa


    return 0;
}