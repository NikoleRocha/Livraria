#include "Usuario.hpp"
Catalogo Usuario::_catalogo = Catalogo();
Catalogo Usuario::livrosVendidos = Catalogo();
int Usuario::numeroClientes = 0;
float Usuario::Saldo = 0;
float Usuario::Lucro = 0;
int Usuario::numeroCompras = 0;
Usuario::Usuario(std::string _nome, std::string _cpf, std::string _login, std::string _telefone, std::string _senha){
    this->Nome=_nome;
    this->CPF=_cpf;
    this->Login=_login;
    this->Telefone=_telefone;
    this->Senha=_senha;
}
Usuario::Usuario(){
    this->Nome="Indefinido";
    this->CPF="Indefinido";
    this->Login="Indefinido";
    this->Telefone="Indefinido";
    this->Senha="Indefinido";
}
void Usuario::setSenha(std::string _senha){
    this->Senha=_senha;
}
void Usuario::setLogin(std::string _login){
    this->Login=_login;
}
std::string Usuario::getSenha(){
    return this->Senha;
}
std::string Usuario::getLogin(){
    return this->Login;
}
bool Usuario::checkUsuario(Usuario &usuario){
    if(usuario.Login == "Indefinido")
    return false;
    else
    return true;
}

