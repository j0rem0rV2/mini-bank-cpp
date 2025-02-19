Explicação do Código
Classe Base Account:

checkBalance(): Implementa a verificação transversal de saldo

withdraw(): Método template que combina verificação e delegação

performWithdraw(): Método virtual puro para implementação específica

Padrão Template Method:

A verificação de saldo é feita antes da operação de saque

As subclasses implementam apenas a lógica específica do saque

Tratamento de Erros:

Exceções são usadas para propagar erros de saldo insuficiente

O bloco try/catch na main captura e exibe os erros

Vantagens desta Implementação
Separação de Responsabilidades: A lógica transversal está isolada na classe base

Reuso de Código: Novas contas herdam automaticamente a verificação de saldo

Extensibilidade: Fácil adição de novos tipos de conta

Manutenibilidade: Regras de negócio centralizadas em um único ponto
