#include <iostream>
#include <limits>

using namespace std;

void matrix_print(int** matrix, int size);

int main() {
    // setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int numbers[10];

    // Ввод чисел А1 ... А10
    for (int i = 0; i < 10; i++) {
        cout << "Введите число А" << i+1 << ": ";
        while (!(cin >> numbers[i])) {
            cout << "Ошибка. Проверьте введённые данные\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    int size;
    cout << "Введите размер для квадратичной матрицы: ";
    if (cin >> size && size > 0) {

        // Создание матрицы
        int** matrix = new int*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new int[size];
        }

        // Заполнение матрицы
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << "Введите элемент с индексом " << i+1 << " " << j+1 << ": ";
                while (!(cin >> matrix[i][j])) {
                    cout << "Ошибка. Проверьте введённые данные\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
        // Вывод чисел A:
        cout << "Числа A:\n";
        for (int i = 0; i < 10; i++) {
            cout << numbers[i] << " ";
        }

        // Вывод матрицы:
        cout << "\nИскомая матрица:\n";
        matrix_print(matrix, size);

        //Заменяем на 0:
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if ((i+j) % 2) continue;
                for (int a = 0; a < 10; a++) {
                    if (matrix[i][j] == numbers[a]) {
                        matrix[i][j] = 0;
                        break;
                    }
                }
            }
        }

        cout << "Получення матрица:\n";
        matrix_print(matrix, size);

        // Очистка памяти:
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        system("pause");

    } else {
        cout << "Ошибка. Проверьте введённые данные\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}

void matrix_print(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
}