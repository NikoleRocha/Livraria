#include "Endereco.hpp"

Endereco::Endereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado){
    this->Logradouro=_logradouro;
    this->CEP=_cep;
    this->Bairro=_bairro;
    this->Cidade=_cidade;
    this->Estado=_estado;
}
void Endereco::imprimir_endereco(){
    std::cout<<Logradouro<<" "<<CEP<<" "<<Bairro<<" "<<Cidade<<" "<<Estado<<std::endl;
}