#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;





// Classe abstrata PERSONAGEM

class Personagem {
private:
    string nome;
    int vida;
    int vidaMaxima;
    int forcaAtaque;
    int defesa;

protected:
    // Calcula o dano bruto: ataque do personagem vezes o multiplicador do golpe
    int calcularDano(double multiplicador) const {
        return static_cast<int>(round(getForcaAtaque() * multiplicador));
    }

    // Aplica o golpe em outro personagem.
    void aplicarGolpe(Personagem& alvo, const string& nomeGolpe, double multiplicador) const {
        int danoBruto = calcularDano(multiplicador);

        cout << "\n" << getNome() << " usou " << nomeGolpe << ".\n";
        cout << "Dano bruto causado: " << danoBruto << "\n";

        alvo.receberDano(danoBruto);
    }

public:
    // Construtor da classe base
    Personagem(const string& nome, int vida, int forcaAtaque, int defesa)
        : nome(nome),
          vida(vida),
          vidaMaxima(vida),
          forcaAtaque(forcaAtaque),
          defesa(defesa) {}

    // Destrutor virtual, usado na herança e polimorfismo.
    virtual ~Personagem() = default;

    // Get-  servem para consultar os atributos privados.
    string getNome() const {
        return nome;
    }

    int getVida() const {
        return vida;
    }

    int getVidaMaxima() const {
        return vidaMaxima;
    }

    int getForcaAtaque() const {
        return forcaAtaque;
    }

    int getDefesa() const {
        return defesa;
    }

    // Set - altera a vida com controle para não ficar menor que zero
    // nem maior que a vida máxima.
    void setVida(int novaVida) {
        vida = novaVida;

        if (vida < 0) {
            vida = 0;
        }

        if (vida > vidaMaxima) {
            vida = vidaMaxima;
        }
    }

    // Verifica se o personagem ainda está vivo.
    bool estaVivo() const {
        return vida > 0;
    }

    // Mostra os dados principais do personagem.
    void mostrarStatus() const {
        cout << getNome() << " [" << getClasse() << "]"
             << " | Vida: " << getVida() << "/" << getVidaMaxima()
             << " | Ataque: " << getForcaAtaque()
             << " | Defesa: " << getDefesa() << "\n";
    }

    // Recebe o dano do golpe, descontando a defesa.
    virtual void receberDano(int danoBruto) {
        int danoFinal = danoBruto - getDefesa();

        // Garante que todo golpe cause pelo menos 1 de dano.
        if (danoFinal < 1) {
            danoFinal = 1;
        }

        setVida(getVida() - danoFinal);

        cout << getNome() << " recebeu " << danoFinal << " de dano final.\n";
        cout << "Vida atual de " << getNome() << ": "
             << getVida() << "/" << getVidaMaxima() << "\n";
    }

    // Métodos virtuais puros
    // Eles tornam Personagem uma classe abstrata.
    virtual string getClasse() const = 0;
    virtual void mostrarGolpes() const = 0;
    virtual void executarGolpe(int opcao, Personagem& alvo) const = 0;

    // Cria uma cópia do personagem escolhido para a batalha.
    virtual unique_ptr<Personagem> clonar() const = 0;
};



//  CLASSES FILHAS
//  GUERREIRO 

class Guerreiro : public Personagem {
public:
    Guerreiro(const string& nome, int vida, int forcaAtaque, int defesa)
        : Personagem(nome, vida, forcaAtaque, defesa) {}

    string getClasse() const override {
        return "Guerreiro";
    }

    void mostrarGolpes() const override {
        cout << "1 - Corte de Espada      (1.20x ataque)\n";
        cout << "2 - Investida de Escudo  (1.55x ataque)\n";
        cout << "3 - Golpe Esmagador      (1.90x ataque)\n";
    }

    void executarGolpe(int opcao, Personagem& alvo) const override {
        switch (opcao) {
            case 1:
                aplicarGolpe(alvo, "Corte de Espada", 1.20);
                break;

            case 2:
                aplicarGolpe(alvo, "Investida de Escudo", 1.55);
                break;

            case 3:
                aplicarGolpe(alvo, "Golpe Esmagador", 1.90);
                break;

            default:
                cout << "Golpe invalido.\n";
                break;
        }
    }

    unique_ptr<Personagem> clonar() const override {
        return make_unique<Guerreiro>(*this);
    }
};


//  MAGO

class Mago : public Personagem {
public:
    Mago(const string& nome, int vida, int forcaAtaque, int defesa)
        : Personagem(nome, vida, forcaAtaque, defesa) {}

    string getClasse() const override {
        return "Mago";
    }

    void mostrarGolpes() const override {
        cout << "1 - Bola de Fogo       (1.30x ataque)\n";
        cout << "2 - Raio Arcano        (1.65x ataque)\n";
        cout << "3 - Explosao Mistica   (2.00x ataque)\n";
    }

    void executarGolpe(int opcao, Personagem& alvo) const override {
        switch (opcao) {
            case 1:
                aplicarGolpe(alvo, "Bola de Fogo", 1.30);
                break;

            case 2:
                aplicarGolpe(alvo, "Raio Arcano", 1.65);
                break;

            case 3:
                aplicarGolpe(alvo, "Explosao Mistica", 2.00);
                break;

            default:
                cout << "Golpe invalido.\n";
                break;
        }
    }

    unique_ptr<Personagem> clonar() const override {
        return make_unique<Mago>(*this);
    }
};


//  ARQUEIRO 

class Arqueiro : public Personagem {
public:
    Arqueiro(const string& nome, int vida, int forcaAtaque, int defesa)
        : Personagem(nome, vida, forcaAtaque, defesa) {}

    string getClasse() const override {
        return "Arqueiro";
    }

    void mostrarGolpes() const override {
        cout << "1 - Flecha Rapida       (1.25x ataque)\n";
        cout << "2 - Tiro Preciso        (1.70x ataque)\n";
        cout << "3 - Chuva de Flechas    (2.05x ataque)\n";
    }

    void executarGolpe(int opcao, Personagem& alvo) const override {
        switch (opcao) {
            case 1:
                aplicarGolpe(alvo, "Flecha Rapida", 1.25);
                break;

            case 2:
                aplicarGolpe(alvo, "Tiro Preciso", 1.70);
                break;

            case 3:
                aplicarGolpe(alvo, "Chuva de Flechas", 2.05);
                break;

            default:
                cout << "Golpe invalido.\n";
                break;
        }
    }

    unique_ptr<Personagem> clonar() const override {
        return make_unique<Arqueiro>(*this);
    }
};



// Função auxiliar

// le uma opção do usuário e só aceita valores dentro do intervalo permitido.
int lerOpcao(int minimo, int maximo) {
    int opcao;

    while (true) {
        cout << "Escolha uma opcao: ";

        if (cin >> opcao) {
            if (opcao >= minimo && opcao <= maximo) {
                return opcao;
            }
        } else {
            cin.clear();
        }

        cout << "Opcao invalida. Digite um numero entre "
             << minimo << " e " << maximo << ".\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// Cadastra os personagens
void cadastrarPersonagens(vector<unique_ptr<Personagem>>& personagens) {
    personagens.push_back(make_unique<Guerreiro>("Ares", 150, 29, 15));
    personagens.push_back(make_unique<Guerreiro>("Bruna", 145, 31, 13));
    personagens.push_back(make_unique<Guerreiro>("Caio", 160, 27, 17));
    personagens.push_back(make_unique<Guerreiro>("Dara", 140, 33, 12));

    personagens.push_back(make_unique<Mago>("Elora", 110, 39, 7));
    personagens.push_back(make_unique<Mago>("Fenix", 105, 42, 6));
    personagens.push_back(make_unique<Mago>("Gael", 115, 37, 8));

    personagens.push_back(make_unique<Arqueiro>("Helena", 125, 34, 10));
    personagens.push_back(make_unique<Arqueiro>("Igor", 130, 32, 11));
    personagens.push_back(make_unique<Arqueiro>("Jade", 120, 36, 9));
}


// Mostra e percorre o vetor personagens
void mostrarPersonagens(const vector<unique_ptr<Personagem>>& personagens) {
    cout << "\n========== PERSONAGENS DISPONIVEIS ==========\n";

    for (int i = 0; i < static_cast<int>(personagens.size()); i++) {
        cout << i + 1 << " - ";
        personagens[i]->mostrarStatus();
    }

    cout << "==============================================\n";
}


// Sorteia um oponente diferente do jogador
int sortearOponente(int indiceJogador, int quantidadePersonagens) {
    int indiceOponente;

    do {
        indiceOponente = rand() % quantidadePersonagens;
    } while (indiceOponente == indiceJogador);

    return indiceOponente;
}


// Sorteia o golpe usado pelo sistema
int sortearGolpeSistema() {
    return (rand() % 3) + 1;
}


// Controla a batalha entre jogador e sistema
void iniciarCombate(Personagem& jogador, Personagem& sistema) {
    int rodada = 1;

    cout << "\n========== INICIO DO COMBATE ==========\n";
    cout << jogador.getNome() << " VS " << sistema.getNome() << "\n";

    while (jogador.estaVivo() && sistema.estaVivo()) {
        cout << "\n---------- RODADA " << rodada << " ----------\n";

        cout << "\nSeu personagem:\n";
        jogador.mostrarStatus();

        cout << "\nPersonagem do sistema:\n";
        sistema.mostrarStatus();

        cout << "\nEscolha seu golpe:\n";
        jogador.mostrarGolpes();

        int golpeJogador = lerOpcao(1, 3);

        // Jogador ataca o sistema
        jogador.executarGolpe(golpeJogador, sistema);

        // Se o sistema morreu, a luta acaba imediatamente
        if (!sistema.estaVivo()) {
            break;
        }

        // Sistema ataca o jogador
        int golpeSistema = sortearGolpeSistema();

        cout << "\nO sistema escolheu o golpe " << golpeSistema << ".\n";

        sistema.executarGolpe(golpeSistema, jogador);

        // Se o jogador morreu, a luta acaba
        if (!jogador.estaVivo()) {
            break;
        }

        rodada++; //contador de rodada
    }

    cout << "\n========== FIM DO COMBATE ==========\n";

    if (jogador.estaVivo()) {
        cout << "Vencedor: USUARIO com " << jogador.getNome() << "!\n";
    } else {
        cout << "Vencedor: SISTEMA com " << sistema.getNome() << "!\n";
    }
}



// FUNÇÃO PRINCIPAL


int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<unique_ptr<Personagem>> personagens;

    cadastrarPersonagens(personagens);

    cout << "========== SIMULACAO DE COMBATE ==========\n";

    mostrarPersonagens(personagens);

    cout << "\nEscolha o seu lutador.\n";
    int escolhaJogador = lerOpcao(1, static_cast<int>(personagens.size())) - 1;

    int escolhaSistema = sortearOponente(
        escolhaJogador,
        static_cast<int>(personagens.size())
    );

    unique_ptr<Personagem> jogador = personagens[escolhaJogador]->clonar();
    unique_ptr<Personagem> sistema = personagens[escolhaSistema]->clonar();

    cout << "\nVoce escolheu: ";
    jogador->mostrarStatus();

    cout << "\nO sistema escolheu: ";
    sistema->mostrarStatus();

    iniciarCombate(*jogador, *sistema);

    cout << "\nObrigado por jogar!\n";

    return 0;
}
