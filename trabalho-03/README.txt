Bruna Caetano - SI - 2023

Sistema de locação de veículos

# O que foi implementado
    -> cadastro:
        veículos, clientes, locações
    -> listagem:
        veículos, clientes, locações
    -> devolução de veículos;
    -> relatório:
        locações ativas em um período fornecido, locações por cliente fornecido, faturamento mensal, 3 veículos mais rodados, veículos disponíveis (n considerando um período fornecido)
    -> menus:
        principal (acessa a das listas e o do relatório), listas (acessa as listas de veículos, clientes e locações), relatórios (acessa os relatórios)

# Arquivos
    -> main.c:
        arquivo principal, inicia o programa
    -> lista.c e lista.h:
        declaração das structs e listas encadeadas, funções de manipulação das listas (cadastro, listagem, remoção, etc)
    -> menu.c e menu.h:
        funções de manipulação dos menus, funções dos relatórios
    -> manipulacao-datas.c e manipulacao-datas.h:
        funções de manipulação de datas, arquivo fornecido no trabalho com algumas alterações para facilitar o uso