#include <iostream>

int mystrcmp(const char* str1, const char* str2);
int StringToNumber(char* str);
char* NumberToString(int number);
char* Uppercase(char* str1);
char* Lowercase(char* str2);
char* mystrrev(char* str2);

int main() {
	setlocale(LC_ALL, "ru");

	char first_str[] = "I'll be back";
	char second_str[] = "Why so serious?";

	std::cout << "Первая строка: |" << first_str << "|" << std::endl;
	std::cout << "Вторая строка: |" << second_str << "|" << std::endl << std::endl;
	std::cout << "Результат сравнения строк: " << mystrcmp(first_str, second_str) << std::endl << std::endl;

	char str_number[] = "123456789ABC";
	std::cout << "Конвертация строки в число: " << StringToNumber(str_number) << std::endl << std::endl;

	int32_t number = rand() + rand();//18508
	std::cout << "Конвертация числа в строку: " << NumberToString(number) << std::endl << std::endl;

	std::cout << "Результат строки в верхнем регистре: |" << Uppercase(first_str) << '|' << std::endl << std::endl;

	std::cout << "Результат строки в нижнем регистре: |" << Lowercase(second_str) << '|' << std::endl << std::endl;

	std::cout << "Результат реверса строки: |" << mystrrev(second_str) << '|' << std::endl << std::endl;

	return 0;
}

int mystrcmp(const char* str1, const char* str2) {
	int32_t compare = (strcmp(str1, str2));
	if (compare == 0) return 0;
	else if (compare < 0) return -1;
	else return 1;
}

int StringToNumber(char* str) {
	int32_t number = atoi(str);/*or: number = str - '0';
							   однако,Вам нужно будет доработать саму конструкцию,если symbol>1*/
	return number;
}

char* NumberToString(int number) {
	static char conversion[10] = "";
	snprintf(conversion, sizeof(conversion), "%d", number);/*Можно использовать std::to_string.
															Но это программа расчитана без исп.библ.<string>(классы)*/
	return conversion;
}

char* Uppercase(char* str1) {
	for (int i = 0; i < strlen(str1) - 1; i++)	str1[i] = toupper(str1[i]);
	return str1;
}

char* Lowercase(char* str2) {
	for (int i = 0; i < strlen(str2) - 1; i++)	str2[i] = tolower(str2[i]);
	return str2;
}

char* mystrrev(char* str2) {
	int32_t n = strlen(str2) - 1;
	for (int i = 0; i < strlen(str2) / 2; i++) {
		int tmp = str2[i];
		str2[i] = str2[n - i];
		str2[n - i] = tmp;
	}
	return str2;
}