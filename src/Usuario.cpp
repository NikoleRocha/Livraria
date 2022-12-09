#include "Usuario.hpp"
Catalogo Usuario::_catalogo = Catalogo();
Catalogo Usuario::livrosVendidos = Catalogo();
int Usuario::numeroClientes = 0;
float Usuario::Saldo = 0;
float Usuario::Lucro = 0;
int Usuario::numeroCompras = 0;

/**
 *
 * @brief Contrutor de um objeto do tipo Usuario
 *
 * @param _nome Nome completo do usuário
 * @param _cpf CPF do usuário
 * @param _login Login utilizado pelo usuário para acessar sua conta
 * @param _telefone Telefone disponibilizado pelo usuário para contato
 * @param _senha Senha de acesso utlizada pelo usuário para fazer login
 */

Usuario::Usuario(std::string _nome, std::string _cpf, std::string _login, std::string _telefone, std::string _senha)
{
    this->Nome = _nome;
    this->CPF = _cpf;
    this->Login = _login;
    this->Telefone = _telefone;
    this->Senha = _senha;
}

/**
 *
 * @brief Construtor padrão do tipo Usuário, caracteriza as informações como indefinidas
 *
 */

Usuario::Usuario()
{
    this->Nome = "Indefinido";
    this->CPF = "Indefinido";
    this->Login = "Indefinido";
    this->Telefone = "Indefinido";
    this->Senha = "Indefinido";
}

/**
 *
 * @brief Define um novo valor para a senha do Usuário
 *
 * @param _senha Nova senha escolhida pelo Usuário
 */

void Usuario::setSenha(std::string _senha)
{
    this->Senha = _senha;
}

/**
 *
 * @brief Define um novo valor para o login do Usuário
 *
 * @param _senha Novo login escolhida pelo Usuário
 */

void Usuario::setLogin(std::string _login)
{
    this->Login = _login;
}

/**
 *
 * @brief Método get para a senha do Usuário
 *
 * @return Retorna a senha do Usuário
 */

std::string Usuario::getSenha()
{
    return this->Senha;
}

/**
 *
 * @brief Método get para o login do Usuário
 *
 * @return Retorna o login do Usuário
 */

std::string Usuario::getLogin()
{
    return this->Login;
}

/**
 *
 * @brief Checa se o Usuário foi cadastrado no sistema
 *
 * @return bool Retorna false caso o Usuário não esteja cadastrado e true caso contrário
 */

bool Usuario::checkUsuario(Usuario &usuario)
{
    if (usuario.Login == "Indefinido")
        return false;
    else
        return true;
}
