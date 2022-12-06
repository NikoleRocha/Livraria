#ifndef USER_H
#define USER_H

#include <string>
#include "Catalogo.hpp"
class Usuario{
    public:
        std::string Nome;
        std::string CPF;
        std::string Login;
        std::string Telefone;
        std::string Senha;
        static int numeroClientes;
        static Catalogo _catalogo;
        static Catalogo livrosVendidos;
        static float Saldo;
        static float Lucro;
        static int numeroCompras;
        public:
        Usuario(std::string _nome, std::string _cpf, std::string _login, std::string _telefone, std::string _senha);
        Usuario();
        void setSenha(std::string _senha);
        void setLogin(std::string _login);
        std::string getSenha();
        std::string getLogin();
        bool checkUsuario(Usuario &usuario);
};

#endif