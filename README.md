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

Para ficar com esse visual, foi alterado o perfil de cores do Ubuntu da seguinte forma:

Fundo: #C3CFA1

Fonte: #000000 (preto)

E a fonte do jogo pode ser baixada [aqui](http://www.fontspace.com/jackster-productions/pokemon-gb)

--------------------------------------------------------------------------------------------------------------------------

TO DO:

- Versão Windows

- Modularizar em arquivos separados

- Fixar cor e fonte no executável

- Melhorar fórmula de dano

- Adicionar novos pokémon e moves 




