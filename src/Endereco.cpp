#include "Endereco.hpp"

/**
 *
 * @brief Construtor de um objeto do tipo Endereço
 *
 * @param _logradouro Logradouro do Endereço de entrega do Cliente
 * @param _cep CEP do Endereço de entrega do Cliente
 * @param _bairro Bairro do Endereço de entrega do Cliente
 * @param _cidade Cidade do Endereço de entrega do Cliente
 * @param _estado Estado do Endereço de entrega do Cliente
 */

Endereco::Endereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado)
{
    this->Logradouro = _logradouro;
    this->CEP = _cep;
    this->Bairro = _bairro;
    this->Cidade = _cidade;
    this->Estado = _estado;
}

/**
 *
 * @brief Construtor padrão de um objeto do tipo Endereço, caracteriza as informações como indefinidas
 */

Endereco::Endereco()
{
    this->Logradouro = "Indefinido";
    this->CEP = "Indefinido";
    this->Bairro = "Indefinido";
    this->Cidade = "Indefinido";
    this->Estado = "Indefinido";
}

/**
 *
 * @brief Imprime o endereço cadastrado pelo cliente
 */

void Endereco::imprimirEndereco()
{
    std::cout << Logradouro << " " << CEP << " " << Bairro << " " << Cidade << " " << Estado << std::endl;
}

/**
 *
 * @brief Define um novo logradouro para o Endereço
 *
 * @param _logradouro Novo logradouro definido pelo Cliente
 */

void Endereco::setLogradouro(std::string _logradouro)
{
    this->Logradouro = _logradouro;
}

/**
 *
 * @brief Define um novo CEP para o Endereço
 *
 * @param _cep Novo CEP definido pelo Cliente
 */

void Endereco::setCEP(std::string _cep)
{
    this->CEP = _cep;
}

/**
 *
 * @brief Define um novo bairro para o Endereço
 *
 * @param _bairro Novo bairro definido pelo Cliente
 */

void Endereco::setBairro(std::string _bairro)
{
    this->Bairro = _bairro;
}

/**
 *
 * @brief Define uma nova cidade para o Endereço
 *
 * @param _cidade Nova cidade definida pelo Cliente
 */

void Endereco::setCidade(std::string _cidade)
{
    this->Cidade = _cidade;
}

/**
 *
 * @brief Define um novo estado para o Endereço
 *
 * @param _estado Novo estado definido pelo Cliente
 */

void Endereco::setEstado(std::string _estado)
{
    this->Estado = _estado;
}

/**
 *
 * @brief Define um novo Endereço de entrega para o CLiente
 *
 * @param _logradouro Novo logradouro definido pelo Cliente
 * @param _cep Novo CEP definido pelo Cliente
 * @param _bairro Novo bairro definido pelo Cliente
 * @param _cidade Nova cidade definida pelo Cliente
 * @param _estado Novo estado definido pelo Cliente
 */

void Endereco::alterarEndereco(std::string _logradouro, std::string _cep, std::string _bairro, std::string _cidade, std::string _estado)
{
    setLogradouro(_logradouro);
    setCEP(_cep);
    setBairro(_bairro);
    setCidade(_cidade);
    setEstado(_estado);
}