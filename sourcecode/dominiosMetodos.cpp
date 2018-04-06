#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "dominiosClasses.hpp"

using namespace std;

/*---------------------------------------------------------------------------------------------------------*/

void Nome::validation(string nome) throw (invalid_argument){

    int tamanhoVetor = nome.size();

    if(tamanhoVetor > TAM_MAX_NOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere"); //o prompt permite que não sejam inseridos caracteres?
    }

    if(nome[0] < 'A' || nome[0] > 'Z'){ 
        throw invalid_argument("A primeira letra deve ser maiuscula.");
    } else {

        for(int i = 1; i < tamanhoVetor; i++) {
            if(nome[i] < 'a' || nome[i] > 'z') { // Existem caracteces com pontuação também, como proceder?
                throw invalid_argument("Caractere invalido inserido");
            }
        } // Testa um a um os caracteres, caso não sejam caracteres minusculos, retorna um erro
        //obs: Nas especificações do trabalho não é informado se devemos considerar somente caracteres minusculos
        //nos restantes caracteres de nome.

    }

    for(int i = 0; i < tamanhoVetor; i++){
        if(nome[i] >= '0' && nome[i] <= '9'){
            throw invalid_argument("Nao é possível ter numeros no nome");
        }
    }
}

/*---------------------------------------------------------------------------------------------------------*/

void Sobrenome::validation(string sobrenome) throw (invalid_argument) {

    int tamanhoVetor = sobrenome.size();

    if(tamanhoVetor > TAM_MAX_SOBRENOME) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    if(sobrenome[0] < 'A' || sobrenome[0] > 'Z'){ 
        throw invalid_argument("A primeira letra deve ser maiuscula.");
    } else {

        for(int i = 1; i < tamanhoVetor; i++) {
            if(sobrenome[i] < 'a' || sobrenome[i] > 'z') { // Existem caracteces com pontuação também, como proceder?
                throw invalid_argument("Caractere invalido inserido");
            }
        }

    }
}

/*---------------------------------------------------------------------------------------------------------*/

void Telefone::validation(string telefone) throw (invalid_argument) {

    int tamanhoVetor = telefone.size();

    if(tamanhoVetor > TAM_MAX_TELEFONE) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
    }

    if(tamanhoVetor == STRING_VAZIA) {
        throw invalid_argument("Nao foi inserido nenhum caractere");
    }

    for(int i = 0; i < tamanhoVetor; i++){

        if(i == POS_ESPA_TELEFONE || i == POS_TRACO_TELEFONE) {
            continue;
        }

        //Utiliza tabela ascii:
        if(telefone[i] < '0' || telefone[i] > '9') { //A tabela ascii é considerada número mágico?
            throw invalid_argument("Nao foi inserido nenhum caractere");
            break;
        }
    }

    if(telefone[POS_ESPA_TELEFONE] != ' ') {
        throw invalid_argument("Fortamo Invalido. Insira o formato correto: AA BBBBB-BBBB");
    }

    if(telefone[POS_TRACO_TELEFONE] != '-') {
        throw invalid_argument("Fortamo Invalido. Insira o formato correto: AA BBBBB-BBBB");
    }


} // no formato AA numero, há uma espaço entre o AA e o número, ou não?

/*---------------------------------------------------------------------------------------------------------*/

void Endereco::validation(string endereco) throw (invalid_argument) {

    int contaEspacos = 0;
    int tamanhoVetor = endereco.size();

      if(tamanhoVetor > TAM_MAX_ENDERECO) {
        throw invalid_argument("Quantidade maxima de caracteres excedida");
     }

    if(endereco[0] == ' ') {
        throw invalid_argument("O primeiro caractere nao pode ser um espaco");
    }

    if(endereco[TAM_MAX_ENDERECO - 1] == ' ') {
        throw invalid_argument("O ultimo caractere nao pode ser um espaco");
    }

    for(int i = 1; i < TAM_MAX_ENDERECO; i++) { //começa do 1, pois o primeiro não pode ser espaço
        if(endereco[i] == ' ') {
            contaEspacos++;
        }

        if(contaEspacos == TAM_MAX_ESPAC_CONSEC) {
            throw invalid_argument("Nao podem haver dois espacos consecutivos no endereco");
        } //Chamar o throw dentro de um laço for interrompe o for e o método de exceção? 
    }

}

/*---------------------------------------------------------------------------------------------------------*/

void Data::validation(string data) throw(invalid_argument){
    int tam_string = data.size();

    if(tam_string > TAM_MAX_DATA){
        throw invalid_argument("Tamanho maximo excedido");
    }

} 