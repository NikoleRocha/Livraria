#ifndef USER_H
#define USER_H

#include <string>

class Usuario{
    private:
        std::string Nome;
        std::string CPF;
        std::string Email;
        std::string Telefone;
        std::string Senha;
    protected:
        Usuario(std::string _nome, std::string _cpf, std::string _email, std::string _telefone, std::string _senha);
        void alterarSenha(std::string _senha);
        void alterarTelefone(std::string _telefone);
        void alterarEmail(std::string _email);
};

#endif