#include <iostream>
using namespace std;

const int MAX_LENGTH=7;

void selection_sort(int [], const int);
void bubble_sort(int [], const int);
void insertion_sort(int [], const int);

void swap(int [], int, int);
void fill_array(int [], const int);
void print_array(const int [], const int);
int binary_search_iterative(const int[], const int);
int binary_search_recursive(int [], int, int, const int);

int main(){
  int array[MAX_LENGTH];

  // Въвеждаме масива:
  fill_array(array, MAX_LENGTH);
  cout << "Original: ";
  print_array(array, MAX_LENGTH);

  // Сортираме масива, използвайки някой от имплементираните методи:
  // selection_sort(array, MAX_LENGTH);
  insertion_sort(array, MAX_LENGTH);
  cout << "Sorted: ";
  print_array(array, MAX_LENGTH);

  // Търсим дадена стойност, използвайки
  // Двоично Търсене, СЛЕД като сме сортирали масива:
  int search_value;
  cout << "Enter search value: ";
  cin  >> search_value;
  int found_at = binary_search_recursive(array, 0, MAX_LENGTH-1, search_value);
  if(found_at == -1){
    cout << "Value " << search_value << " not found.\n";
  } else {
    cout << "Value " << search_value << " found at index: " \
         << found_at << "\n";
  }

  return 0;
}


// Описание:
//      Разменя два елемента в масив.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -int i, j - индекси на чиито елементи подлежат на размяна
void swap(int array[], int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}


// Описание:
//      Сортира масив по използвайки Selection Sort.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void selection_sort(int array[], const int array_length){
  int min;
  // На всяка стъпка първите i елементи са вече сортирани:
  for(int i=0; i<array_length-1; i++){
    // Минималният елемент е текущият елемент:
    min = i;
    // За всеки останали array_length - i на брой елементи
    // проверяваме дали някой от тях е по-малък от текущия минимален,
    // , ако е така, то ги разменяме:
    for(int j=i+1; j<array_length; j++){
      if(array[j] < array[min]){
	min = j;
	swap(array, i, j);
      }
    }
  }
}


// Описание:
//      Сортира масив използвайки Bubble Sort.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void bubble_sort(int array[], const int array_length){
  bool swaped;
  for(int i=0; i < array_length-1; i++){
    swaped = false;
    // Последните i елементи вече са на правилните им позиции,
    // затова имаме array_length-i-1:
    for(int j=0; j < array_length-i-1; j++){
      // Проверяваме последователно всяка двойка елементи в масива
      // и разменяме елементите, ако текущия има по-голяма стойност
      // от следващият.
      if(array[j] > array[j+1]){
	swap(array,j,j+1); // Разменяме местата на j-тия и j+1-вия елемент
	swaped = true; 
      }
    }
    // Ако вътрешния цикъл не е разменил нито един
    // елемент, то тогава може да заключим, че
    // масива вече е сортиран:
    if(!swaped) break;
  }
}


// Описание:
//      Сортира масив използвайки Insertion Sort.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -const int array_length - големината на масива
void insertion_sort(int array[], const int array_length){
  for(int i=1; i < array_length; i++){
    // Взимаме първия елемент (i-тият в този случай) от несортираната част и проверяваме дали
    // e по-малък от елемент от сортираната част (с индекси [0, i)). В случай, че е по-малък то
    // разменяме местата им и повтаряме процедурата докато не намерим правилната позиция
    // на разглеждания елемент (няма елемнти в ляво от него, които са по-малки от него):
    for(int j=i; j > 0 && array[j] < array[j-1]; j--) swap(array, j, j-1);
  }
}


// Описание:
//      Намира индекс на търсена стойност в сортиран масив, използвайки
//      Двоично Търсене (итеративен вариант). Последователно разделя масива на леви/десни интервали за
//      търсене в зависимост от това дали търсената стойност е < или > от
//      стойността в средата на интервала.
// Входни параметри на функцията:
//     -const int array[] - указател към масив
//     -const int value   - търсената стойност в масива
// Връщан резултат:
//     -int - Връща индекс в масива, където се намира търсената стойност.
//            Връща -1 ако такава не бъде открита.
int binary_search_iterative(const int arr[], const int value){
  int left   = 0;
  int right  = MAX_LENGTH - 1;
  int middle = -1;

  while(left <= right){
    middle = (left + right) / 2;
    if(arr[middle] < value) left = middle + 1;
    else if(arr[middle] > value) right = middle - 1;
    else return middle;
  }
  return -1;
}


// Описание:
//      Намира индекс на търсена стойност в сортиран масив, използвайки
//      Двоично Търсене (рекурсивен вариант). Последователно разделя масива на леви/десни интервали за
//      търсене в зависимост от това дали търсената стойност е < или > от
//      стойността в средата на интервала.
// Входни параметри на функцията:
//     -int array[] - указател към масив
//     -int left, right - начало и край на интервала за търсене
//     -const int search_value - търсената стойност в масива
// Връщан резултат:
//     -int - Връща индекс в масива, където се намира търсената стойност.
//            Връща -1 ако такава не бъде открита.
int binary_search_recursive(int array[], int left, int right, const int value){
  if(right >= left){
    // Изчисление на средата на интервала:
    int middle = left + (right-left)/2;
    // Ако търсената стойност съвпада със стойността в средата на интервала:
    if(array[middle] == value) return middle;
    // Ако търсената стойност е < от стойността в средата на интервала,
    // то търсим в левия подинтервал:
    if(value < array[middle]) right = middle-1;
    // Ако търсената стойност е > от стойността в средата на интервала,
    // то търсим в десния подинтервал:
    if(value > array[middle]) left  = middle+1;
    // Рекурсивно извикваме функцията с новите граници на интервала:4 2
    return binary_search_recursive(array, left, right, value);
  }
  return -1;
}


void fill_array(int array[], const int array_length){
  cout << "Enter array`s contents (length " << MAX_LENGTH << "):\n";
  for(int i=0; i < array_length; i++){
    cout << "[" << i << "]=";
    cin  >> array[i];
  }
}


void print_array(const int array[], const int array_length){
  for (int i=0; i < array_length; i++) {
    cout << "|" << array[i] << "|" << " ";
  }
  cout << "\n";
}
