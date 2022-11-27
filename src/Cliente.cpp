#include "Cliente.hpp"

Cliente::Cliente(std::string _nome, std::string _cpf, std::string _email, std::string _telefone, 
std::string _senha, std::string _logradouro, std::string _cep, std::string _bairro, 
std::string _cidade, std::string _estado) : Usuario(_nome, _cpf, _email, _telefone, _senha){
    this->endereco = Endereco(_logradouro, _cep, _bairro, _cidade, _estado);
}
void Cliente::alterarDados(){
    std::string dado;
    std::cout<<"Digite o tipo de dado que deseja alterar: "<<std::endl;
    std::cin>>dado;
}