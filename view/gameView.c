//
// Created by Caio Baracat on 24/09/20.
//

#include "gameView.h"

void showPieces(struct Piece p) {
    printf("[ %d | %d ]\n", p.SideA, p.SideB);
}

int showMainMenu() {
    int option;

    printf("\nJOGO DE DOMINO (PUC-SP)\n\n");
    printf("[1] Iniciar novo jogo\n");
    printf("[2] Continuar a jogar\n");
    printf("[3] Salvar jogo\n");
    printf("[4] Carregar jogo\n");
    printf("[5] Regras do jogo\n");
    printf("[6] Sair do jogo\n\n");

    scanf("%d", &option);

    return option;
}

void showActionMenu() {

    printf("\nJOGO DE DOMINO (PUC-SP)\n\n");
    printf("Jogador #1,2,3,4...\n\n");
    printf("[1] Mesa do domino\n");
    printf("[2] Ver suas pecas\n");
    printf("[3] Comprar peca\n");
    printf("[4] Jogar\n");
    printf("[5] Voltar ao menu principal\n\n");
}

void askPlayerNickname(char nickname[], int playerTurn)
{
    printf("Qual o nome do jogador %d?\n", playerTurn);
    scanf("%s", nickname);
}

int play(int options)
{
    int choice = 0;
    printf("Escolha de 1 até %d\nQual peça você deseja jogar?\n", options);
    scanf("%d", &choice);

    printf("escolheu %d\n", choice);

    if (choice < 0 || choice > options) {
        printf("O número que você escolheu não é válido.\n");
        return 0;
    }

    return choice -= 1;
}

void alert(char message[])
{
    printf(message);
}

void showRules()
{
    printf("\n");
    printf("---------------------------------------- Regras do Jogo ----------------------------------------\n");
    printf("\n");
    printf("As regras do jogo sao bem simples: cada jogador pega sete pecas e pode comprar\n"
           "sempre que precisar de uma peca para poder jogar e quantas vezes for necessario. Da-se\n"
           "inicio ao jogo o jogador que tirar a pedra 'seis-seis'. Caso ninguem tenha o tirado,\n"
           "inicia-se o jogador que tiver a peca com os numeros repetidos mais altos, ou seja,\n"
           "'cinco-cinco', 'quatro-quatro', e assim sucessivamente.\n\n\n"
           "O jogo acontece no sentido anti-horario e os jogadores devem colocar pecas que tenham\n"
           "os mesmos numeros das pecas que se encontram na ponta do jogo. O jogador que comeca a partida\n"
           "leva vantagem. Este e' um conceito importante para a estrategia do domino, pois o jogador que\n"
           "comeca, normalmente, e' o que leva a vantagem durante a partida.\n\n\n"
           "Cada jogador, no seu turno, deve colocar uma das suas pecas em uma das 2 extremidades\n"
           "abertas, de forma que os pontos de um dos lados coincidam com os pontos da extremidade\n"
           "onde esta sendo colocada. As dobradas sao colocadas de maneira transversal para facilitar\n"
           "sua localizacao. Quando o jogador coloca sua peca sobre a mesa, seu turno se acaba e passa-se\n"
           "ao seguinte jogador. Se um jogador nao puder jogar, devera 'comprar' do monte tantas pecas\n"
           "como forem necessarias. Se nao houver pecas no monte, passara o turno ao seguinte jogador.\n"
           "A partida continua com os jogadores colocando suas pecas sobre a mesa ate que se apresente\n"
           "alguma das seguintes situacoes:\n"
           "\n--> Quando um jogador coloca sua ultima pedra na mesa, essa acao e' chamada de bater. Quando\n"
           "joga-se sozinho, o jogador que ganhou a partida soma os pontos de todos os seus adversarios.\n"
           "\n--> Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o\n"
           "numero das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida esta fechada.\n"
           "Os jogadores contarao os pontos das pedras que ficaram; o jogador com menos pontos vence e\n"
           "somam-se os pontos da maneira habitual. Pode acontecer de voce ter os mesmos pontos que o\n"
           "jogador que tem a vantagem, nesse caso, ganha este jogador.\n\n\n");
}