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
void add_aluno(vector <Aluno> aluno, int tamanho);


int main(){

    vector <Aluno> aluno;

    int limite;


    cout << "Limite de alunos"<<  endl;
    cin >> limite;

    add_aluno(aluno, limite);

    return 0;
}

void add_aluno(vector <Aluno> aluno, int tamanho){

    Aluno aluno_novo;

    for(int i = 0; i <tamanho; i++) {
        cout << "Digite o nome do aluno"<<  endl;
        cin >> aluno_novo.nome;

        cout << "Nota1 do aluno"<<  endl;
        cin >> aluno_novo.nota1;

        cout << "Nota2 do aluno"<<  endl;
        cin >> aluno_novo.nota2;

        aluno.push_back(aluno_novo);
    }

    for(int j = 0; j <tamanho; j++) {
        cout << "Digite o nome do aluno:"<<aluno[j].nome<<
        "\nNota1 do aluno:"<< aluno[j].nota1<<
        "\nNota2 do aluno:"<< aluno[j].nota2<<
        "\n--------------------------------"<< endl; 
    }
    

}