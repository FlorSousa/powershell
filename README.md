# Rinha de compiladores - grupo Powershell
#### Pessoas: [João Barros](https://github.com/UmBarril), [Nycolas Costa](https://github.com/NycolasKCN), [Jhonatas Flor](https://github.com/FlorSousa)
#### Linguagem usada: <img style="width:25px; height:25px" src="https://seeklogo.com/images/C/c-language-logo-CE0F92E683-seeklogo.com.png">

<div align="center">



<img src="https://camo.githubusercontent.com/474e7ff0104a8e98d42eab75afd9bff5ce9a6fba7064708d3001e0944b8ec6c4/68747470733a2f2f75706c6f6164732e6a6f76656d6e6572642e636f6d2e62722f77702d636f6e74656e742f75706c6f6164732f323032322f30332f61732d6d656e696e61732d7375706572706f6465726f7361732d68626f2d6d61782e6a7067">

</div>

# Executando fora do docker

### Compilar com o make:

- Na pasta raiz do projeto rode:
```
git submodule update --init
```

- Entra na pasta json-c:
```
cd libs/json-c/
```

- Comando para compilar lib:
```
cmake .
```

- Na pasta raiz roda o comando make para compilar e linkar o compilador:
```
make
```

# Executando no docker (In progress)
