#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Usuario.hpp"
#include "Cliente.hpp"
#include "Catalogo.hpp"

class Administrador : public Usuario{
    public:
    Administrador(std::string _nome, std::string _cpf, std::string _login, 
    std::string _telefone, std::string _senha);
    Administrador();
    std::vector<Cliente> clientes;
    void adicionarLivroCatalogo();
    void adicionarLivroCatalogo(Livro &livro);
    void removerLivroCatalogo();
    void exibirCatalogo();
    void relatorioCompleto();
    void cadastrarCliente();
    Cliente loginCliente();

};

#endif

