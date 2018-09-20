#include <iostream>
using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
private:
	int capacidade;
	Dado *dados;
	int tamanho;
	int posTopo;
public:
	pilhav(int cap = 100);
        ~pilhav();
	void empilha(Dado valor);
	Dado desempilha();
	Dado espia(); // acessa elemento do topo, mas não retira
	void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
	void info();  // imprime informações da pilha (tamanho e  posição do topo)
};
pilhav::pilhav(int cap) : capacidade(cap){
	tamanho = 0;
	dados = new int[capacidade];
	posTopo = -1;
    
}
pilhav::~pilhav(){
	delete[] dados;
}
void pilhav::empilha(int valor){
	dados[posTopo + 1] = valor;
	++posTopo;
	++tamanho;
}
Dado pilhav::desempilha(){
	Dado removido = dados[posTopo];
	--posTopo;
	--tamanho;
	return removido;
}
Dado pilhav::espia(){
	
	if (tamanho > 0) {
		return dados[posTopo];
	}
	
	else {
		return -1;
	}
}
void pilhav::depura(){
	
	for(int i = 0; i <= posTopo; ++i){
		cout << dados[i] << ' ';
		
	}
	cout << endl;
	
}
void pilhav::info(){
	cout << tamanho << ' ' << posTopo << endl;
}

int main(){
	pilhav pilha(20);
	int n;
	for(int i = 0; i < 5; i++)
	{
		cin >> n;
		pilha.empilha(n);
	}
	cout << pilha.desempilha() <<  ' ';
	cout << pilha.desempilha() <<  ' ';
	cout << pilha.desempilha() << ' ';
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		cin >> n;
		pilha.empilha(n);
	}
	cout << pilha.desempilha() <<  ' ';
	cout << pilha.desempilha() <<  ' ';
	cout << pilha.desempilha() << ' ';
	cout << endl;
	
	cout << pilha.espia() << endl;
	pilha.depura();
	pilha.info();


		
	return 0;
}