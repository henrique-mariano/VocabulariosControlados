#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "dominios.hpp"
#include "entidades.hpp"
#include "controle.hpp"
#include "interfaces.hpp"
#include "stubs.hpp"
#include "comandos.hpp"

#define ACESSAR_CONTA 1
#define CADASTRAR 2
#define SAIR 3

using namespace std;

int main(void){
    do{
        int escolha;
        //Controladoras
        AutenticacaoIA *cntr_ia_autenticacao;
        CadastroIA *cntr_ia_cadastro;

        cntr_ia_autenticacao = new ApresentacaoAutenticacaoControle();
        cntr_ia_cadastro = new ApresentacaoCadastroControle();

        //Stubs
        AutenticacaoIS *stub_autenticacao;
        stub_autenticacao = new StubAutenticacao();

        CadastroIS *stub_cadastro;
        stub_cadastro = new StubCadastro();

        //Link controladora-stub
        cntr_ia_autenticacao->set_aut_ia(stub_autenticacao);
        cntr_ia_cadastro->set_cadastro_ia(stub_cadastro);

        system(CLEAR);
        cout << "\tValores dos Triggers: \n";
        cout << "Email Invalido: " << StubAutenticacao::TRIGGER_FALHA_EMAIL << endl;
        cout << "Senha Invalida: " << StubAutenticacao::TRIGGER_FALHA_SENHA << endl;
        cout << "Erro Sistema Email: " << StubAutenticacao::TRIGGER_ERRO_SISTEMA_EMAIL << endl;
        cout << "Erro Sistema Senha: " << StubAutenticacao::TRIGGER_ERRO_SISTEMA_SENHA << endl;

        ResultadoUsuario resultado;

        do {
            cout << "\t\t\tVocabularios Controled\n\n";
            cout << "Escolha uma das opcoes: \n";
            cout << "1. Acessar conta\n";
            cout << "2. Cadastrar\n";
            cout << "3. Sair\n";
            cin >> escolha;
        } while(escolha > 3 || escolha < 1);

        switch (escolha) {
            case ACESSAR_CONTA: //Falta preencher com os métodos que serão chamados
                try{
                    resultado = cntr_ia_autenticacao->Autenticar();
                    switch (resultado.get_resultado()) {
                        case ResultadoUsuario::SUCESSO:
                            //chamar usuario apresentacao
                            break;
                        case ResultadoUsuario::RETORNAR:
                            continue;
                    }
                } catch (const invalid_argument &exp) {
                    cout << "Erro de sistema" << endl;
                    cout << "Pressione qualquer tecla para continuar: ";
                    fflush(stdin);
                    getchar();

                }//end try catch
                break;
            case CADASTRAR:
                try{
                    cntr_ia_cadastro->ExecutarIA();
                } catch (invalid_argument &exp) {
                    cout << "Erro de sistema" << endl;
                    cout << "Pressione qualquer tecla para continuar: ";
                    fflush(stdin);
                    getchar();

                }
                break;
            case SAIR:
                exit(0);
        }//end switch()

        delete cntr_ia_autenticacao;
        delete cntr_ia_cadastro;
        delete stub_autenticacao;
        delete stub_cadastro;
    }while(true);//do while principal

    return 0;
}