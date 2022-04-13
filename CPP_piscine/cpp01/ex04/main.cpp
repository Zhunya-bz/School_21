#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Error arguments" <<std::endl;
	else
	{
		std::ifstream	fin; // на чтение
		std::string		buf; // буфер для считывания и его же изменения
		std::string 	str; // для genline

		if (!strcmp(argv[2], "") || !strcmp(argv[3], "")) // порверка на пустоту строк
		{
			std::cout << "Line is empty!" << std::endl;
			return (1);
		}
		fin.open(argv[1]); // открытие файла
		if (!fin.is_open()) // ошибка открытия
			std::cout << "Error open file" <<std::endl;
		else
		{
			if ((fin.peek()) == EOF) // peek проверяет следующий символ//порверка на пустоту файла
			{
				std::cout << "File is empty!" << std::endl;
				fin.close();
				return (1);
			}
			while (!fin.eof()) // пока не конец файла
			{
				if (std::getline(fin, str))
				{
					buf.append(str);// добавляем в конец по одному сиволу
					buf.append("\n"); // записываем \n
				}
				else
					buf.append("\n");// если он встречает в строке только \n и после EOF, то добавляем его(str-пустая)
			}
			buf.erase(buf.size() - 1); // стираем последний \n
		}
		fin.close(); // закрываем файл
		size_t i = 0;
		while (i < buf.length())
		{
			i = buf.find(argv[2], i); //ищется номер первого вхождения подстроки argv1 в буфере
			if (i == std::string::npos) // если не нашли никакого вхождения то выходим
				break;
			buf.erase(i, strlen(argv[2])); // удаляется (чистится) первая подстрока в буфере
			buf.insert(i,argv[3]); // заменяется на вторую строку
			i += strlen(argv[3]);//сдвигается четчик строки
		}
//		std::cout << buf <<std::endl; //вывод ответа в консоль
		std::ofstream	fout; // на запись
		std::string 	filename;

		filename = argv[1];
		if (!(filename.find(".", 0) == std::string::npos)) // если нашли точку то стираем
			filename.erase(filename.find(".", 0));
		filename.append(".replace");
		fout.open(filename);
		fout << buf;
	}
	return (0);
}
