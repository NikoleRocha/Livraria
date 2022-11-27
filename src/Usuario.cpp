#include "Usuario.hpp"
Usuario::Usuario(std::string _nome, std::string _cpf, std::string _email, std::string _telefone, std::string _senha){
    this->Nome=_nome;
    this->CPF=_cpf;
    this->Email=_email;
    this->Telefone=_telefone;
    this->Senha=_senha;
}
void Usuario::alterarSenha(std::string _senha){
    this->Senha=_senha;
}
void Usuario::alterarTelefone(std::string _telefone){
    this->Telefone=_telefone;
}
void Usuario::alterarEmail(std::string _email){
    this->Email=_email;
}
