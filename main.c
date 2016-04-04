/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Max
 *
 * Created on 3 de Abril de 2016, 19:54
 */

#include <stdio.h>
#include <stdlib.h>

/*
 Error constants
 */
typedef struct {
    char* ERROR_INSUFICIENT_AMMOUNT;
    char* ERROR_OVER_AMMOUNT;
    char* ERROR_INVALID_COIN;
    char* INSERT_A_COIN;
    char* SUCCESS;
    char* WELCOME;
    char* COINS;
    char* INSTRUCTION;
    char* CANCEL;
} Messages;

void printCoins(float coins[]){
    int i;
    for(i = 0; i<3; i++){
        printf("%.2f \n", coins[i]);
    }
}

/*
 * Parquimetro...
 */
int main() {
    
    /*
    Program configuration
    */
    float price = 1;
    float availableCoins[3] = { 0.25, 0.50, 1.00 };
    float paid = 0;
    float coin;
    int validCoin;
    
    // Prepare messages
    Messages messageEnum;
    messageEnum.ERROR_INSUFICIENT_AMMOUNT = "Por favor, insira outra moeda.\nVoce precisa inserir mais %.2f para completar o pagamento.\n";
    messageEnum.ERROR_OVER_AMMOUNT = "Por favor, recolha seu troco.\n";
    messageEnum.INSERT_A_COIN = "\nPor favor, insira uma moeda.\n";
    messageEnum.ERROR_INVALID_COIN = "Voce inseriu uma moeda invalida, por favor, recolha sua moeda e insira outra.\n";
    messageEnum.SUCCESS = "Pagamento efetuado com sucesso!\n";
    messageEnum.WELCOME = "Bem vindo ao parquimetro AutoPark!\nO valor do estacionamento e %.2f.\n";
    messageEnum.COINS = "Insira moedas ate completar o valor da tarifa conforme os valores a seguir:\n";
    messageEnum.INSTRUCTION = "Apos informar o valor, pressione ENTER.\n";
    messageEnum.CANCEL = "Operacao cancelada!\n";
    
    // Print Welcome message
    printf(messageEnum.WELCOME, price);
    // Print instructions
    printf(messageEnum.COINS);
    printCoins(availableCoins);
    printf(messageEnum.INSTRUCTION);
    
    while(paid != price){
        // Wait for user
        printf(messageEnum.INSERT_A_COIN);
        scanf("%f", &coin);
        
        // Check valid coin
        validCoin = 0;
        int i;
        for(i = 0; i<3; ++i){
            if (availableCoins[i] == coin){
                validCoin = 1;
            }
        }
        
        if (validCoin == 1){
            // increment paid
            paid += coin;
        } else {
            printf(messageEnum.ERROR_INVALID_COIN);
        }
        
        // Check paid status
        if ((price - paid) == 0){
            // Paid
            printf(messageEnum.SUCCESS);
        } else if ((price - paid) < 0) {
            // Overpaid
            printf(messageEnum.SUCCESS);
            printf(messageEnum.ERROR_OVER_AMMOUNT);
            paid = price;
        } else if ((price - paid) < price) {
            // Insufficient paid
            printf(messageEnum.ERROR_INSUFICIENT_AMMOUNT, (price - paid));
        } else if (coin == 0) { 
            // Coin == 0
            printf(messageEnum.CANCEL);
            paid = price;
        }        
        
    }
    
    printf("Press ENTER\n");
    getchar();
    getchar();
    
    return (EXIT_SUCCESS);
}

