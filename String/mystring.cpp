#include<iostream>
using namespace std;

// Функция определяет и выводит на экран самое длинное слово в предложении 
void LongestWord(const char *text)
{
	char word[100] = { };
	const char *begin = text, *end = nullptr;
	int length = 0;
	while (true)
	{
		while (*begin == ' ')
			begin++;
		end = strchr(begin, ' ');
		if (end != nullptr)
		{
			if (length < end - begin)
			{
				length = end - begin;
				strncpy_s(word, sizeof(word), begin, length);
				word[length] = '\0';
			}
			begin = end + 1;
		}
		else
		{
			if (strlen(begin) > length)
			{
				length = strlen(begin);
				strcpy_s(word, sizeof(word), begin);
			}
			break;
		}
	}
	cout << "\nThe longest word: " << word;
}

// Функция проверяет корректность передаваемого символа (0...9, +, -)
bool Check(char symbol)
{
	if (symbol >= '0' && symbol <= '9' || symbol == '+' || symbol == '-')
		return true;
	else
		return false;
}

// Функция вычисляет результат арифметического выражения
bool Arithmetic(const char *str, int &result)
{
	bool incorrect = true;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (Check(str[i]))
			continue;
		else
		{
			cout << "\nIncorrect symbol \'" << str[i] << "\' in position " << i;
			incorrect = false;
		}
	}
	if (!incorrect)
		return false;
	result = 0;
	while (*str != '\0')
	{
		result += atoi(str);
		str++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return true;
}