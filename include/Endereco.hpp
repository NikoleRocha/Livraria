#ifndef ENDERECO_H
#define ENDERECO_H

#include<string>
#include<iostream>

class Endereco{
   
    private:
        std::string Logradouro;
        std::string CEP;
        std::string Bairro;
        std::string Cidade;
        std::string Estado;
   
    public:
        Endereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado);
        Endereco();
        void imprimirEndereco();
        void setLogradouro(std::string _logradouro);
        void setCEP(std::string _cep);
        void setBairro(std::string _bairro);
        void setCidade(std::string _cidade);
        void setEstado(std::string _estado);
        void alterarEndereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado);
};

#endif