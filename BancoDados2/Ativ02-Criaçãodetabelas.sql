CREATE TABLE Fabrica (
Id_Fabrica INTEGER PRIMARY KEY,
Nome VARCHAR(255),
Endereco VARCHAR(255),
Cidade VARCHAR(255),
UF CHAR(2),
Telefone VARCHAR(20),
Email VARCHAR(255)
);
CREATE TABLE Produto (
Id_Produto INTEGER PRIMARY KEY,
Referencia VARCHAR(50),
Descricao VARCHAR(255),
Unidade VARCHAR(10),
Id_Fabrica INTEGER,
Id_ProdutoC INTEGER,
FOREIGN KEY (Id_Fabrica) REFERENCES Fabrica(Id_Fabrica)
);
CREATE TABLE CondPagto (
Id_Condicao INTEGER PRIMARY KEY,
Descricao VARCHAR(255)
);
CREATE TABLE Cliente (
Id_Cliente INTEGER PRIMARY KEY,
Nome VARCHAR(255),
Endereco VARCHAR(255),
Cidade VARCHAR(255),
UF CHAR(2),
Telefone VARCHAR(20),
Contato VARCHAR(255)
);
CREATE TABLE Pedido (
Id_Pedido INTEGER PRIMARY KEY,
Data DATE,
Valor DECIMAL(10, 2),
Id_Cliente INTEGER,
Id_Vendedor INTEGER,
Id_Transportadora INTEGER,
FOREIGN KEY (Id_Cliente) REFERENCES Cliente(Id_Cliente),
FOREIGN KEY (Id_Vendedor) REFERENCES Vendedor(Id_Vendedor),
FOREIGN KEY (Id_Transportadora) REFERENCES
Transportadora(Id_Transportadora)
);

CREATE TABLE Vendedor (
Id_Vendedor INTEGER PRIMARY KEY,
Nome VARCHAR(255)
);
CREATE TABLE Transportadora (
Id_Transportadora INTEGER PRIMARY KEY,
Nome VARCHAR(255),
Endereco VARCHAR(255),
Cidade VARCHAR(255),
UF CHAR(2)
);
CREATE TABLE ProdutoPedido (
Id_Pedido INTEGER,
Id_Produto INTEGER,
Quantidade INTEGER,
FOREIGN KEY (Id_Pedido) REFERENCES Pedido(Id_Pedido),
FOREIGN KEY (Id_Produto) REFERENCES Produto(Id_Produto)
);
CREATE TABLE ProdutoCond (
Id_Produto INTEGER,
Id_Condicao INTEGER,
Preco DECIMAL(10, 2),
FOREIGN KEY (Id_Produto) REFERENCES Produto(Id_Produto),
FOREIGN KEY (Id_Condicao) REFERENCES CondPagto(Id_Condicao)
);
