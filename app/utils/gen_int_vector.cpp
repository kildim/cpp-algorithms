#include <climits>
#include <fstream>
#include <iostream>
#include <random>
#include <set>

int main() {
  int count;

  std::cout << "Утилита записывает в файл ./mock/data.txt заданное количество "
               "произвольных не повторяющихся целых чисел."
            << std::endl;
  std::cout << "Введите количество случайных чисел: ";
  std::cin >> count;

  // Устанавливаем диапазон случайных чисел
  int min_num = 0;
  int max_num = INT_MAX;

  std::set<int> random_numbers;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(min_num, max_num);

  while (random_numbers.size() < static_cast<size_t>(count)) {
    int num = dist(gen);
    random_numbers.insert(num);
  };

  std::ofstream outputFile("./mock/data.txt"); // Открытие файла для записи
  if (!outputFile.is_open()) {
    std::cerr << "Не удалось открыть файл для записи." << std::endl;
    return 1;
  }

  for (const int &num : random_numbers) {
    outputFile << num << " ";
  };

  outputFile.close();

  return 0;
}
