#ifndef CLIENT_H
#define CLIENT_H

#include "Usuario.hpp"
#include "Endereco.hpp"

class Cliente : public Usuario{
    private:
        Endereco endereco;
    public:
        Cliente(std::string _nome, std::string _cpf, std::string _email, std::string _telefone, std::string _senha,
        std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado);
        void alterarDados();
};

#endif