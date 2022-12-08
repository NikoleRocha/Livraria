#include <iostream>
#include "Cliente.hpp"
#include "Administrador.hpp"

bool comandoValido(int dado, int aux)
{
    if ((dado > 0) && (dado < aux))
    {
        return true;
    }
    else
        return false;
}

int main()
{
    Administrador Main;
    Livro estoque_1("Crepúsculo", "Stephenie Meyer", "Romance", 29.90, 1, 10, 14.90);
    Livro estoque_2("Lua Nova", "Stephenie Meyer", "Romance", 29.90, 2, 10, 14.90);
    Livro estoque_3("Eclipse", "Stephenie Meyer", "Romance", 29.90, 3, 10, 14.90);
    Livro estoque_4("Amanhecer", "Stephenie Meyer", "Romance", 29.90, 4, 10, 14.90);
    Livro estoque_5("50 tons de cinza", "Erika L. James", "Romance", 29.90, 5, 10, 14.90);
    Livro estoque_6("50 tons mais escuros", "Erika L. James", "Romance", 29.90, 6, 10, 14.90);
    Livro estoque_7("A coragem de ser imperfeito", "Benê Brown", "Auto ajuda", 20.0, 7, 10, 10.0);
    Livro estoque_8("Bíblia Sagrada", "Indefinido", "Livro sagrado", 50.0, 8, 10, 35.0);
    Livro estoque_9("Jojo's Bizarre Adventure : Golden Wind - Todos os volumes", "Hirohiko Araki", "Aventura", 299.90, 9, 1, 200.0);
    Livro estoque_10("Jojo's Bizarre Adventure : Stone Ocean - Todos os volumes", "Hirohiko Araki", "Aventura", 299.90, 10, 1, 200.0);
    Main.adicionarLivroCatalogo(estoque_1);
    Main.adicionarLivroCatalogo(estoque_2);
    Main.adicionarLivroCatalogo(estoque_3);
    Main.adicionarLivroCatalogo(estoque_4);
    Main.adicionarLivroCatalogo(estoque_5);
    Main.adicionarLivroCatalogo(estoque_6);
    Main.adicionarLivroCatalogo(estoque_7);
    Main.adicionarLivroCatalogo(estoque_8);
    Main.adicionarLivroCatalogo(estoque_9);
    Main.adicionarLivroCatalogo(estoque_10);
    std::cout << "Bem vindo a Livraria E-commerce! Os seguintes comandos te guiarão por nossa loja:" << std::endl;
    int tipo;
    bool continuarUsuario = true;
    while (continuarUsuario)
    {
        bool continuar = true;
        bool loginContinuar = true;
        bool _comandoValido = true;
        bool _comandoValido2 = true;
        bool _comandoValido3 = true;
        bool continuarAdmin = true;
        std::cout << "Digite 1 para acessar a loja como um cliente" << std::endl;
        std::cout << "Digite 2 para acessar a loja como um administrador" << std::endl;
        std::cout << "Digite 3 para encerrar o programa" << std::endl;
        std::cout << "Digite o tipo de usuário que deseja usar: " << std::endl;
        std::cin >> tipo;
        _comandoValido = comandoValido(tipo, 4);
        while (_comandoValido == false)
        {
            std::cout << "Comando inválido, digite o comando novamente: " << std::endl;
            std::cin >> tipo;
            _comandoValido = comandoValido(tipo, 4);
        }
        switch (tipo)
        {
        case 1:
        {
            while (continuar)
            {
                std::cout << "Bem vindo cliente! Temos disponíveis as seguintes opções inicialmente: " << std::endl;
                std::cout << "Atenção! Compras e pesquisas só podem ser realizadas após ter sido feito login!" << std::endl;
                std::cout << "Digite 1 para se cadastrar" << std::endl;
                std::cout << "Digite 2 para realizar login" << std::endl;
                std::cout << "Digite 3 para encerrar sua visita como cliente" << std::endl;
                int dado;
                std::cout << "Digite o comando desejado: " << std::endl;
                std::cin >> dado;
                _comandoValido2 = comandoValido(dado, 4);
                while (_comandoValido2 == false)
                {
                    std::cout << "Comando inválido, digite o comando novamente: " << std::endl;
                    std::cin >> dado;
                    _comandoValido2 = comandoValido(dado, 4);
                }
                switch (dado)
                {
                case 1:
                {
                    Main.cadastrarCliente();
                    break;
                }
                case 2:
                {
                    Cliente cliente = Main.loginCliente();
                    if (Main.checkUsuario(cliente) == false)
                        break;
                    std::cout << "Login realizado com sucesso" << std::endl;
                    while (loginContinuar)
                    {
                        int dadoLogin;
                        std::cout << "Bem vindo à área de login, os comandos abaixo te guiarão para as áreas desejadas:" << std::endl;
                        std::cout << "Digite 1 para visualizar o catálogo" << std::endl;
                        std::cout << "Digite 2 para adicionar um livro a seu carrinho" << std::endl;
                        std::cout << "Digite 3 para remover um livro de seu carrinho" << std::endl;
                        std::cout << "Digite 4 para visualizar seu carrinho" << std::endl;
                        std::cout << "Digite 5 para finalizar sua compra" << std::endl;
                        std::cout << "Digite 6 para filtrar o catálogo pelo título" << std::endl;
                        std::cout << "Digite 7 para filtrar o catálogo pela categoria" << std::endl;
                        std::cout << "Digite 8 para filtrar o catálogo pelo codigo" << std::endl;
                        std::cout << "Digite 9 para encerrar o programa" << std::endl;
                        std::cout << "Digite o comando desejado: " << std::endl;
                        std::cin >> dadoLogin;
                        switch (dadoLogin)
                        {
                        case 1:
                        {
                            Main.exibirCatalogo();
                            break;
                        }
                        case 2:
                        {
                            cliente.adicionarPedido();
                            break;
                        }
                        case 3:
                        {
                            cliente.retirarPedido();
                            break;
                        }
                        case 4:
                        {
                            cliente.exibirCarrinho();
                            break;
                        }
                        case 5:
                        {
                            cliente.finalizarCompra();
                            break;
                        }
                        case 6:
                        {
                            cliente.filtrarTitulo();
                            break;
                        }
                        case 7:
                        {
                            cliente.filtrarCategoria();
                            break;
                        }
                        case 8:
                        {
                            cliente.filtrarCodigo();
                            break;
                        }
                        case 9:
                        {
                            loginContinuar = false;
                            continuar = false;
                            std::cout << "Cliente encerrado com sucesso!" << std::endl;
                            break;
                        }
                        }
                    }
                    break;
                }
                case 3:
                {
                    continuar = false;
                    std::cout << "Cliente encerrado com sucesso!" << std::endl;
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            while (continuarAdmin)
            {
                std::cout << "Digite 1 para gerar o relatório completo" << std::endl;
                std::cout << "Digite 2 para adicionar um livro ao catálogo" << std::endl;
                std::cout << "Digite 3 para remover um livro do catálogo" << std::endl;
                std::cout << "Digite 4 para encerrar o programa" << std::endl;
                std::cout << "Digite o comando desejado:" << std::endl;
                int dado2;
                std::cin >> dado2;
                _comandoValido3 = comandoValido(dado2, 5);
                while (_comandoValido3 == false)
                {
                    std::cout << "Comando inválido, digite o comando novamente: " << std::endl;
                    std::cin >> dado2;
                    _comandoValido2 = comandoValido(dado2, 5);
                }
                switch (dado2)
                {
                case 1:
                {
                    Main.relatorioCompleto();
                    break;
                }
                case 2:
                {
                    Main.adicionarLivroCatalogo();
                    break;
                }
                case 3:
                {
                    Main.removerLivroCatalogo();
                    break;
                }
                case 4:
                {
                    continuarAdmin = false;
                    std::cout << "Administrador encerrado com sucesso!" << std::endl;
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            continuarUsuario = false;
            std::cout << "Programa encerrado com sucesso!" << std::endl;
            break;
        }
        }
    }
    return 0;
}
