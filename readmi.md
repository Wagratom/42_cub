# 🎮 Cub3D

*	This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.

*	As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc. To conclude cub3D is a remarkable playground

*	to explore the playful practical applications of mathematics without having to understand the specifics.

# ⚙️ Installing

```
git clone git@github.com:Wagratom/42_cub.git  --recurse-submodules
```

apos clonar o repo você pode checar se o buffer size no head da libft e igual a 1 para evitar leaks de memoria


# Makefile

```
Make
```
para gerar o executavel use make


```
Make tests
```
Para rodar alguns test de validação do mapa vc pode use to make tests, ele executara todos os tests automaticamente, alguns test poderam estar comentado então você pode verificar cada um na pasta test. Caso altere o codigo vc pode rodar o make tests para verificar se nada esta rodando fora dos padroes.

Caso algum test de error e o executavel nao seja deletado, você pode deletar automaticamente para que o mesmo possa pegar novamente, temos que corrigir isso ainda

```
Make vgtests
```
O makefile também possui a funcionalidade de rodar os test com o valgrind para verificar possiveis erros e leaks of memory, basta usar

Caso queria você também pode rodar um test individual

```
Make test t=<caminho dentro da past test>
exemplo
Make test t=parser/extract_data nota que nao colocamos a extenção do arquivo
```
para rodar um arquivo individual com o valgrind vc pode usar o vg novamente antes do nome test

```
Make vgtest t=parser/extract_data
```
Lembrando que alguns test podem estar comentando para um melhor funcionamento.

# MOD DEGUB 🌈

Caso queria ativar o modo debug do nosso projeto você pode passar a flag -D apos os parametros do executavel
![teste](/.g)

