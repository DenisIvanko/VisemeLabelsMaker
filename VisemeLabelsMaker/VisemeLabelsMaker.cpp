// VisemeLabelsMaker.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

/**************************************************************************************************
Данная версия программы была скомунизжена с сайта http://ci-plus-plus-snachala.ru/?p=3679 
и приспособлена под нужды пролетариев
**************************************************************************************************/



/*ФУНКЦИЯ РАЗБИВАЕТ СТРОКУ НА СЛОВА ПРИ ЭТОМ УЧИТЫВАЕТ НЕ СЛОВА*/
std::vector<std::string> GetVectorString(const std::string& S) {
	std::vector<std::string> Vec(1);

	unsigned count = 0;
	unsigned i = 0;
	std::string temp;
	bool f = false;

	while (S[i]) {
		if ( isspace(S[i])) {
			if (f == true) {
				f = false;
				count++;
				Vec.push_back("");
			}
			Vec[count] += S[i];
		}
		else {
			if (f == false) {
				f = true;
				count++;
				Vec.push_back("");
			}
			Vec[count] += S[i];
		}
		i++;
	}
	return Vec;
}

int main()
{
	std::string PATH_TO_LABELS_FOLDER = ".\\Labels\\1\\";
	int NUMBER_OF_SPEAKERS = 11;
	int NUMBER_OF_PHRASES = 200;

	std::vector<std::string> v1;
	std::vector<std::string> v2;

	for (int SCount = 1; SCount <= NUMBER_OF_SPEAKERS; SCount++)
	{
		for (int PCount = 1; PCount <= NUMBER_OF_PHRASES; PCount++)
		{
			std::string INPUT_FILE_NAME = "";
			std::string OUTPUT_FILE_NAME = "";
			// Построение валидного адреса разетки
			INPUT_FILE_NAME += PATH_TO_LABELS_FOLDER;

			if (SCount < 100) {
				INPUT_FILE_NAME += ("0");
				if (SCount < 10) INPUT_FILE_NAME += ("0");
			}
			INPUT_FILE_NAME += std::to_string(SCount);

			INPUT_FILE_NAME += ("-essv_");

			if (PCount < 100) {
				INPUT_FILE_NAME += ("0");
				if (PCount < 10) INPUT_FILE_NAME += ("0");
			}
			INPUT_FILE_NAME += std::to_string(PCount);

			OUTPUT_FILE_NAME = INPUT_FILE_NAME + ("V");
			INPUT_FILE_NAME += (".lab");
			OUTPUT_FILE_NAME += (".lab");

			std::ifstream labelFile(INPUT_FILE_NAME);

			if (!labelFile.is_open())
			{
				std::cout << "Unable to open input file" << std::endl;
				continue;
			}

			std::ofstream VlabelFile(OUTPUT_FILE_NAME);

			if (!VlabelFile.is_open())
			{
				std::cout << "Unable to open output file" << std::endl;
				return -1;
			}

			std::string LINE;

			while (getline(labelFile, LINE)) {				//Читаем файл построчно
				v1 = GetVectorString(LINE);					//Разбиваем строку на слова и записываем даные в вектор
				v1.insert(v1.end(), "\n");					//Для корректной новой строки добавляем
				v2.insert(v2.end(), v1.begin(), v1.end());	//Склеиваем вектора
			}

			std::vector<std::string>::iterator it1;

			//Обход векторов и замена фонем на соответствующий класс визем (47 фонем, 10 визем)
			for (it1 = v2.begin(); it1 != v2.end(); it1++) {
				if (*it1 == "a" || *it1 == "a!") *it1 = "V1";
				if (*it1 == "y" || *it1 == "y!" || *it1 == "i" || *it1 == "i!" || *it1 == "e!") *it1 = "V2";
				if (*it1 == "o!" || *it1 == "u" || *it1 == "u!") *it1 = "V3";
				if (*it1 == "m" || *it1 == "m'" || *it1 == "b" || *it1 == "b'" || *it1 == "p" || *it1 == "p'") *it1 = "V4";
				if (*it1 == "f" || *it1 == "f!" || *it1 == "v" || *it1 == "v'") *it1 = "V5";
				if (*it1 == "sh" || *it1 == "zh" || *it1 == "ch" || *it1 == "chs") *it1 = "V6";
				if (*it1 == "r" || *it1 == "r'" || *it1 == "l" || *it1 == "l'") *it1 = "V7";
				if (*it1 == "d" || *it1 == "d'" || *it1 == "t" || *it1 == "t'" || *it1 == "n" || *it1 == "n'" || *it1 == "s" ||
					*it1 == "s'" || *it1 == "c" || *it1 == "z" || *it1 == "z'") *it1 = "V8";
				if (*it1 == "k" || *it1 == "k'" || *it1 == "h" || *it1 == "h'" || *it1 == "j" || *it1 == "g" || *it1 == "g'") *it1 = "V9";
				if (*it1 == "SIL") *it1 = "V10";
			}

			//Вывод результата на экран и запись в файл
			for (it1 = v2.begin(); it1 != v2.end(); it1++)
			{
				std::cout << *it1;
				VlabelFile << *it1;
			}
			v1.clear();
			v2.clear();
			labelFile.close();
			VlabelFile.close();
		}
	}

	return 0;
}


/**********************************************************************************
Первоначальная версия программы, сохранена для истории
***********************************************************************************/

//int main()
//{
//	std::string LINE;
//	
//	std::string OUTPUT_FILE_NAME = "C:\\Users\\denis\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\VisemeLabelsMaker\\VisemeLabelsMaker\\Labels\\1\\V001-essv_001.lab";
//	std::string INPUT_FILE_NAME = "C:\\Users\\denis\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\VisemeLabelsMaker\\VisemeLabelsMaker\\Labels\\1\\001-essv_001.lab";
//
//	std::ifstream labelFile(INPUT_FILE_NAME);
//	std::ofstream VlabelFile(OUTPUT_FILE_NAME);
//
//	if (!labelFile.is_open())
//	{
//		std::cout << "Unable to open input file" << std::endl;
//		return -1;
//	}
//	
//	if (!VlabelFile.is_open())
//	{
//		std::cout << "Unable to open output file" << std::endl;
//		return -1;
//	}
//
//	while (labelFile.good())
//	{
//		getline(labelFile, LINE);
//		
//		for (int i = 0; i < LINE.length(); i++) 
//		{
//			if (LINE[i] == 'S') { // SIL - пауза
//				LINE[i] = 'V'; LINE[i + 1] = '1'; LINE[i + 2] = '0'; // TODO Придумать менее говнистый вариант замены букв в файле
//			}
//
//			if (LINE[i] == 'a') {
//				LINE[i] = 'V'; LINE += '1';
//			}
//
//			if (LINE[i] == 'a!') {
//				LINE[i] = 'V'; LINE[i + 1] = '1';
//			}
//
//			if (LINE[i] == 'o!') {
//				LINE[i] = 'V';
//				LINE += '3';
//			}
//			
//			if (LINE[i] == 'i') {
//				LINE[i] = 'V';
//				LINE += '2';
//			}
//
//			
//
//
//		}
//
//		VlabelFile << LINE << std::endl;
//		std::cout << LINE << std::endl;
//	}
//	labelFile.close();
//	VlabelFile.close();
//	return 0;
//}
