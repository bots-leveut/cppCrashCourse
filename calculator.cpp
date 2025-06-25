#include <cstdio>

enum class Operation
{
	Add,
	Substract,
	Multiply,
	Divide
};

struct Calculator
{
	Calculator()
	{
		op = Operation::Add;
	}

	bool setOperation(Operation newop)
	{
		op = newop;
	}

	Operation getOperation()
	{
		return op;
	}

	int compute(int a, int b)
	{
		switch (op)
		{
		case Operation::Add:
			return a + b;
		case Operation::Substract:
			return a - b;
		case Operation::Multiply:
			return a * b;
		case Operation::Divide:
			if (b == 0)
			{
				printf("error: zero divisor\n");
				return -2;
			}
			return a / b;
		default:
			return -1;
		}
	}

  private:
	Operation op;
};

int main(int argc, char *argv[])
{
	Calculator calculator;
	int a{17}, b{0};
	printf("Choisissez l'operation:\n");
	printf("1.Addition:\n");
	printf("2.Substract:\n");
	printf("3.Multiply:\n");
	printf("4.Divide:\n");
	int choix{};
	scanf("%d", &choix);
	switch (choix)
	{
	case 1:
		calculator.setOperation(Operation::Add);
		break;
	case 2:
		calculator.setOperation(Operation::Substract);
		break;
	case 3:
		calculator.setOperation(Operation::Multiply);
		break;
	case 4:
		calculator.setOperation(Operation::Divide);
		break;
	default:
		return -1;
	}

	int resultat = calculator.compute(a, b);
	printf("%d\n", resultat);
}