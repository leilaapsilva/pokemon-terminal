#include <iostream>
#include <string>

using namespace std;

typedef int TipoChave;

typedef struct {
	TipoChave id;
	//string nome;#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef int TipoChave;

typedef struct {
	TipoChave id;
	//string nome;
	float atk; //ataque
	float def; //defesa
	float hp; //vida
	float speed; //velocidade (o maior ataca antes)
	float sp_atk;
	float sp_def;
	int moves[3]; //movimentos de ataque possiveis
} TipoPokemon;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
	TipoPokemon pokemon;
	struct TipoNo *prox;
} TipoNo;

typedef struct TipoLista {
	TipoApontador Primeiro, Ultimo;
} TipoLista;

void InicializaLista(TipoLista *L) {
	(*L).Primeiro = NULL;
	(*L).Ultimo = NULL;
	printf("Criou a lista\n");
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

	cout << "Pokemon inserido: " << poke.id << endl;
}

TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {

	TipoApontador P;
	
	P = L->Primeiro;
	while(P != NULL) {
		//printf("Pesquisa passando por %d\n", P->poke.Chave);
		if (P->pokemon.id == C)
			return P;
		P = P->prox;
	}
	//caso nao encontre
	cout << "nao encontrado" << endl;
	
	return NULL; 
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

	//moves ---- devem ser const para que possam ser usados no switch
	
	//charizard 
		
	const int flamethrower = 1; //special
	const int fire_blast = 2; //s
	const int fly = 3; //fisico
	const int earthquake = 4; //f
	
	//pikachu
	
	const int quick_attack = 5; //f
	const int thunderbolt = 6; //s
	const int thunder = 7; //s
	const int skull_bash = 8; //f
	
	//dragonite
	
	const int ice_beam = 9; //s
	
	//vaporeon
	
	const int hydro_pump = 10; //s
	const int aurora_beam = 11; //s
	const int blizzard = 12; //s
	

void InicializaPokemon(TipoPokemon *poke, int id, /*string nome*/ float ataque, float defesa, float vida, float velocidade, float spAtk, float spDef, int mov0, int mov1, int mov2, int mov3){			
								
				poke->id = id;
				//poke->nome("teste");
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
//	cout << "*  NOME	" << " ... "  << "	           *" << endl;
	cout << "*  ID: " << poke->id << "                   *" << endl;
//	cout << "*  ATK: " << poke->atk << "	           *" << endl;	
//	cout << "*  DEF: " << poke->def << "	           *" << endl;
	cout << "*  HP: " << poke->hp << "	           *" << endl;
	cout << "*  SPEED: " << poke->speed << "	           *" << endl;
//	cout << "*  SP.ATK: " << poke->sp_atk << "	           *" << endl;
//	cout << "*  SP.DEF:	" << poke->sp_def << " 	   *" << endl;
	cout << "****************************" << endl; 
} 

void Ataque(TipoPokemon *fez_atk, TipoPokemon *rec_atk, int move){
	
	float power_move;
	int type_move; //0 para fisico e 1 para especial
	float dano;
	string string_move;
	
	switch(move){
		case flamethrower: 
			power_move = 95;
			type_move = 1; //especial
			string_move = "flamethrower";
			break;
			
        case fire_blast: 
        	power_move = 120;
        	type_move = 1;
        	string_move = "fire blast";
			break;
        	
	    case fly:
        	power_move = 70;
        	type_move = 0;
        	string_move = "fly";
			break;
    	
		case earthquake:
        	power_move = 100;
        	type_move = 0;
        	string_move = "earthquake";
			break;
        	
		case quick_attack:
			power_move = 40;
        	type_move = 0;
        	string_move = "quick_attack";
			break;
        	
		case thunderbolt:
			power_move = 95;
        	type_move = 1;
        	string_move = "thunderbolt";
			break;
			
		case thunder:
			power_move = 120;
        	type_move = 1;
        	string_move = "thunder";
			break;
			
		case skull_bash:
			power_move = 100;
        	type_move = 0;
        	string_move = "skull bash";
			break;
			
		case ice_beam:
			power_move = 95;
        	type_move = 1;
        	string_move = "ice beam";
			break;
			
		case hydro_pump:
			power_move = 120;
        	type_move = 1;
        	string_move = "hydro pump";
			break;
			
		case aurora_beam:
			power_move = 65;
        	type_move = 1;
        	string_move = "aurora beam";
			break;
			
		case blizzard:    	
  			power_move = 120;
        	type_move = 1;
        	string_move = "blizzard";
			break;
	}
	
	if(type_move == 1){ //ataques especiais atingem defesa especial
		dano = ((fez_atk->sp_atk / rec_atk->sp_def) * power_move)/2; 
		
	
		
	} else{ //ataques fisicos atingem a defesa normal
	
		dano = ((fez_atk->atk / rec_atk->def) * power_move)/2;

	}
	
	//trunca o dano para ficar inteiro
	dano = floor(dano);
	
	rec_atk->hp = rec_atk->hp - dano;
	
	cout << " *nome pokemon* atacou" << " *nome pokemon* " << " usando " << string_move << " e causou " << dano << " de dano";
	
}


int main(int argc, char** argv)
{
	TipoPokemon charizard, pikachu;

	//InicializaPokemon(TipoPokemon *poke, float id, /*string nome*/ float ataque, float defesa, float vida, float velocidade, float spAtk, float spDef, float mov0, float mov1, float mov2, float mov3)
	
	InicializaPokemon(&pikachu, 1, /*"pikachu"*/ 229, 196, 274, 306, 218, 218, quick_attack, thunderbolt, thunder, skull_bash);
	
	InicializaPokemon(&charizard, 2, /*"Charizard"*/ 293, 280, 360, 328, 348, 295, flamethrower, fire_blast, fly, earthquake);

	
	//listas de pokemons dos jogadores
	TipoLista player1, player2;
	InicializaLista(&player1);
	InicializaLista(&player2);
	
	cout << "player 1 <- pikachu" << endl;
	cout << "player 2 <- charizard" << endl;
	
	InsereLista(&player1, pikachu);
	InsereLista(&player2, charizard);

	
	
	cout<<"pikachu:"<<endl;
	
	ImprimePokemon(&pikachu);
	
	cout<<"charizard:"<< endl;
	
	ImprimePokemon(&charizard);
	
	//no come�o do jogo, pega os primeiros da lista de cada jogador	
	
	TipoPokemon pokemon1 = PrimeiroPokemon(&player1);
	TipoPokemon pokemon2 = PrimeiroPokemon(&player2);
	
	if(pokemon1.speed > pokemon2.speed){
		//pokemon1 comeca
		cout << endl;
		cout << "speed do pokemon 1 maior, ele comeca" << endl;
	} else
	{
		//pokemon2 comeca
		cout << endl;
		cout << "speed do pokemon 2 maior, ele comeca" << endl;
	}
	

	
	

	
	//determinar qual joga primeiro de acordo com o speed
	
	
	
	/*
	
	cout << "escolha o move: " << endl;
	cout << "(1) flamethrower" << endl;
	cout << "(2) fire blast" << endl;
	cout << "(3) fly " << endl;
	cout << "(4) earthquake" << endl;
	
	//TO DO - verificar se o move escolhido pertence ao pokemon
	
	
	int mov;
	
	cin >> mov;
	
	Ataque(&charizard, &pikachu, mov);	
	
	ImprimePokemon(&pikachu);
	
	*/
	
	return 0;
}

	float atk; //ataque
	float def; //defesa
	float hp; //vida
	float speed; //velocidade (o maior ataca antes)
	float sp_atk;
	float sp_def;
	int moves[3]; //movimentos de ataque possiveis
} TipoPokemon;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
	TipoPokemon pokemon;
	struct TipoNo *prox;
} TipoNo;

typedef struct TipoLista {
	TipoApontador Primeiro, Ultimo;
} TipoLista;

void InicializaPokemon(TipoPokemon *poke, int id, /*string nome*/ float ataque, float defesa, float vida, float velocidade, float spAtk, float spDef, int mov0, int mov1, int mov2, int mov3){			
								
				poke->id = id;
				//poke->nome("teste");
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
	cout << "*  NOME	" << " ... "  << "	           *" << endl;
	cout << "*  ID: " << poke->id << "                   *" << endl;
	cout << "*  ATK: " << poke->atk << "	           *" << endl;	
	cout << "*  DEF: " << poke->def << "	           *" << endl;
	cout << "*  HP: " << poke->hp << "	           *" << endl;
	cout << "*  SPEED: " << poke->speed << "	           *" << endl;
	cout << "*  SP.ATK: " << poke->sp_atk << "	           *" << endl;
	cout << "*  SP.DEF:	" << poke->sp_def << " 	   *" << endl;
	cout << "****************************" << endl; 
} 

void Ataque(TipoPokemon *fez_atk, TipoPokemon *rec_atk, int move){
	
	float power_move;
	int type_move; //0 para fisico e 1 para especial
	float dano;
	
		/*moves
	
	flamethrower 1;
	fire_Blast 2;
	fly 3;
	earthquake 4;
	
	quick_attack 5;
	thunderbolt 6;
	thunder 7;
	skull_bash 8;
	
	*/
	
	switch(move){
		case 1: //flamethrower
			power_move = 95;
			type_move = 1; //especial
			
        case 2: //fire blast
        	power_move = 120;
        	type_move = 1;
        	
	    //case 3: //fly
        	//power_move = ;
        	//type_move = ;
    	
		//case 4: //earthquake
        	//power_move = 120;
        	//type_move = 1;    	
	    
	}
	
	//dano = (( 42 * power * (atk/def)) / 50) + 2
	
	if(type_move == 1){ //ataques especiais atingem defesa especial
		dano = ((fez_atk->sp_atk / rec_atk->sp_def) * power_move)/2; 
		
	//	dano = (((((2*100)/5) + 2) * power_move * (fez_atk->sp_atk/rec_atk->sp_def))/50)+2;
		
		//dano = ((42 * power_move * (fez_atk->sp_atk/rec_atk->sp_def)) / 50) + 2;
		
	
		
	} else{ //ataques fisicos atingem a defesa normal
	
		dano = ((fez_atk->atk / rec_atk->def) * power_move)/2;
	
	
		//dano = ((42 * power_move * (fez_atk->atk/rec_atk->def)) / 50) + 2;
		
	}
	rec_atk->hp = rec_atk->hp - dano;
	
	
}


	/*moves
	
	flamethrower 1;
	fire_Blast 2;
	fly 3;
	earthquake 4;
	
	quick_attack 5;
	thunderbolt 6;
	thunder 7;
	skull_bash 8;
	
	*/


int main(int argc, char** argv)
{
	
	TipoPokemon charizard, pikachu;

	//InicializaPokemon(TipoPokemon *poke, float id, /*string nome*/ float ataque, float defesa, float vida, float velocidade, float spAtk, float spDef, float mov0, float mov1, float mov2, float mov3)
	
		InicializaPokemon(&pikachu, 1, /*"pikachu"*/ 229, 196, 274, 306, 218, 218, 5, 6, 7, 8);
	
	
	InicializaPokemon(&charizard, 2, /*"Charizard"*/ 293, 280, 360, 328, 348, 295, 1, 2, 3, 4);

	
	cout<<"charizard:"<< endl;
	
	ImprimePokemon(&charizard);
	
	cout<<"pikachu:"<<endl;
	
	ImprimePokemon(&pikachu);
	
	
	
	cout << "escolha o move: " << endl;
	cout << "(1) flamethrower" << endl;
	cout << "(2) fire blast" << endl;
	cout << "(3) fly " << endl;
	cout << "(4) earthquake" << endl;
	
	int mov;
	
	cin >> mov;
	
	Ataque(&charizard, &pikachu, mov);
	
	cout << "charizard atacou pikachu" << endl;
	
	
	cout<<"pikachu:"<<endl;
	ImprimePokemon(&pikachu);
	
	
	return 0;
}
