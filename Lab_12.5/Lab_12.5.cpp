#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1;
	inform inf;
};

void Creata(Spusok*& top, inform inf);
void COUT(Spusok*& T);

void Copy(Spusok*& top, Spusok*& top1, Spusok* T);
void Process(Spusok*& top1, Spusok* T, Spusok* G, const int N);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* top = NULL;
	Spusok* top1 = NULL;

	int x, N = 4;
	for (int i = 0; i < N; i++)
	{
		x = 6 - rand() % 12;
		Creata(top, x);
	}


	cout << "Сформований стек 'до перетворення': " << endl << endl;
	Spusok* T = top;
	COUT(T);

	T = top;
	Copy(top, top1, T);

	cout << "Сформований стек 'після перетворення': " << endl << endl;
	T = top1;
	Spusok* G = top1;
	Process(top1, T, G, N);

	T = top1;
	COUT(T);

	return 0;
}

void Creata(Spusok*& top, inform inf)
{
	Spusok* tmp = new Spusok;

	tmp->inf = inf;
	if (top == NULL)
		tmp->link1 = NULL;
	else
		tmp->link1 = top;
	top = tmp;
}

void COUT(Spusok*& T)
{
	inform inf;

	while (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link1;
	}
	cout << endl << endl;
}

void Copy(Spusok*& top, Spusok*& top1, Spusok* T)
{
	inform x;
	while (T != NULL)    //копіюємо значення елементів стеку 'top' в стек 'top1'
	{
		x = T->inf; 
		T = T->link1; 
		Creata(top1, x);
	}
}

void Process(Spusok*& top1, Spusok* T, Spusok* G, const int N)
{
	inform x, y;
	int zmina, zmina_l = 1;       // 0(оголошення двох змінних)
	inform min_x;

	for (int i = 0; i < N; i++)
	{
		x = G->inf;               // 1(змінна 'x' отримає значення від елемента(інформаційного поля))
		min_x = x;                // 2(вважаємо що значення 'x' є максимальним ---> 'max_x')

		zmina = 0;                // 3('zmina' отримує значення 0)
		while (zmina < zmina_l)
		{
			T = T->link1;         // 4(вказівник 'T' переходить на нову позицію)
			zmina++;              // 5('zmina' змінює своє значення)
		}

		while (T != NULL)
		{
			x = T->inf;           // 6(змінна 'x' отримує значення елемента стека)
			if (min_x > x)
				min_x = x;        // 7(змінна 'max_x' отримує нового, більшого значення за попереднє від змінної 'x')
			T = T->link1;         // 8(вказівник 'T' переходить на нову позицію елемента стеку)
		}

		T = top1;                 // 9(вказівник 'T' отримує адрусу вказівника 'top')
		x = G->inf;               // 10(змінна 'x' отримую значення елемента стеку)

		zmina = 0;                // 11('zmina' отримує значення 0)
		while (zmina < zmina_l)
		{
			T = T->link1;         // 12(вказівник 'T' переходить на нову позицію)
			zmina++;              // 13('zmina' змінює своє значення)
		}

		while (T != NULL)
		{
			y = T->inf;           // 14(змінна 'y' отримує значення від елемента стеку)
			if (y == min_x)
			{
				G->inf = min_x;   // 15(елемент отримує значення більшого елемента)
				T->inf = x;       // 16(а позиція більшого елемента замінюється значення елемнта поточної позиції(елемнта на який вказує вказівник 'G'))

				break;
			}
			T = T->link1;         // 17(вказівник 'T' переходить на нову позицію)
		}

		zmina_l++;                // 18(змінна 'zmina_l' збільшує своє значення на одиницю)

		T = top1;                 // 19(вказівник 'T' отримує значення адреси яке містить вказівник 'top1')
		G = G->link1;             // 20(вказівник 'G' переходить на нову позицію)
	}
}