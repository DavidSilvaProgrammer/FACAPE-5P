/* 1) Selecione todos os nomes dos Itens pertencentes ao grupo dos alimentos
Perecíveis.*/

SELECT item.nome
FROM item
JOIN grupo ON item.codgrupo = grupo.codgrupo
WHERE grupo.nome LIKE '%ALIMENTOS PERECÍVEIS';

/*  2) Para cada venda, mostre o número da nota fiscal, total da nota, data, nome do
cliente e o nome do vendedor que efetuou a venda.*/

SELECT venda.numnf, venda.totalnf, venda.data, cliente.nomecli, vendedor.nomevend
FROM venda
JOIN cliente ON venda.codcliente = cliente.codcliente
JOIN vendedor ON venda.codvendedor = vendedor.codvendedor;

/* 3) Selecione as notas fiscais cuja quantidade de itens vendidos, tenham ultrapassado
a 90% da quantidade em estoque deste mesmo item.*/

SELECT item_venda.numnf
FROM item_venda
JOIN item ON item_venda.coditem = item.coditem
WHERE item_venda.qtde >= 0.9 * (
SELECT qtdeestoque
FROM item
WHERE item.coditem = item_venda.coditem
);

/* 4) Para cada cliente, mostre o nome e suas notas fiscais com valor mais alto e com o
valor mais baixo.*/

SELECT cliente.nomecli,
max_nf.numnf AS nota_fiscal_maxima,
max_nf.max_totalnf AS valor_maximo,
min_nf.numnf AS nota_fiscal_minima,
min_nf.min_totalnf AS valor_minimo
FROM cliente
LEFT JOIN (
SELECT venda.codcli,
MAX(venda.totalnf) AS max_totalnf,
FIRST(1) AS numnf -- assumindo que FIRST(1) retorna a primeira nota fiscal
associada ao valor máximo
FROM venda

GROUP BY venda.codcli
) AS max_nf ON cliente.codcli = max_nf.codcli
LEFT JOIN (
SELECT venda.codcli,
MIN(venda.totalnf) AS min_totalnf,
FIRST(1) AS numnf -- assumindo que FIRST(1) retorna a primeira nota fiscal
associada ao valor mínimo
FROM venda
GROUP BY venda.codcli
) AS min_nf ON cliente.codcli = min_nf.codcli;

/*  5) Para cada tipo de cliente, mostre quantos clientes existem.*/

SELECT tipo_cliente.desctipocli, COUNT(cliente.codtipocli) AS total_clientes
FROM cliente
JOIN tipo_cliente ON tipo_cliente.codtipocli = cliente.codtipocli
GROUP BY tipo_cliente.codtipocli, tipo_cliente.desctipocli;

/* 6) Mostre o código do item, seu nome, a quantidade do item vendida, seu preço
unitário e o total de cada item vendido.*/

SELECT item_venda.numnf, item.coditem, item.nome, item_venda.qtde, item.valorunit,
(item_venda.qtde * item.valorunit) AS "VALOR TOTAL"
FROM item
JOIN item_venda ON item.coditem = item_venda.coditem;

/*7) Selecione todas as notas que tenham o mesmo valor que a média dos valores das
notas.*/

SELECT TOTALNF
FROM venda
WHERE totalnf = (SELECT AVG(totalnf) FROM venda);

/* 8) Selecione todas as notas e seus respectivos valores, dos os clientes que têm no
nome Silva e participaram de vendas no mês de julho de 2009.*/

SELECT venda.numnf, venda.totalnf
FROM venda
JOIN cliente ON venda.codcli = cliente.codcli
WHERE venda.data >= '2009-07-01'
AND venda.data <= '2009-07-31'
AND cliente.nomecli LIKE '%Silva%';
9) Qual o item com o maior preço e com a menor quantidade em estoque?
SELECT coditem, nome

FROM item
WHERE valorunt = (SELECT MAX(valorunt) FROM item)
OR qtdestoque = (SELECT MIN(qtdestoque) FROM item);
10) Selecione todos os nomes dos itens que pertencem ao mesmo grupo dos itens 1
e 2.
SELECT nome
FROM item
WHERE codgrupo IN (
SELECT codgrupo
FROM item
WHERE coditem IN (1, 2)
);
