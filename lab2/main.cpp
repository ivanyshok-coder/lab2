#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <map>
#include <set>
#include <string>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

bool inputError() {
    if (std::cin.fail()) {
        std::cout << "Ошибка ввода!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return true;
    }
    return false;
}

// ЗАДАНИЕ 1. Вариант 6
template <typename Container>
void processContainer(Container& c, const std::string& name) {
    auto itFirst = c.begin();
    auto itLast = std::prev(c.end());
    auto itMid = std::next(c.begin(), c.size() / 2);

    *itFirst *= 2;
    *itMid *= 2;
    *itLast *= 2;

    std::cout << name << " после удвоения: ";
    for (int x : c) std::cout << x << " ";
    std::cout << "\n";
}

void task1() {
    std::cout << "\nЗадание 1.\n";
    int n = 0;

    std::cout << "Введите нечетный размер (>=3) для вектора V: ";
    std::cin >> n;
    if (inputError() || n < 3 || n % 2 == 0) { std::cout << "Ошибка размера\n"; return; }
    std::vector<int> V;
    std::cout << "Введите элементы V: ";
    for (int i = 0; i < n; i++) { int x = 0; std::cin >> x; if (inputError()) return; V.push_back(x); }

    std::cout << "Введите нечетный размер (>=3) для дека D: ";
    std::cin >> n;
    if (inputError() || n < 3 || n % 2 == 0) { std::cout << "Ошибка размера\n"; return; }
    std::deque<int> D;
    std::cout << "Введите элементы D: ";
    for (int i = 0; i < n; i++) { int x = 0; std::cin >> x; if (inputError()) return; D.push_back(x); }

    std::cout << "Введите нечетный размер (>=3) для списка L: ";
    std::cin >> n;
    if (inputError() || n < 3 || n % 2 == 0) { std::cout << "Ошибка размера\n"; return; }
    std::list<int> L;
    std::cout << "Введите элементы L: ";
    for (int i = 0; i < n; i++) { int x = 0; std::cin >> x; if (inputError()) return; L.push_back(x); }

    processContainer(V, "Вектор V");
    processContainer(D, "Дек D");
    processContainer(L, "Список L");
}

// ЗАДАНИЕ 2. Вариант 3
void task2() {
    std::cout << "\nЗадание 2.\n";
    int n = 0;
    std::list<int> L;
    std::cout << "Введите размер списка (кратный 3): ";
    std::cin >> n;
    if (inputError()) return;
    if (n % 3 != 0) { std::cout << "Ошибка: размер должен быть кратен 3\n"; return; }

    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        int x = 0;
        std::cin >> x;
        if (inputError()) return;
        L.push_back(x);
    }

    auto it = L.begin();
    std::advance(it, n / 3);

    std::vector<int> temp(L.begin(), it);
    std::reverse(temp.begin(), temp.end());

    L.insert(L.end(), temp.begin(), temp.end());

    std::cout << "Результат: ";
    for (int x : L) std::cout << x << " ";
    std::cout << "\n";
}

// ЗАДАНИЕ 3. Вариант 9
void task3() {
    std::cout << "\nЗадание 3.\n";
    int n = 0;
    std::deque<int> D;
    std::cout << "Введите размер дека (кратный 4): ";
    std::cin >> n;
    if (inputError()) return;
    if (n % 4 != 0) { std::cout << "Ошибка: размер должен быть кратен 4\n"; return; }

    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        D.push_back(x);
    }

    auto it = D.begin();
    for (int i = 0; i < n / 4; i++) {
        ++it;
        it = D.erase(it);
    }

    std::cout << "Результат: ";
    for (int x : D) std::cout << x << " ";
    std::cout << "\n";
}

// ЗАДАНИЕ 4. Вариант 4
void task4() {
    std::cout << "\nЗадание 4.\n";
    int n = 0;
    std::vector<int> V;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    if (inputError()) return;

    std::cout << "Введите числа: ";
    for (int i = 0; i < n; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        V.push_back(x);
    }

    std::ofstream file("name.txt");
    std::ostream_iterator<int> out_it(file, "  ");

    std::replace_copy(V.begin(), V.end(), out_it, 0, 10);
    file.close();

    std::cout << "Результат записан в файл name.txt\n";
}

// ЗАДАНИЕ 5. Вариант 8
void task5() {
    std::cout << "\nЗадание 5.\n";
    int n = 0, k = 0;
    std::vector<int> V;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    if (inputError()) return;

    std::cout << "Введите вектор (только 0 и 1): ";
    for (int i = 0; i < n; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        V.push_back(x);
    }
    std::cout << "Введите K: ";
    std::cin >> k;
    if (inputError()) return;

    auto it = std::search_n(V.rbegin(), V.rend(), k, 0);
    if (it != V.rend()) {
        V.erase((it + k).base(), it.base());
    }

    std::cout << "Результат: ";
    for (int x : V) std::cout << x << " ";
    std::cout << "\n";
}

// ЗАДАНИЕ 6. Вариант 8
void task6() {
    std::cout << "\nЗадание 6.\n";
    int n1 = 0, n2 = 0;
    std::list<int> L1, L2;

    std::cout << "Введите размер L1 (кратный 4): ";
    std::cin >> n1;
    if (inputError() || n1 % 4 != 0) { std::cout << "Ошибка размера\n"; return; }
    std::cout << "Введите элементы L1: ";
    for (int i = 0; i < n1; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        L1.push_back(x);
    }

    std::cout << "Введите размер L2 (кратный 4): ";
    std::cin >> n2;
    if (inputError() || n2 % 4 != 0) { std::cout << "Ошибка размера\n"; return; }
    std::cout << "Введите элементы L2: ";
    for (int i = 0; i < n2; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        L2.push_back(x);
    }

    auto first = L1.begin();
    auto last = std::next(L1.begin(), n1 / 2 - 1);

    for (int i = 0; i < n1 / 4; i++) {
        std::swap(*first, *last);
        ++first;
        --last;
    }

    auto mid2 = L2.begin();
    std::advance(mid2, L2.size() / 2);
    std::reverse(mid2, L2.end());

    std::cout << "L1: ";
    for (int x : L1) std::cout << x << " ";
    std::cout << "\nL2: ";
    for (int x : L2) std::cout << x << " ";
    std::cout << "\n";
}

// ЗАДАНИЕ 7. Вариант 5
void task7() {
    std::cout << "\nЗадание 7\n";
    int n = 0;
    std::list<int> L;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    if (inputError()) return;

    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        L.push_back(x);
    }

    auto it = std::partition(L.begin(), L.end(), [](int x) { return x % 2 == 0; });

    std::cout << "Четных: " << std::distance(L.begin(), it) << "\n";
    std::cout << "Нечетных: " << std::distance(it, L.end()) << "\n";
}

// ЗАДАНИЕ 8. Вариант 1
void task8() {
    std::cout << "\nЗадание 8\n";
    int n = 0;
    std::list<int> L;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    if (inputError()) return;

    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        L.push_back(x);
    }

    std::vector<double> V;
    std::adjacent_difference(L.begin(), L.end(), std::back_inserter(V),
                             [](int right, int left) { return (right + left) / 2.0; });

    if (!V.empty()) V.erase(V.begin());

    std::cout << "Результат: ";
    for (double x : V) std::cout << x << " ";
    std::cout << "\n";
}

// ЗАДАНИЕ 9. Вариант 2
void task9() {
    std::cout << "\nЗадание 9\n";
    int n0 = 0, countVn = 0;
    std::vector<int> V0;

    std::cout << "Введите размер V0: ";
    std::cin >> n0;
    if (inputError()) return;
    std::cout << "Введите элементы V0: ";
    for (int i = 0; i < n0; i++) {
        int x = 0; std::cin >> x; if (inputError()) return;
        V0.push_back(x);
    }

    std::cout << "Введите количество векторов N: ";
    std::cin >> countVn;
    if (inputError()) return;

    std::vector<std::vector<int>> Vn;
    for (int i = 0; i < countVn; i++) {
        int size = 0;
        std::cout << "Введите размер вектора V" << i + 1 << ": ";
        std::cin >> size;
        if (inputError()) return;
        std::vector<int> temp;
        std::cout << "Введите элементы V" << i + 1 << ": ";
        for (int j = 0; j < size; j++) {
            int x = 0; std::cin >> x; if (inputError()) return;
            temp.push_back(x);
        }
        Vn.push_back(temp);
    }

    std::multiset<int> set0(V0.begin(), V0.end());
    int count = 0;

    for (const auto& vec : Vn) {
        std::multiset<int> setN(vec.begin(), vec.end());
        if (std::includes(setN.begin(), setN.end(), set0.begin(), set0.end())) {
            count++;
        }
    }
    std::cout << "Количество векторов: " << count << "\n";
}

// ЗАДАНИЕ 10. Вариант 4
void task10() {
    std::cout << "\nЗадание 10.\n";
    int n = 0;
    std::vector<std::string> V;
    std::cout << "Введите количество слов: ";
    std::cin >> n;
    if (inputError()) return;

    std::cout << "Введите слова (заглавные буквы): ";
    for (int i = 0; i < n; i++) {
        std::string s = ""; std::cin >> s; if (inputError()) return;
        V.push_back(s);
    }

    std::multimap<char, std::string> M;
    for (auto it = V.rbegin(); it != V.rend(); ++it) {
        char last_char = it->back();
        M.insert({last_char, *it});
    }

    std::cout << "Результат группировки:\n";
    for (const auto& pair : M) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    std::cout << "Лабораторная работа №2 (Вариант 8)\n";
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();

    return 0;
}