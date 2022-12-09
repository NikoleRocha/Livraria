#include "Cliente.hpp"

/**
 *
 * @brief Construtor de um objeto de tipo Cliente e contador do número de clientes cadastrados
 *
 * @param _nome Nome completo do usuário
 * @param _cpf CPF do usuário
 * @param _login Login utilizado pelo usuário para acessar sua conta
 * @param _telefone Telefone disponibilizado pelo usuário para contato
 * @param _senha Senha de acesso utlizada pelo usuário para fazer login
 * @param _logradouro Logradouro do Endereço de entrega do Cliente
 * @param _cep CEP do Endereço de entrega do Cliente
 * @param _bairro Bairro do Endereço de entrega do Cliente
 * @param _cidade Cidade do Endereço de entrega do Cliente
 * @param _estado Estado do Endereço de entrega do Cliente
 */

Cliente::Cliente(std::string _nome, std::string _cpf, std::string _login, std::string _telefone,
                 std::string _senha, std::string _logradouro, std::string _cep, std::string _bairro,
                 std::string _cidade, std::string _estado) : Usuario(_nome, _cpf, _login, _telefone, _senha)
{
    this->endereco = Endereco(_logradouro, _cep, _bairro, _cidade, _estado);
    this->numeroClientes++;
    this->pedidos = Pedido();
}

/**
 *
 * @brief Construtor padrão de um objeto do tipo Cliente e contador do número de clientes cadastrados, caracteriza as informações como indefinidas
 */

Cliente::Cliente() : Usuario()
{
    this->endereco = Endereco();
    this->numeroClientes++;
    this->pedidos = Pedido();
}

/**
 *
 * @brief Altera os dados escolhidos pelo cliente
 */

void Cliente::alterarDados()
{
    std::string dado;
    std::cout << "Digite o tipo de dado que deseja alterar: " << std::endl;
    std::cin >> dado;
    if (dado == "Endereço")
    {
        std::string novoLogradouro;
        std::string novoCep;
        std::string novoBairro;
        std::string novaCidade;
        std::string novoEstado;
        std::cout << "Digite o novo logradouro:" << std::endl;
        std::getline(std::cin, novoLogradouro);
        std::getline(std::cin, novoLogradouro);
        std::cout << "Digite o novo CEP:" << std::endl;
        std::getline(std::cin, novoCep);
        std::cout << "Digite o novo bairro:" << std::endl;
        std::getline(std::cin, novoBairro);
        std::cout << "Digite o novo cidade:" << std::endl;
        std::getline(std::cin, novaCidade);
        std::cout << "Digite o novo estado:" << std::endl;
        std::getline(std::cin, novoEstado);
        this->endereco.alterarEndereco(novoLogradouro, novoCep, novoBairro, novaCidade, novoEstado);
        std::cout << "O novo endereço é: ";
        this->endereco.imprimirEndereco();
    }
    if (dado == "Senha")
    {
        std::cout << "Digite a nova senha: " << std::endl;
        std::string novaSenha;
        std::cin >> novaSenha;
        Cliente::setSenha(novaSenha);
    }
}

/**
 *
 * @brief Adiciona um ou mais livros ao carrinho do Cliente
 */

void Cliente::adicionarPedido()
{
    std::string comando = "y";
    int cod;
    while (comando == "y")
    {
        std::cout << "Digite o código do livro a ser adicionado no carrinho: " << std::endl;
        std::cin >> cod;
        for (vector<Livro>::iterator it = _catalogo.livrosEstoque.begin();
             it != _catalogo.livrosEstoque.end(); it++)
        {
            if (it->getCodigoLivro() == cod)
            {
                this->pedidos.adicionarLivro(*it);
                std::cout << "Livro adicionado ao carrinho" << std::endl;
            }
        }
        std::cout << "Deseja adicionar outro livro ao seu carrinho?" << std::endl;
        std::cout << "Digite y para confirmar e n para sair do carrinho" << std::endl;
        std::cin >> comando;
        while (comando != "y")
        {
            if (comando == "n")
                break;
            std::cout << "Comando inválido! Digite o comando novamente: " << std::endl;
            std::cin >> comando;
            if (comando == "n")
                break;
        }
    }
}

/**
 *
 * @brief Remove um ou mais livros do carrinho do Cliente
 */

void Cliente::retirarPedido()
{
    std::string comando = "y";
    int cod;
    while (comando == "y")
    {
        std::cout << "Digite o código do livro a ser retirado do carrinho: " << std::endl;
        std::cin >> cod;
        this->pedidos.removerLivro(cod);
        std::cout << "livro removido com sucesso" << std::endl;
        std::cout << "Deseja remover outro livro do seu carrinho?" << std::endl;
        std::cout << "Digite y para confirmar e n para sair do carrinho" << std::endl;
        std::cin >> comando;
        while (comando != "y")
        {
            if (comando == "n")
                break;
            std::cout << "Comando inválido! Digite o comando novamente: " << std::endl;
            std::cin >> comando;
            if (comando == "n")
                break;
        }
    }
}

/**
 *
 * @brief Exibe os livros presentes no carrinho do Cliente, é lançada uma exceção caso esteja vazio
 */

void Cliente::exibirCarrinho()
{
    this->pedidos.gerarBoleto(&this->pedidos);
}

/**
 *
 * @brief Finaliza a compra do cliente, diminuindo a quantidade disponível dos livros comprados e imprimindo os detalhes da compra
 */

void Cliente::finalizarCompra()
{
    Saldo += this->pedidos.calcularValorCompra();
    Lucro += this->pedidos.calcularLucroCompra();
    numeroCompras++;
    std::cout << "Número de itens comprados" << this->pedidos._livrosSalvos.size() << std::endl;
    this->pedidos.gerarBoleto(&this->pedidos);
    std::cout << "Obrigado pela preferência! Nós d E-commerce esperamos te ver novamente :D!" << std::endl;
    int tamanho = this->pedidos._livrosSalvos.size();
    for (int i = 0; i < tamanho; i++)
    {
        this->livrosVendidos.livrosEstoque.push_back(this->pedidos._livrosSalvos[i]);
        this->pedidos.removerLivro(this->pedidos._livrosSalvos[i].getCodigoLivro());
        for (vector<Livro>::iterator it = _catalogo.livrosEstoque.begin();
             it != _catalogo.livrosEstoque.end(); it++)
        {
            it->setQuantidadeLivro(it->getQuantidadeLivro() - 1);
        }
    }
}

/**
 *
 * @brief Filtra o catálogo com base no título escolhido
 */

void Cliente::filtrarTitulo()
{
    std::string titulo;
    std::cout << "Digite o título do livro que deseja pesquisar: " << std::endl;
    std::getline(std::cin, titulo);
    std::getline(std::cin, titulo);
    this->_catalogo.filtroTitulo(titulo);
}

/**
 *
 * @brief Filtra o catálogo com base no código do livro escolhido
 */

void Cliente::filtrarCodigo()
{
    int codigo;
    std::cout << "Digite o código do livro que deseja pesquisar: " << std::endl;
    std::cin >> codigo;
    this->_catalogo.filtroCodigo(codigo);
}

/**
 *
 * @brief Filtra o catálogo com base na categoria escolhido
 */

void Cliente::filtrarCategoria()
{
    std::string categoria;
    std::cout << "Digite a categoria do livro que deseja pesquisar: " << std::endl;
    std::getline(std::cin, categoria);
    std::getline(std::cin, categoria);
    this->_catalogo.filtroCategoria(categoria);
}
