# Dino2000

Este guia contém as instruções diretas para compilar e executar o projeto em ambientes Linux e Windows.

---

## 🐧 Executando no Linux

No Linux, você pode optar por usar o script de automação ou compilar manualmente via terminal usando o CMake.

### Opção 1: Com o script Bash (Automático)
Na pasta raiz do projeto, abra o terminal e execute os comandos abaixo para conceder permissão e iniciar o jogo:

```bash
chmod +x run.sh
./run.sh
```

### Opção 2: Sem o script Bash (Compilação Manual)
Caso não queira utilizar o atalho do bash, você pode compilar os arquivos manualmente. Abra o terminal na raiz do projeto e execute a seguinte sequência:

```bash
mkdir build
cd build
cmake ..
make
./ProjetoGame
```

---

## 🪟 Executando no Windows

Para rodar o projeto no Windows, a forma recomendada é utilizar a integração nativa do Visual Studio com arquivos CMake.

1. Abra o **Visual Studio** (certifique-se de ter o suporte a "Desenvolvimento para Desktop com C++" e ferramentas CMake instalados).
2. Na tela inicial, clique em **"Abrir uma pasta local"** e selecione a pasta raiz deste projeto.
3. Aguarde alguns instantes para que o Visual Studio leia o arquivo `CMakeLists.txt` e configure o cache do ambiente automaticamente.
4. Na barra de ferramentas no topo da tela, clique no menu suspenso de **Destino de Inicialização** (Startup Item) e selecione o executável do seu jogo.
5. Clique no botão de **"Play"** (ou aperte a tecla `F5`) para compilar e iniciar o jogo.
