#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Classe base abstrata para Conta
class Account {
protected:
    string number;
    double balance;

    // Método para verificação de saldo (aspecto transversal)
    void checkBalance(double amount) const {
        if (balance < amount) {
            throw runtime_error("[ERRO] Saldo insuficiente na conta " + number +
                                "\nRequerido: " + to_string(amount) + 
                                ", Saldo: " + to_string(balance));
        }
    }

public:
    Account(string accNumber, double initialBalance) 
        : number(accNumber), balance(initialBalance) {}

    virtual ~Account() = default;

    // Método template para saque (une aspecto e lógica específica)
    void withdraw(double amount) {
        checkBalance(amount);  // Verificação transversal
        performWithdraw(amount); // Delega para subclasses
        cout << "Saque de " << amount << " realizado na conta " << number << endl;
    }

    virtual void performWithdraw(double amount) = 0; // Para implementação específica
};

// Implementações específicas das contas
class CurrentAccount : public Account {
public:
    CurrentAccount(string accNumber, double initialBalance)
        : Account(accNumber, initialBalance) {}

    void performWithdraw(double amount) override {
        balance -= amount;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string accNumber, double initialBalance)
        : Account(accNumber, initialBalance) {}

    void performWithdraw(double amount) override {
        balance -= amount * 0.99; // Exemplo: taxa de 1% para saque
    }
};

int main() {
    try {
        CurrentAccount contaCorrente("CC-123", 1000);
        SavingsAccount contaPoupanca("CP-456", 500);

        contaCorrente.withdraw(800);   // Bem-sucedido
        contaPoupanca.withdraw(600);   // Gerará erro

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}