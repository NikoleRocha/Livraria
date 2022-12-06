#include "Cliente.hpp"

Cliente::Cliente(std::string _nome, std::string _cpf, std::string _login, std::string _telefone,
                 std::string _senha, std::string _logradouro, std::string _cep, std::string _bairro,
                 std::string _cidade, std::string _estado) : Usuario(_nome, _cpf, _login, _telefone, _senha)
{
    this->endereco = Endereco(_logradouro, _cep, _bairro, _cidade, _estado);
    this->numeroClientes++;
    this->pedidos = Pedido();
}
Cliente::Cliente() : Usuario()
{
    this->endereco = Endereco();
    this->numeroClientes++;
    this->pedidos = Pedido();
}
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
void Cliente::exibirCarrinho()
{
    this->pedidos.gerarBoleto(&this->pedidos);
}
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
void Cliente::filtrarTitulo()
{
    std::string titulo;
    std::cout << "Digite o título do livro que deseja pesquisar: " << std::endl;
    std::getline(std::cin, titulo);
    std::getline(std::cin, titulo);
    this->_catalogo.filtroTitulo(titulo);
}
void Cliente::filtrarCodigo()
{
    int codigo;
    std::cout << "Digite o código do livro que deseja pesquisar: " << std::endl;
    std::cin >> codigo;
    this->_catalogo.filtroCodigo(codigo);
}
void Cliente::filtrarCategoria()
{
    std::string categoria;
    std::cout << "Digite a categoria do livro que deseja pesquisar: " << std::endl;
    std::getline(std::cin, categoria);
    std::getline(std::cin, categoria);
    this->_catalogo.filtroCategoria(categoria);
}