
#include <iostream>
#include <ctime>

using namespace std;

#define tab "\t"
int main();
void Choise_columns(int**&arr, int& m, int& n);

//////////////////////////////////////////////////////////////////////////////////   Заготовленные функции

void ShowArrDuo(int**& arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}
void RandArrDuo(int**& arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 50;
		}

	}
}

//////////////////////////////////////////////////////////////////////////////////   Функции для работы со строками массива

void Arr_row_delete_index(int**& arr, int& m, int& n, int index)
{
	cout << "Введите индекс удаляемой строки\n";

	int** arr_copy = new int* [m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		arr_copy[i] = new int [n] {};
	}

	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			i < index ? arr_copy[i][j] = arr[i][j] : arr_copy[i][j] = arr[i + 1][j];
		}
	}

	delete[] arr;
	arr = arr_copy;
	m--;

}
void Arr_row_push_index(int**& arr, int& m, int& n, int index)
{

	int** arr_copy = new int* [m + 1]{};
	for (int i = 0; i < m + 1; i++)
	{
		arr_copy[i] = new int [n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			i < index ? arr_copy[i][j] = arr[i][j] : arr_copy[i+1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		arr_copy[index][i] = rand() % 50;
	}
	delete[] arr;
	arr = arr_copy;
	m++;

}
void Choise_row(int**& arr, int& m, int& n)
{
	system("cls");
	ShowArrDuo(arr, m, n);
	cout << endl << endl;
	cout << "Выберите действие с двумерным массивом\n"
		<< "1) Добавить строку в конец\n"
		<< "2) Добавить строку в начало\n"
		<< "3) Удалить строку в конце\n"
		<< "4) Удалить строку в начале\n"
		<< "5) Удалить строку по индексу\n"
		<< "6) Добавить строку по индексу\n"
		<< "7) Пересобрать массив\n"
		<< "8) Вернуться в начало программы\n"
		<< "9) Перейти к работе с столбцами массива\n"
		<< "10) Закрыть программу\n\n";

	int a = 0; cin >> a;
	system("cls");
	switch (a)
	{
	case 1:
	{
		Arr_row_push_index(arr, m, n, m);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_row(arr, m, n);
	}
	case 2:
	{
		Arr_row_push_index(arr, m, n, 0);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_row(arr, m, n);
	}
	case 3:
	{
		Arr_row_delete_index(arr, m, n, m);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_row(arr, m, n);
	}
	case 4:
	{
		Arr_row_delete_index(arr, m, n, 0);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_row(arr, m, n);
	}
	case 5:
	{
		ShowArrDuo(arr, m, n);
		cout << "Введите индекс удаляемого столбца\n";
		int index = 0; cin >> index;
		Arr_row_delete_index(arr, m, n, index);
		cout << endl << endl;
		system("cls");
		Choise_row(arr, m, n);
	}
	case 6:
	{
		ShowArrDuo(arr, m, n);
		cout << "Введите индекс добавляемого столбца\n";
		int index = 0; cin >> index;
		Arr_row_push_index(arr, m, n, index);
		cout << endl << endl;
		system("cls");
		Choise_row(arr, m, n);
	}
	case 7:
	{
		system("cls");
		RandArrDuo(arr, m, n);
		Choise_row(arr, m, n);
	}
	case 8:
	{
		system("cls");
		delete[] arr;
		main();
	}
	case 9:
	{
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 10:
	{
		exit(0);
	}
	}

}

///////////////////////////////////////////////////////////////////////////////      Функции для работы со столбцами массива

void Arr_columns_push_index(int**& arr, int& m, int& n, int index)
{
	index++;
	int** arr_copy = new int* [m]{};
	for (int i = 0; i < m; i++)
	{
		arr_copy[i] = new int [n+1] {};
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < index - 1; j++)
		{
			arr_copy[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		arr_copy[i][index - 1] = rand() % 50;
	}

	for (int j = 0; j < m; j++)
	{
		for (int i = index, k = index - 1; i < n+1; i++, k++)
		{
			arr_copy[j][i] = arr[j][k];
		}
	}
	delete[] arr;
	arr = arr_copy;
	n++;
}
void Arr_columns_delete_index(int**& arr, int& m, int& n, int index)
{
	index++;
	int** arr_copy = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr_copy[i] = new int[n - 1]{};
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < index - 1; j++)
		{
			arr_copy[i][j] = arr[i][j];
		}
	}



	for (int j = 0; j < m; j++)
	{
		for (int i = index, k = index - 1; i < n + 1; i++, k++)
		{
			arr_copy[j][k] = arr[j][i];
		}
	}
	delete[] arr;
	arr = arr_copy;
	n--;
}
void Choise_columns(int**& arr, int& m, int& n)
{
	system("cls");
	ShowArrDuo(arr, m, n);
	cout << endl << endl;
	cout << "Выберите действие с двумерным массивом\n"
		<< "1) Добавить столбец в конец\n"
		<< "2) Добавить столбец в начало\n"
		<< "3) Удалить столбец в конце\n"
		<< "4) Удалить столбец в начале\n"
		<< "5) Удалить столбец по индексу\n"
		<< "6) Добавить столбец по индексу\n"
		<< "7) Пересобрать массив\n"
		<< "8) Вернуться в начало программы\n"
		<< "9) Перейти к работе со строками массива\n"
		<< "10) Закрыть программу\n\n";


	int a = 0; cin >> a;
	system("cls");
	switch (a)
	{
	case 1:
	{
		Arr_columns_push_index(arr, m, n, n);
 		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 2:
	{
		Arr_columns_push_index(arr, m, n, 0);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 3:
	{
		Arr_columns_delete_index(arr, m, n, n);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 4:
	{
		Arr_columns_delete_index(arr, m, n, 0);
		ShowArrDuo(arr, m, n);
		cout << endl << endl;
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 5:
	{
		ShowArrDuo(arr, m, n);
		cout << "Введите индекс удаляемого столбца\n";
		int index = 0; cin >> index;
		Arr_columns_delete_index(arr, m, n, index);
		cout << endl << endl;
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 6:
	{
		ShowArrDuo(arr, m, n);
		cout << "Введите индекс добавляемого столбца\n";
		int index = 0; cin >> index;
		Arr_columns_push_index(arr, m, n, index);
		cout << endl << endl;
		system("cls");
		Choise_columns(arr, m, n);
	}
	case 7:
	{
		system("cls");
		RandArrDuo(arr, m, n);
		Choise_columns(arr, m, n);
	}
	case 8:
	{
		system("cls");
		delete[] arr;
		main();
	}
	case 9:
	{
		system("cls");
		Choise_row(arr, m, n);
	}
	case 10:
	{
		exit(0);
	}
	}

}

//////////////////////////////////////////////////////////////////////////////       Главный switch

void Choise_main(int**& arr, int& m, int& n)
{
	system("cls");
	ShowArrDuo(arr, m, n);
	cout << "\n\n1)Изменять строки массива\n2)Изменять столбцы массива\n";
	int a = 0; cin >> a;
	switch (a)
	{
	case 1:
		{
			Choise_row(arr,m,n);
		}
	case 2:
	    {
		Choise_columns(arr, m, n);
	    }
	}
}

//////////////////////////////////////////////////////////////////////////////        main()
int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Введите строки\n";
	int m = 0; cin >> m;
	cout << "Введите столбцы\n";
	int n = 0; cin >> n;
	system("cls");

	int** arr = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int [n] {};
	}

	RandArrDuo(arr, m, n);
	ShowArrDuo(arr, m, n);
	cout << endl << endl;
	
	Choise_main(arr, m, n);
	ShowArrDuo(arr, m, n);

}
