/* 1 A tabela ATLETA tem um campo denominado SEXO. Crie um domínio para esse
campo de modo que ele aceite apenas M (para masculino) ou F (para feminino) como
sexo, que seja char(1) e não nulo. */

create domain tipo_sexo as char(1) check (value in('F','M'))NOT NULL;

/* 2 A tabela EMPREGADO tem um campo denominado SALARIO. Crie um domínio para
esse campo limitando os valores inseridos de forma que sejam maiores que 300.00 e
menores que 5000.00 e não nulo. */

create domain tipo_salario as decimal(10, 2) check (value > 300.00 and value < 5000.00)
not null;

/* 3 Crie um domínio para o campo TotalNF da tabela Venda, de tal forma que ele cheque
que o valor inserido no campo seja sempre preenchido e positivo: */

create domain tipo_TotalINF as decimal (10,2) check (value>0) not null;

/* 4. Crie um domínio para o campo Data da tabela Compra, de tal forma que ele cheque
que o valor inserido no campo seja maior ou igual a data atual. */

create domain tipo_Compra as data check ( value current_date) not null;

/* 05)ALTER DOMAIN TIPO_SEXO TO ATLETA_SEXO; */

alter domain tipo_sexo to atleta_sexo;

/*6 . Crie um domínio para todos os NOMES do banco de dados com no máximo 40
caracteres. */

create domain tipo_NOMES as varchar(40);

/* 7. Altere o domínio para todos os NOMES do banco de dados para o máximo de 50
caracteres.*/

create domain tipo_NOMES as varchar(50);
