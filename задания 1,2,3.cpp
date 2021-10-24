#include <iostream>
using namespace std;
int progression(int mas[], const int N) {
	int a, b;
	cout << "Введите 1- й элемент ";
	cin >> a;
	cout << "Введите разность ";
	cin >> b;
	mas[0] = a;
	for (int i = 1; i < N; i++) {
		mas[i] = a + b;
		a += b;
	}
	return(mas[N]);
}
int random_generate(int max,int min) {
	double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return(static_cast<int>(rand() * fraction * (max - min + 1) + min));
}
int progression2(int mas[], const int N) {
	srand(time(0));
	rand(); //первый пустой вызов для обхода проблемы реализации rand() в VS
	int buf;
	int min = 0;
	int max = N;
	for (int i = 0; i < N; i++) {
		mas[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		buf = mas[i];
		int x = random_generate(N - 1,0);
		mas[i] = mas[x];
		mas[x] = buf;
	}
	return(mas[N]);
}
int progression3(int mas[], const int N) {
	srand(time(0));
	rand();
	int count = 0;
	for (int i = 0; i < N; i++) {
		mas[i] = random_generate(2000, 1000);
		if (((mas[i] / 10) % 10) % 2 == 0) {
			count += 1;
		}
	}
	cout << "число элементов, у которых вторая с конца цифра – чётная = " << count << "\n";
	return(mas[N]);
}
void print_array(int mas[], const int N) {
	for (int i = 0; i < N; i++) {
		cout << mas[i] << " ";
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	// "Введите  длину необходимого массива";
	const int N = 10;
	int mas[N];
	int number;
	cout << "Введите номер задания 1-3: ";
	cin >> number;
	if (number == 1) {
		progression(mas, N);
	}
	else if (number == 2) {
		progression2(mas, N);
	}
	else if (number == 3) {
		progression3(mas, N);
	}
	else
		return(0);
	print_array(mas, N);
	return (0);

}
