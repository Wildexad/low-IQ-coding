#include <iostream> 
#include <array> 
#include <cmath> 
 
int* creat_arr(int n) { 
 int* a = new int[n]; 
 for (int i = 0; i < n; i++) 
  std::cin >> a[i]; 
 return a; 
} 
 
int deep(int* a) { 
 int size = 1; 
 int degree = 0; 
 while (size < sizeof(a)) { 
  size *= 2; 
  degree++; 
 } 
 return degree; 
} 
 
void print(int* a, int n) { 
 for (int i = 0; i < n; i++) std::cout << a[i] << " "; 
 std::cout << std::endl; 
} 
 
void heapify(int* a, int i, int n) { 
 int max = 1; 
 while (true) { 
  int child = 2 * i + 1; 
  if (child < n && a[child] > a[max]) max = child; 
  child++; 
  if (child < n && a[child] > a[max]) max = child; 
  if (max == i) break; 
  else { 
   std::swap(a[max], a[i]); 
   i = max; 
  } 
 } 
} 
 
void print_tree(int* a) { 
 int width = pow(2, deep(a) - 1); 
 std::cout << a[0] << "\n"; 
 int index = 1; 
 for (int i = 1; i < deep(a); i++) { 
  int kol = 1; 
  for (kol; kol <= pow(2, i); kol++) { 
   std::cout << a[index] << " "; 
   index += 1; 
   if (a[index] == a[-1]) break; 
  } 
  std::cout << "\n"; 
 } 
} 
 
int main() { 
 setlocale(LC_ALL, "Russian"); 
 
 int n; 
 std::cout << "Размер массива: "; 
 std::cin >> n; 
 
 int* a = creat_arr(n); 
 std::cout << "Исходный массив\n"; 
 print(a, n); 
 for (int i = n / 2; i >= 0; i--) { 
  heapify(a, i, n); 
 } 
 std::cout << "Глубина дерева: " << deep(a) << "\n"; 
 std::cout << "Плоская двоичная куча\n"; 
 print(a, n); 
 std::cout << "Двоичная куча\n"; 
 print_tree(a); 
 return 0; 
}