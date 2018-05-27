#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "pokedexascii.h"

using namespace std;

typedef int TipoChave;

#define NUM_MOVES 4

typedef struct TipoMove{
	string nome; 
	int id;
	char tipo; //'e' para especial e 'f' para fisico 
	float power;
} TipoMove; 
	
typedef struct TipoPokemon{
	TipoChave id;
	string nome;
	float atk; //ataque
	float def; //defesa
	float hp; //vida
	float speed; //velocidade (o maior ataca antes)
	float sp_atk; //ataque especial
	float sp_def; //defesa especial
	TipoMove moves[NUM_MOVES]; //movimentos de ataque possiveis
} TipoPokemon;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
	TipoPokemon pokemon;
	struct TipoNo *prox;
} TipoNo;

typedef struct TipoLista {
	TipoApontador Primeiro, Ultimo;
	int player; //player 1 ou 2
} TipoLista;

////////////////////////////////////////////////////////////////////////

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
	cout << "*  NOME:	" <<  poke->nome  << "	           *" << endl;
//	cout << "*  ID: " << poke->id << "                   *" << endl;
//	cout << "*  ATK: " << poke->atk << "	           *" << endl;	
//	cout << "*  DEF: " << poke->def << "	           *" << endl;
	cout << "*  HP: " << poke->hp << "	           *" << endl;
	cout << "*  SPEED: " << poke->speed << "	           *" << endl;
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

int main(int argc, char** argv)
{

//	cout << "Inicializando moves :) " << endl << endl; 
	TipoMove flamethrower, fire_blast, fly, earthquake, quick_attack, thunderbolt, thunder, skull_bash, ice_beam, hydro_pump, aurora_beam, blizzard; 
	
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


//	cout << "Inicializando pokemons :) " << endl << endl; 	
	
	TipoPokemon pikachu, charizard, dragonite, vaporeon;

		
	InicializaPokemon(&pikachu, 1, "Pikachu", 274, 229, 218, 196, 218, 306, quick_attack, thunderbolt, thunder, skull_bash);

	InicializaPokemon(&charizard, 2, "Charizard", 360, 293, 348, 280, 295, 328, flamethrower, fire_blast, fly, earthquake);

	InicializaPokemon(&dragonite, 3, "Dragonite", 386, 403, 328, 317, 328, 284, fly, earthquake, ice_beam, fire_blast);

	InicializaPokemon(&vaporeon, 4, "Vaporeon", 464, 251, 350, 240, 317, 251, hydro_pump, aurora_beam, quick_attack, blizzard); 
	
	TipoLista player1, player2;

	InicializaLista(&player1, 1);
	InicializaLista(&player2, 2);

	InsereLista(&player1, charizard);
	InsereLista(&player1, dragonite);	
	InsereLista(&player1, pikachu);

	InsereLista(&player2, vaporeon);	
	InsereLista(&player2, pikachu);
	InsereLista(&player2, dragonite);

	//no começo do jogo, pega os primeiros da lista de cada jogador	
	
	TipoPokemon pokemon1 = PrimeiroPokemon(&player1);
	cout << "primeiro do player1: " << pokemon1.nome << endl;
	
	TipoPokemon pokemon2 = PrimeiroPokemon(&player2);
	cout << "primeiro do player2: " << pokemon2.nome << endl;	

	//TipoPokemon pokemonAtual = comeca(pokemon1, pokemon2);
	
	TipoLista jogadorAtual = comeca(player1, player2);
	TipoLista proxJogador, aux;
	
	print_pokemon(6); //charizard (?)


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

		TipoMove escolhido;	

		ImprimeMoves(&jogadorAtual.Primeiro->pokemon, &escolhido);
		
		Ataque(&jogadorAtual.Primeiro->pokemon, &proxJogador.Primeiro->pokemon, &escolhido);		

		cout << endl;

		//ImprimeLista(&jogadorAtual);
		//cout << endl;
		//ImprimeLista(&proxJogador);
		//cout << endl;
		
		//ImprimeLista(&aux);
		//cout << endl;

		aux = jogadorAtual;
		jogadorAtual = proxJogador;
		proxJogador = aux;

		cout << "--------------------------------------------------------------" << endl;
		
		comeco = false;
	}

	while(!acabou){
		TipoMove escolhido;	
		int count = 0;	
		ImprimeMoves(&jogadorAtual.Primeiro->pokemon, &escolhido);
		
		int eliminado = Ataque(&jogadorAtual.Primeiro->pokemon, &proxJogador.Primeiro->pokemon, &escolhido);		

		TipoLista aux2;

		if(eliminado){
			RemoveLista(&proxJogador, proxJogador.Primeiro->pokemon.id); 		
			//aux2 = proxJogador;
			//proxJogador.Ultimo = aux2.Primeiro;
			//proxJogador.Primeiro = proxJogador.Primeiro->prox;
			//count++;
			//cout << count;
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
	
	
}

	
	return 0;
}
