#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include "pokedexascii.h" //biblioteca com os 151 pokemons iniciais para impressao
//#include "poketads.h"


using namespace std;

#define ANSI_COLOR_RED     	"\x1b[31m" //cores em ANSI utilizadas 
#define ANSI_COLOR_GRAY    	"\e[0;37m"
#define ANSI_COLOR_DARK_GRAY 	"\e[1;30m"
#define ANSI_COLOR_GREEN	"\e[0;32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define NUM_MOVES 4 //quantidade de moves para 



//TADs utilizados 

typedef int TipoChave;

typedef struct TipoMove{
	string nome; 
	int id;
	char tipo; //'e' para especial e 'f' para fisico 
	float power; //quanto poder o move possui para o ataque
} TipoMove; 
	
typedef struct TipoPokemon{
	TipoChave id; //chave - usada para impressao dos pokemon
	string nome; //nome
	float atk; //ataque
	float def; //defesa
	float hp; //vida
	float speed; //velocidade (o maior ataca antes)
	float sp_atk; //ataque especial
	float sp_def; //defesa especial
	TipoMove moves[NUM_MOVES]; //movimentos de ataque possiveis
} TipoPokemon;

typedef struct TipoNo *TipoApontador; //ponteiro para um nó

typedef struct TipoNo {
	TipoPokemon pokemon; //cada nó possui um pokemon
	struct TipoNo *prox; //e aponta para o proximo no
} TipoNo;

typedef struct TipoLista { 
	TipoApontador Primeiro, Ultimo;
	int player; //player 1 ou 2
} TipoLista;

////////////////////////////////////////////////////////////////////////



//------------------------------v
void InicializaMove(TipoMove *mov, string n, int id, char t, float pw){
	mov->nome = n;
	mov->id = id;
	mov->tipo = t;
	mov->power = pw;
	
	//cout << "move " << mov->nome << " inicializado " << endl;
}

void InicializaLista(TipoLista *L, int player) {
	(*L).Primeiro = NULL;
	(*L).Ultimo = NULL;
	//printf("Criou a lista\n");
}

int ListaVazia(TipoLista *L) {
	if (L->Primeiro == NULL)
		return 1;
	else
		return 0;
}

void InsereLista(TipoLista *L, TipoPokemon poke) {

	TipoApontador P;
	
	P = (TipoApontador) malloc(sizeof(TipoNo));
	if (P == NULL) {
		cout << "NAO FOI POSSIVEL INSERIR O ITEM: MEMORIA CHEIA " << endl;
		return;
	}
	
	P->pokemon = poke;
	P->prox = NULL;
	if (ListaVazia(L)) {
		L->Primeiro = P;
		L->Ultimo = P;
	} else {
		L->Ultimo->prox = P;
		L->Ultimo = P;
	}

	//cout << "Pokemon inserido: " << poke.id << endl;
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {

	TipoApontador P;
	
	P = L->Primeiro;
	while(P != NULL) {
		printf("Pesquisa passando por %d\n", P->pokemon.id);
		if (P->pokemon.id == C)
			return P;
		P = P->prox;
	}
	//caso nao encontre
	cout << "nao encontrado" << endl;
	
	return NULL; 
}

int static RemoveListaPosicao(TipoLista *L, TipoApontador P) {
	cout << "entrou no remove por posiçao" << endl;

	if (P->pokemon.id == -1){
	cout << "posicao invalida" << endl;
		return -1;
	}

	// unico elemento na lista
	if (P == L->Primeiro && L->Primeiro == L->Ultimo) {
	cout << "unico elemento" << endl;
		L->Primeiro = NULL;
		L->Ultimo = NULL;
		free(P);
		return 0;
	}
	
	// Remove do inicio
	if (P == L->Primeiro) {
	cout << "primeiro" << endl;
		L->Primeiro = L->Primeiro->prox;
		free(P);
		return 0;
	}
	
	// Remove no meio da lista
	cout << "remove no meio da lista" << endl;
	TipoApontador aux = L->Primeiro;
	while(aux->prox != NULL && aux->prox != P) {
		aux = aux->prox;
	}
	
	aux->prox = P->prox;
	// se o removido estava no fim
	if (aux->prox == NULL)
		L->Ultimo = aux;
	
	free(P);
	
	return 0;
	
}

void RemoveLista(TipoLista *L, TipoChave C) {	
	TipoApontador P = PesquisaLista(L, C);	
	int r = RemoveListaPosicao(L, P);
	if (r != -1)
		printf("Removeu elemento\n");
	else
		printf("Remocao deu ruim\n");
}

void ImprimeLista(TipoLista *L) {
	
	TipoApontador P = L->Primeiro;

	int i = 0;
	//while(P != NULL) {
	//	if (P->prox != NULL){ //se nao for o ultimo, aponta para o proximo
		cout << L->Primeiro->pokemon.nome << endl;
		cout << L->Primeiro->prox->pokemon.nome << endl;
		cout << L->Primeiro->prox->prox->pokemon.nome << endl;
		//cout << L->Primeiro->prox->prox->pokemon.nome << endl;

	//	}else{ //se for o ultimo, apenas imprime
					
	//	}
		P = P->prox;
		i++;

		cout << endl;
		cout << endl;
	//}
	
}


TipoPokemon PrimeiroPokemon(TipoLista *L){
	TipoPokemon ash;
	ash.id = -1;
	
	if(ListaVazia(L)){
		cout << "a lista esta vazia, nao eh possivel retornar o primeiro " << endl;
		return ash;
	}
	
	return L->Primeiro->pokemon; 
}

void InicializaPokemon(TipoPokemon *poke, int id, string nome, float vida, float ataque, float spAtk, float defesa, float spDef, float velocidade, TipoMove mov0, TipoMove mov1, TipoMove mov2, TipoMove mov3){		
								
				poke->id = id;
				poke->nome = nome;
				poke->atk = ataque;
				poke->def = defesa;
				poke->hp = vida;
				poke->speed = velocidade;
				poke->sp_atk = spAtk;
				poke->sp_def = spDef;
				poke->moves[0]= mov0;
				poke->moves[1] = mov1;
				poke->moves[2] = mov2;
				poke->moves[3] = mov3;		
																			
}

void ImprimePokemon(TipoPokemon *poke){
	
	cout << endl;
	cout << "****************************" << endl;
	cout << "*  POKEMON:	" <<  poke->nome  << "	           *" << endl;
//	cout << "*  ID: " << poke->id << "                   *" << endl;
//	cout << "*  ATK: " << poke->atk << "	           *" << endl;	
//	cout << "*  DEF: " << poke->def << "	           *" << endl;
	cout << "*  HP: " << poke->hp << "	           *" << endl;
//	cout << "*  SPEED: " << poke->speed << "	           *" << endl;
//	cout << "*  SP.ATK: " << poke->sp_atk << "	           *" << endl;
//	cout << "*  SP.DEF:	" << poke->sp_def << " 	   *" << endl;
//	cout << "*  MOVES: " << "                 *" << endl;
//	cout << "*  "<< poke->moves->nome << "            *" << endl;
//	cout << "*  "<< poke->moves[1].nome << "              *" << endl;
//	cout << "*  "<< poke->moves[2].nome << "                     *" << endl;
//	cout << "*  "<< poke->moves[3].nome << "              *" << endl;
	cout << "****************************" << endl; 
} 

//retorna 0 caso nao elimine e 1 caso elimine
int Ataque(TipoPokemon *ataca, TipoPokemon *defende, TipoMove *move){

	cout << endl;
	float dano;
	
	//cout <<"Tipo do move usado: " << move->tipo << endl;

	if(move->tipo == 'e'){ //ataque especial atinge defesa especial
		//cout << "ataque especial" << endl;
		dano = ((ataca->sp_atk / defende->sp_def) * move->power)/2;
	}
	else if(move->tipo == 'f'){ //ataque fisico atinge defesa normal
		//cout << "ataque fisico" << endl;

		dano = ((ataca->atk / defende->def) * move->power)/2;	
	}
	else{
		//tipo invalido
		cout << "tipo invalido" << endl;
	}

	//trunca o dano para ficar inteiro
	dano = floor(dano);
	
	//cout << "dano: " << dano << endl;

	//decrementa a hp do pokemon que recebeu o ataque
	defende->hp = defende->hp - dano; 

	cout << "teste" << endl;

	cout << ataca->nome << " atacou " << defende->nome << " usando " << move->nome << " e causou " << dano << " de dano"<< endl;

	cout << "hp do atacado = " << defende->hp << endl;
	
	if(defende->hp <= 0){
		cout << defende->nome << " eliminado!" << endl;
		//RemoveLista(lista, chave);
		return 1;
	}
	return 0;

}

//metodo para escolha do move a ser jogado
void ImprimeMoves(TipoPokemon *pokemon, TipoMove *escolhido){	
	
	int n_escolhido = 0;
	cout << "Escolha o move: " << endl;
	for(int i = 0; i < NUM_MOVES; i++){
		cout << "(" << i+1 << ") " << pokemon->moves[i].nome << endl;
	}
	cin >> n_escolhido;

	*escolhido = pokemon->moves[n_escolhido-1];
}

TipoLista comeca(TipoLista p1, TipoLista p2){

	//se for o primeiro turno
	//determina qual joga primeiro
	if(p1.Primeiro->pokemon.speed > p2.Primeiro->pokemon.speed){
		//pokemon1 comeca
		cout << endl;
		cout << "speed do " << p1.Primeiro->pokemon.nome <<" maior, ele comeca" << endl;
		return p1;
	
	} else
	{
		//pokemon2 comeca
		cout << endl;
		cout << "speed do " << p2.Primeiro->pokemon.nome <<" maior, ele comeca" << endl;
		return p2;
	}
}

void menuInicial(){

	char jogar;

	std::cout << "\033c";

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;             
	cout << endl;

	//String color = ANSI_COLOR_GREEN;

	printf(ANSI_COLOR_RED "             	                                .::.                         \n"ANSI_COLOR_RESET); 
	printf(ANSI_COLOR_RED "                                           .;:**'            AMC           	\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "                                           `                  0            \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "               .:XHHHHk.              db.   .;;.     dH  MX   0            \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "             oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN     \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "             QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "               `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP\n"ANSI_COLOR_RESET);
	printf("                'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GRAY "                 ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GRAY "                  ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM  \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GRAY "                   MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP  \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GRAY "                   'MMM.                                             IMX   \n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GRAY "                    ~M!M                                             IMP \n"ANSI_COLOR_RESET);
	printf("                                                   Console edition :p ");  


	//cout << "                                                                 " << endl;

	cout << endl << endl << endl << endl;
}


int main(int argc, char** argv)
{

//	cout << "Inicializando moves :) " << endl << endl; 
	TipoMove flamethrower, fire_blast, fly, earthquake, quick_attack, thunderbolt, thunder, skull_bash, ice_beam, hydro_pump, aurora_beam, blizzard, surf, body_slam, hyper_beam, take_down, mega_kick, psychic, tri_attack, solar_beam, stomp, egg_bomb; 
	
	InicializaMove(&flamethrower, "Flamethrower", 1, 'e', 95); 
	InicializaMove(&fire_blast, "Fire Blast", 2, 'e', 120);
	InicializaMove(&fly, "Fly", 3, 'f', 70);
	InicializaMove(&earthquake, "Earthquake", 4, 'f', 100);
	InicializaMove(&quick_attack, "Quick Attack", 5, 'f', 40);
	InicializaMove(&thunderbolt, "Thunderbolt", 6, 'e', 95);
	InicializaMove(&thunder, "Thunder", 7, 'e', 120);
	InicializaMove(&skull_bash, "Skull Bash", 8, 'f', 100);
	InicializaMove(&ice_beam, "Ice Beam", 9, 'e', 95);
	InicializaMove(&hydro_pump, "Hydro Pump", 10, 'e', 120);
	InicializaMove(&aurora_beam, "Aurora Beam", 11, 'e', 65);
	InicializaMove(&blizzard, "Blizzard", 12, 'e', 120);
	InicializaMove(&surf, "Surf", 13, 'e', 95);
	InicializaMove(&body_slam, "Body Slam", 14, 'f', 85);
	InicializaMove(&hyper_beam, "Hyper Beam", 15, 'e', 150);
	InicializaMove(&take_down, "Take Down", 16, 'f', 90);
	InicializaMove(&mega_kick, "Mega Kick", 17, 'f', 120);
	InicializaMove(&psychic, "Psychic", 18, 'e', 90);
	InicializaMove(&tri_attack, "Tri Attack", 19, 'e', 80);
	InicializaMove(&solar_beam, "Solar Beam", 20, 'e', 120);
	InicializaMove(&stomp, "Stomp", 21, 'f', 65);
	InicializaMove(&egg_bomb, "Egg Bomb", 22, 'f', 100);
	
//	cout << "Inicializando pokemons :) " << endl << endl; 	
	
	TipoPokemon pikachu, charizard, dragonite, vaporeon, gyarados, snorlax, mewtwo, exeggutor;

		
	InicializaPokemon(&pikachu, 25, "Pikachu", 274, 229, 218, 196, 218, 306, quick_attack, thunderbolt, thunder, skull_bash);

	InicializaPokemon(&charizard, 6, "Charizard", 360, 293, 348, 280, 295, 328, flamethrower, fire_blast, fly, earthquake);

	InicializaPokemon(&dragonite, 149, "Dragonite", 386, 403, 328, 317, 328, 284, fly, earthquake, ice_beam, fire_blast);

	InicializaPokemon(&vaporeon, 134, "Vaporeon", 464, 251, 350, 240, 317, 251, hydro_pump, aurora_beam, quick_attack, blizzard); 

	InicializaPokemon(&gyarados, 130, "Gyarados", 394, 383, 240, 282, 328, 287, ice_beam, blizzard, hydro_pump, surf);

	InicializaPokemon(&snorlax, 143, "Snorlax", 524, 350, 251, 251, 350, 174, body_slam,hyper_beam,take_down,mega_kick);

	//InicializaPokemon(&mewtwo, 150, "Mewtwo", 416, 350, 447, 306, 306, 394, psychic,tri_attack, solar_beam,fire_blast);

	InicializaPokemon(&exeggutor, 103, "Exeggutor", 394, 317, 383, 295, 251, 229, stomp,egg_bomb, solar_beam,hyper_beam);

	
	TipoLista player1, player2;

	InicializaLista(&player1, 1);
	InicializaLista(&player2, 2);

	InsereLista(&player1, charizard);
	InsereLista(&player1, dragonite);	
	InsereLista(&player1, pikachu);
	InsereLista(&player1, vaporeon);	
	
	InsereLista(&player2, gyarados);
	InsereLista(&player2, snorlax);
	//InsereLista(&player2, mewtwo);
	InsereLista(&player2, exeggutor);


	//no começo do jogo, pega os primeiros da lista de cada jogador	

	menuInicial();
	cout << "                                                            Aceita o desafio?              " << endl;

	char entrada;
	cin >> entrada;

	std::cout << "\033c";
	
	
	TipoLista jogadorAtual = comeca(player1, player2);
	TipoLista proxJogador, aux;

	bool comeco = true;
	bool acabou = false;

	while(comeco){
		//proximo jogador
		if(jogadorAtual.player == player1.player){
			proxJogador = player2;
			
		}
		else{
			proxJogador = player1;
		}

		cout << "Time 1: " << endl;
		ImprimeLista(&jogadorAtual);
		cout << endl;

		cout << "Time 2: " << endl; 
		ImprimeLista(&proxJogador);
		cout << endl;

		char jogar;
		cout << "Iniciar batalha? y/n" << endl;
		cin >> jogar;
		std::cout << "\033c";
		
		//cout << "=========================================================================" << endl;
		cout << jogadorAtual.Primeiro->pokemon.nome << " atacando" << endl;

		//imprime ascii
		print_pokemon(jogadorAtual.Primeiro->pokemon.id);
		cout << "=========================================================================" << endl;

		TipoMove escolhido;	
		
		cout << "Player1" << endl;
		ImprimePokemon(&player1.Primeiro->pokemon);		

		
		cout << "Defendendo:" << endl;
		ImprimePokemon(&player2.Primeiro->pokemon);		


		ImprimeMoves(&jogadorAtual.Primeiro->pokemon, &escolhido);
		
		Ataque(&jogadorAtual.Primeiro->pokemon, &proxJogador.Primeiro->pokemon, &escolhido);		
		

		cout << endl;

		aux = jogadorAtual;
		jogadorAtual = proxJogador;
		proxJogador = aux;

		cout << "--------------------------------------------------------------" << endl;
		std::cout << "\033c";
		comeco = false;
	}

	while(!acabou){
		TipoMove escolhido;	
		int count = 0;	

		//cout << "=========================================================================" << endl;
		cout << jogadorAtual.Primeiro->pokemon.nome << " atacando" << endl;

		print_pokemon(jogadorAtual.Primeiro->pokemon.id); //pikachu
		cout << "=========================================================================" << endl;

		cout << "Player 1" << endl;
		ImprimePokemon(&player1.Primeiro->pokemon);		

		
		cout << "Player 2:" << endl;
		ImprimePokemon(&player2.Primeiro->pokemon);

		ImprimeMoves(&jogadorAtual.Primeiro->pokemon, &escolhido);
		
		int eliminado = Ataque(&jogadorAtual.Primeiro->pokemon, &proxJogador.Primeiro->pokemon, &escolhido);		

		TipoLista aux2;

		if(eliminado){
			RemoveLista(&proxJogador, proxJogador.Primeiro->pokemon.id); 		
		}

		cout << endl;

	//	ImprimeLista(&jogadorAtual);
	//	cout << endl;
	//	ImprimeLista(&proxJogador);
	//	cout << endl;

		if(ListaVazia(&proxJogador)){
			cout << "acabou!!!111" << endl;
			acabou = true;
		}

		aux = jogadorAtual;
		jogadorAtual = proxJogador;
		proxJogador = aux;
		
		
	
		cout << "--------------------------------------------------------------" << endl;
		//sleep(5);
		std::cout << "\033c";
	
}

	cout << "acabooooooooooooooou" << endl;
	menuInicial();
	cout << "Obrigada por jogar!!" << endl;
	cout << "Pressione enter parar sair do jogo" << endl; 
	char fim;
	cin >> fim;
	
	return 0;
}
