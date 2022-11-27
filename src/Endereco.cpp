#include "Endereco.hpp"

Endereco::Endereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado){
    this->Logradouro=_logradouro;
    this->CEP=_cep;
    this->Bairro=_bairro;
    this->Cidade=_cidade;
    this->Estado=_estado;
}
Endereco::Endereco(){
    this->Logradouro="Indefinido";
    this->CEP="Indefinido";
    this->Bairro="Indefinido";
    this->Cidade="Indefinido";
    this->Estado="Indefinido";
}
void Endereco::imprimirEndereco(){
    std::cout<<Logradouro<<" "<<CEP<<" "<<Bairro<<" "<<Cidade<<" "<<Estado<<std::endl;
}
void Endereco::setLogradouro(std::string _logradouro){
    this->Logradouro=_logradouro;
}
void Endereco::setCEP(std::string _cep){
    this->CEP=_cep;
}
void Endereco::setBairro(std::string _bairro){
    this->Bairro=_bairro;
}
void Endereco::setCidade(std::string _cidade){
    this->Cidade=_cidade;
}
void Endereco::setEstado(std::string _estado){
    this->Estado=_estado;
}
void Endereco::alterarEndereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado){
    setLogradouro(_logradouro);
    setCEP(_cep);
    setBairro(_bairro);
    setCidade(_cidade);
    setEstado(_estado);
}