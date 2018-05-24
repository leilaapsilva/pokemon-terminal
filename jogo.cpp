#include <iostream>
#include <string>

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
