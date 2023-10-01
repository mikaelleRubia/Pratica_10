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


int main(){

    vector <Aluno> alunos;

    int limite;


    cout << "Limite de alunos"<<  endl;
    cin >> limite;

    add_aluno(alunos, limite);

    return 0;
}

void add_aluno(vector<Aluno>& alunos, int tamanho) {
    Aluno aluno_novo;
    string aux;

    for(int i = 0; i < tamanho; i++) {
        cout << "Digite o nome do aluno: ";
        cin >> aluno_novo.nome;

        cout << "Nota1 do aluno: ";
        cin >> aluno_novo.nota1;

        cout << "Nota2 do aluno: ";
        cin >> aluno_novo.nota2;

        alunos.push_back(aluno_novo);
    }
    cout << "--------------------------------" << endl; 
    
    for (int j = 0; j < tamanho - 1; j++) {
        for (int i = 0; i < tamanho - j - 1; i++) {
            if(alunos[i].nome > alunos[i + 1].nome){
                aux = alunos[i].nome;
                alunos[i].nome = alunos[i + 1].nome;
                alunos[i + 1].nome = aux;
            }
        }
    }

    for(int j = 0; j < tamanho; j++) {
        cout << "Nome do aluno: " << alunos[j].nome <<
        "\nNota1 do aluno: " << alunos[j].nota1 <<
        "\nNota2 do aluno: " << alunos[j].nota2 <<
        "\n--------------------------------" << endl; 
    }
}