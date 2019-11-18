#include <iostream>
#include<new>

struct chaff
{
	char dross[20];
	int slag;
};

void fill(chaff *a);
void show(const chaff *a);
const int Size = 5;
chaff buffor[5];

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	for (int i = 0; i < 5; i++)
		cout << "Adresy komorek buffora:/n" << i + 1 << " : " << (buffor+i) << endl;
	chaff * a = new chaff;
	chaff * b = new(buffor) chaff;
	fill(a);
	fill(b);
	show(a);
	show(b);
	chaff * c = new((buffor+1)) chaff;
	fill(c);
	show(c);

	cin.get();
	return 0;
}

void fill(chaff *a)
{
	using std::cout;
	using std::cin;
	cout << "Podaj tekst: ";
	cin.get(a->dross, 20);
	cout << "Podaj wartosc: ";
	cin >> a->slag;
	while (cin.get() != '\n')
		continue;
}
void show(const chaff *a)
{
	using std::cout;
	using std::endl;
	cout << "dross: " << a->dross << "\tadres dross: " << &a->dross <<
		"\nslag: " << a->slag << "\tadres slag: " << &a->slag << endl;
}