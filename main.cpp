#include <iostream>
#include <vector>

using namespace std;

int main() {

 vector<vector<int>> Z(4, vector<int>(5));
 cout << "Введите матрицу Z (4x5):" << endl;
 /** 
 * @brief ввод матрицы Z
 * @param i параметр для строк
 * @param j параметр для столбцов
 * @param Z матрица (4,5)
 */
   for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 5; j++) {
           cin >> Z[i][j];
       }
   }

  vector<int> zeroRows;
 /** 
 * @brief Определение индексов строк, начинающихся с нуля
 * @param i параметр для строк
 * @param Z матрица (4,5)
 * @param zeroRows динамический массив, где сохраняются индексы строк, начинающихся с "0"
 */
  for (int i = 0; i < 4; i++) {
    if (Z[i][0] == 0) {
      zeroRows.push_back(i);
    }
  }

  // Переписывание элементов в обратном порядке для строк, начинающихся с нуля
  for (int i : zeroRows) {
    for (int j = 0; j < 5 / 2; j++) {
      swap(Z[i][j], Z[i][4 - j]);
    }
  }

  // Определение отрицательных элементов и сохранение их в массиве B
  vector<int> B;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      if (Z[i][j] < 0) {
        B.push_back(Z[i][j]);
      }
    }
  }

  // Печать исходной матрицы Z
  cout << "Исходная матрица Z:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      cout << Z[i][j] << " ";
    }
    cout << endl;
  }

  // Печать преобразованной матрицы Z
  cout << "Преобразованная матрица Z:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      cout << Z[i][j] << " ";
    }
    cout << endl;
  }

  // Печать массива B
  cout << "Массив B отрицательных элементов:" << endl;
  for (int i : B) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}