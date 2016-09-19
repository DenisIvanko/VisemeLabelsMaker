// VisemeLabelsMaker.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	//const int len = 30;
	//const int strings = 200;
	//const char ch = '\n';
	//char mass[len][strings];

	//std::string INPUT_FILE_NAME = "C:\\Users\\denis\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\VisemeLabelsMaker\\VisemeLabelsMaker\\Labels\\1\\001-essv_001.lab";

	//std::ifstream labelFile(INPUT_FILE_NAME, std::ios::in | std::ios::binary);
	//if (!labelFile) return 1;

	//for (int r = 0; r<strings; r++)
	//{
	//	labelFile.getline(mass[r], len - 1, ch); //Считываем строки в массив
	//	std::cout << "String " << r + 1 << " = " << mass[r] << std::endl; //Выводи строку из массива
	//}
	//labelFile.close();

	std::string LINE;
	
	std::string OUTPUT_FILE_NAME = "C:\\Users\\denis\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\VisemeLabelsMaker\\VisemeLabelsMaker\\Labels\\1\\V001-essv_001.lab";
	std::string INPUT_FILE_NAME = "C:\\Users\\denis\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\VisemeLabelsMaker\\VisemeLabelsMaker\\Labels\\1\\001-essv_001.lab";

	std::ifstream labelFile(INPUT_FILE_NAME);
	std::ofstream VlabelFile(OUTPUT_FILE_NAME);

	if (labelFile.is_open())
	{
		if (VlabelFile.is_open())
		{
			while (labelFile.good())
			{
				getline(labelFile, LINE);

				VlabelFile << LINE << std::endl;
				std::cout << LINE << std::endl;
			}
			labelFile.close();
		}
		else std::cout << "Unable to open output file" << std::endl;
	}
	else std::cout << "Unable to open input file" << std::endl;
    

	return 0;
}

