#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

struct Aluno{
    string nome;
    float nota1, nota2;

};

void add_aluno(vector<Aluno>& alunos, int tamanho);
void listar_notas(vector<Aluno>& alunos);
bool verifica_lista_aluno(vector<Aluno>& alunos);
void altera_nota(vector<Aluno>& alunos);

int main(){

    vector <Aluno> alunos;
    int limite;

    do{
        cout << "Limite de alunos"<<  endl;
        cin >> limite;

    }while (limite <=0);
    

    add_aluno(alunos, limite);
    altera_nota(alunos);
    listar_notas(alunos);


    return 0;
}
bool verifica_lista_aluno(vector<Aluno>& alunos){
    if(alunos.size() <=0){
        return false;
    }
    return true;

}

void add_aluno(vector<Aluno>& alunos, int tamanho) {
    Aluno aluno_novo;
    string aux;
    char resp;
    int tamanho_vector = alunos.size(), i =0;

    do{
        
        cout << "Digite o nome do aluno: ";
        cin >> aluno_novo.nome;

        cout << "Nota1 do aluno: ";
        cin >> aluno_novo.nota1;

        cout << "Nota2 do aluno: ";
        cin >> aluno_novo.nota2;

        alunos.push_back(aluno_novo);
        i++;
        if(i < tamanho){
            cout << "Deseja excluir algum aluno (s/n)?";
            cin >> resp;
        }

        cout << "--------------------------------" << endl; 

    }while(resp == 's' && i < tamanho);
    
    for (int j = 0; j < tamanho_vector - 1; j++) {
        for (int i = 0; i < tamanho_vector - j - 1; i++) {
            if(alunos[i].nome > alunos[i + 1].nome){
                aux = alunos[i].nome;
                alunos[i].nome = alunos[i + 1].nome;
                alunos[i + 1].nome = aux;
            }
        }
    }

}

void listar_notas(vector<Aluno>& alunos){
    float media = 0.0;
    string resultado;
    int tamanho = alunos.size();

    if(!verifica_lista_aluno(alunos)){
        cout << "Lista vazia" << endl; 

    }else{
        cout << "---------------------------" << endl; 
        cout << "LISTA DE ALUNOS " << endl; 
        for(int j = 0; j < tamanho; j++) {
            media = (alunos[j].nota1 + alunos[j].nota2) /2;
            if (media >= 7){

            }
            resultado =  (media >= 7) ? "Aprovado" : (media < 7) ? "Reprovado": "valor invalido";
            cout << "Nome do aluno: " << alunos[j].nome <<
            "\nNota1 do aluno: " << alunos[j].nota1 <<
            "\nNota2 do aluno: " << alunos[j].nota2  <<
            " \nResultado da media: " << resultado <<
            "\n--------------------------------" << endl; 
        }
    }

}

void altera_nota(vector<Aluno>& alunos){
    string altera_nome;
    char altera_nota, deseja_alterar;
    int index,  tamanho = alunos.size();

    listar_notas(alunos);

    do{
        cout << "Deseja alterar alguma nota (s/n)?";
        cin >> deseja_alterar;

        if(deseja_alterar =='n'){
            break;
        }else{
            cout << "Digite o nome do aluno para atualização de nota: ";
            cin >> altera_nome;

            for(int j = 0; j < tamanho; j++) {
                if(altera_nome == alunos[j].nome){
                    index =j;
                }else if(tamanho == j && altera_nome != alunos[j].nome){
                    cout << "Aluno nao foi encontrado.";
                }
            }
            
        }

        do{
            cout << "Alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)?"<< endl;
            cin >> altera_nota;
            if(altera_nota == '1'){
                cout << "Informa o valor para atualizacao da nota1: "<< alunos[index].nota1 << endl;
                cin >> alunos[index].nota1;
                    
            }else if(altera_nota == '2'){
                cout << "Informa o valor para atualizacao da nota2: " << alunos[index].nota2 << endl;
                cin >> alunos[index].nota2;
            }
        }while(altera_nota != '0');

    }while(deseja_alterar != 'n' );
    
}