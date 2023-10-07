/* Bruna Caetano - SI - 2023 */
/* Este programa permite ao usuário inserir duas datas no formato DD MM AAAA (dia, mês e year) e, em seguida, calcula a diferença em dias
 entre essas duas datas. Certifique-se de inserir as datas no formato correto e observe que este programa não trata todos os casos
  possíveis (por exemplo, datas inválidas), mas deve funcionar bem para datas válidas. */

#ifndef TRABALHO_03_MANIPULACAO_DATAS_H
#define TRABALHO_03_MANIPULACAO_DATAS_H

#include <stdbool.h>

// Estrutura para representar uma data
typedef struct dates {
    int day;
    int month;
    int year;
} Date;

// Funções
// Função para calcular a diferença em dias entre duas datas
int daysBetweenDates(Date date1, Date date2);

// Função para verificar se uma data está entre duas outras datas
bool isBetweenDates(Date date, Date startDate, Date endDate);

// Função para comparar duas datas
bool compararDatas(Date data1, Date data2);

#endif //TRABALHO_03_MANIPULACAO_DATAS_H
