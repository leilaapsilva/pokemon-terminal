# Pokémon - Console Edition

![Logo](https://imgur.com/kZ14IwF.png)

![Charizard](https://imgur.com/rvGlkz5.png)

![Gyarados](https://imgur.com/wcyqxcD.png)


**Compilando** 

No terminal, acessar a pasta com os arquivos do jogo e compilar utilizando o *g++*:

`g++ jogo.cpp -o jogo`

Rodar o executável com: 

`./jogo`





**Debugando com GDB**  

Compilar normalmente, adicionando -g no final:

`g++ jogo.c -o jogo -g`

iniciar o gdb passando o executavel: 

`gdb ./jogo`

Para rodar: 

`run`

O programa será executado e se houver alguma falha indicará onde.
