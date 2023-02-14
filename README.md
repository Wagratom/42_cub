# 🎮 Cub3D

*	This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.

*	As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc. To conclude cub3D is a remarkable playground

*	to explore the playful practical applications of mathematics without having to understand the specifics.

# ⚙️ Installing

```
git clone git@github.com:Wagratom/42_cub.git  --recurse-submodules
```

* Após instalar o repositório, você pode verificar se o tamanho do "BUFFER SIZE" do cabeçalho da biblioteca "libft" é igual a 1, para evitar vazamentos de memória.

# Makefile

* para gerar o executavel use make
```
Make
```


## tests

- Para rodar alguns testes de validação do mapa, você pode usar o comando "make tests". Ele executará todos os testes automaticamente. Alguns testes podem estar comentados, então você pode verificá-los na pasta "tests". Caso altere o código, você pode rodar o comando "make tests" novamente para verificar se nada está fora dos padrões.

```
Make tests
```
- Caso algum teste de erro seja executado e o arquivo executável não seja deletado, você pode deletá-lo automaticamente para que o código possa ser reexecutado novamente. <br> ![error teste](.github/error_tst.png)



## test valgrind

- O arquivo Makefile também possui a funcionalidade de rodar os testes com o Valgrind para verificar possíveis erros e vazamentos de memória. Basta usar a opção "vg" antes da palavra "teste".

```
Make vgtests
```

## unic test

- Caso queria você também pode rodar um test individual.

```
Make test t=<caminho dentro da past test>
exemplo
Make test t=parser/extract_data nota que nao colocamos a extenção do arquivo
```

## unic test vg

- Para rodar um arquivo de teste individualmente com o Valgrind, basta usar a opção "vg" antes do nome do teste.

```
Make vgtest t=parser/extract_data
```

Lembrando que alguns test podem estar comentando para um melhor funcionamento.

# MOD DEGUB 🌈

Caso queria ativar o modo debug do nosso projeto você pode passar a flag -D apos os parametros do executavel

![teste](.github/modo_debug.png)

Você também pode ativar o modo debug em qualquer uma parte do codigo usando a função `set_flag(TRUE)`, as informaçoes começarão a ser imprimidas a partir dali. A função `set_flag(TRUE)` também funciona dentro do escopo dos test. Caso queria receber mais informação sobre o que esta ocorrendo no test você pode ativar a função. <br>Obs: e muito mais ultio ultilizala nas pastas test.

![teste](.github/set_flag_true.png)
