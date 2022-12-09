#include "Administrador.hpp"

/**
 *
 * @brief Contrutor de um objeto do tipo Administrador
 *
 * @param _nome Nome completo do usuário
 * @param _cpf CPF do usuário
 * @param _login Login utilizado pelo usuário para acessar sua conta
 * @param _telefone Telefone disponibilizado pelo usuário para contato
 * @param _senha Senha de acesso utlizada pelo usuário para fazer login
 */

Administrador::Administrador(std::string _nome, std::string _cpf, std::string _login, std::string _telefone,
                             std::string _senha) : Usuario(_nome, _cpf, _login, _telefone, _senha) {}

/**
 *
 * @brief Construtor padrão de um objeto do tipo Administrador, carazteriza as informações como indefinidas
 */

Administrador::Administrador() : Usuario() {}

/**
 *
 * @brief Adiciona um livro existente ao catálogo
 *
 * @param livro Livro a ser adicionado ao catálogo
 */

void Administrador::adicionarLivroCatalogo(Livro &livro)
{
    this->_catalogo.livrosEstoque.push_back(livro);
}

/**
 *
 * @brief Cria um novo objeto do tipo Livro e o adiciona ao catálogo
 */

void Administrador::adicionarLivroCatalogo()
{
    std::string _titulo;
    std::string _autor;
    std::string _genero;
    int _codigo;
    int _quantidade;
    double _custo;
    double _valorVenda;
    Livro _livro;
    std::cout << "Digite o título do livro: " << std::endl;
    std::getline(std::cin, _titulo);
    std::getline(std::cin, _titulo);
    std::cout << "Digite o nome do autor do livro: " << std::endl;
    std::getline(std::cin, _autor);
    std::cout << "Digite o gênero do livro: " << std::endl;
    std::getline(std::cin, _genero);
    std::cout << "Digite o código do livro: " << std::endl;
    std::cin >> _codigo;
    std::cout << "Digite a quantidade de livros a ser disponibilizada: " << std::endl;
    std::cin >> _quantidade;
    std::cout << "Digite o valor de custo de compra do livro: " << std::endl;
    std::cin >> _custo;
    std::cout << "Digite o valor no qual o livro será vendido: " << std::endl;
    std::cin >> _valorVenda;
    _livro = Livro(_titulo, _autor, _genero, _valorVenda, _codigo, _quantidade, _custo);
    this->_catalogo.livrosEstoque.push_back(_livro);
}

/**
 *
 * @brief Remove um livro do catálogo pelo código
 */

void Administrador::removerLivroCatalogo()
{
    int _cod;
    std::cout << "Digite o código do livro a ser retirado do catálogo: " << endl;
    std::cin >> _cod;
    for (vector<Livro>::iterator it = _catalogo.livrosEstoque.begin();
         it != _catalogo.livrosEstoque.end(); it++)
    {
        if (it->getCodigoLivro() == _cod)
        {
            _catalogo.livrosEstoque.erase(it);
            std::cout << "Todos os exemplares do livro " << it->getTituloLivro() << " foram removidos com sucesso" << std::endl;
            break;
        }
        else
        {

            std::cout << "O código digitado não pertence a nenhum livro presente no catálogo" << endl;
            break;
        }
    }
}

/**
 *
 * @brief Exibe o catálogo completo disponível
 */

void Administrador::exibirCatalogo()
{
    this->_catalogo.imprimirLivrosEstoque();
}

/**
 *
 * @brief Imprime um relatório completo da loja, contendo o saldo total e lucro da loja, além de informações sobre as vendas e clientes
 */

void Administrador::relatorioCompleto()
{
    if (this->numeroClientes == 1)
        std::cout << "Foi cadastrado apenas " << this->numeroClientes << " cliente desde a última verificação" << std::endl;
    else if (this->numeroClientes == 0)
        std::cout << "Nenhum cliente foi cadastrado desde a última verificação" << std::endl;
    else
        std::cout << "Foram cadastrados " << this->numeroClientes << " clientes desde a última verificação" << std::endl;
    this->numeroClientes = 0;
    if (numeroCompras == 0)
        std::cout << "Não foram realizadas compras desde a última verificação" << std::endl;
    if (numeroCompras == 1)
        std::cout << "Foi realizada " << this->numeroCompras << " compra desde a últimas verificação" << std::endl;
    else
        std::cout << "Foram realizadas " << this->numeroCompras << " compras desde a últimas verificação" << std::endl;
    std::cout << "O saldo disponpivel desde a última verificação é de: " << Saldo << std::endl;
    std::cout << "O lucro obtido desde a última verificação é de: " << Lucro << std::endl;
    this->Lucro = 0;
    if (livrosVendidos.livrosEstoque.empty())
        std::cout << "Nenhum livro foi vendido desde a última verificação" << std::endl;
    else
    {
        std::cout << "Os seguintes livros foram vendidos desde a abertura da loja: " << std::endl;
        this->livrosVendidos.imprimirLivrosEstoque();
    }
}

/**
 *
 * @brief Cadastra um cliente, criando um novo objeto do tipo cliente e o adicionando a um vetor de clientes
 */

void Administrador::cadastrarCliente()
{
    std::string nomeCliente;
    std::string cpfCliente;
    std::string loginCliente;
    std::string senhaCliente;
    std::string telefoneCliente;
    std::string logradouroCliente;
    std::string cepCliente;
    std::string bairroCliente;
    std::string cidadeCliente;
    std::string estadoCliente;
    std::cout << "Digite as seguintes informações pessoais: " << std::endl;
    std::cout << "Digite o seu nome completo: " << std::endl;
    std::getline(std::cin, nomeCliente);
    std::getline(std::cin, nomeCliente);
    std::cout << "Digite o seu login: " << std::endl;
    std::getline(std::cin, loginCliente);
    std::cout << "Digite a sua senha: " << std::endl;
    std::getline(std::cin, senhaCliente);
    std::cout << "Digite o seu CPF: " << std::endl;
    std::getline(std::cin, cpfCliente);
    std::cout << "Digite o seu telefone: " << std::endl;
    std::getline(std::cin, telefoneCliente);
    std::cout << "Digite as seguintes informações sobre o endereço de entrega: " << std::endl;
    std::cout << "Digite o nome de seu logradouro: " << std::endl;
    std::getline(std::cin, logradouroCliente);
    std::cout << "Digite o seu CEP: " << std::endl;
    std::getline(std::cin, cepCliente);
    std::cout << "Digite o nome de seu bairro: " << std::endl;
    std::getline(std::cin, bairroCliente);
    std::cout << "Digite o nome de sua cidade: " << std::endl;
    std::getline(std::cin, cidadeCliente);
    std::cout << "Digite o nome de seu estado: " << std::endl;
    std::getline(std::cin, estadoCliente);
    this->clientes.push_back(Cliente(nomeCliente, cpfCliente, loginCliente, telefoneCliente, senhaCliente, logradouroCliente, cepCliente, bairroCliente, cidadeCliente, estadoCliente));
    std::cout << "Cliente cadastrado com sucesso" << std::endl;
}

/**
 * @brief Faz o login de um cliente usando suas credênciais, percorrendo o vetor clientes de clientes cadastrados
 *
 * @return Cliente Retorna um objeto do tipo Cliente, caso esteja cadastrado, retorna o cliente cadastrado, caso contrário, retorna um cliente indefinido
 */

Cliente Administrador::loginCliente()
{
    std::string login;
    std::string senha;
    std::cout << "Digite o login cadastrado no site: " << std::endl;
    std::cin >> login;
    std::cout << "Digite a senha cadastrada no site: " << std::endl;
    std::cin >> senha;
    for (vector<Cliente>::iterator it = clientes.begin();
         it != clientes.end(); it++)
    {
        if ((it->getLogin() == login) && (it->getSenha() == senha))
        {
            return *it;
            break;
        }
    }
    std::cout << "Credênciais erradas! Pressione o comando 2 para tentar realizar login novamente" << std::endl;
    return Cliente();
}