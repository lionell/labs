#include <iostream>
using std::cout;
using std::cin;


int main() {
  int number_of_columns; // êîë-âî ñòîëáèêîâ;
  cin >> number_of_columns;
  
  int height_of_columns[100];
  
  for (int i = 0; i < number_of_columns; i++)
      cin >> height_of_columns[i];
  
  int v = 0, k = 0, index = 0, difference_between_first_last = 0, last_index = 0;  
  bool flag = 0;
  
  for (int i = 0; i < number_of_columns - 1; i++) {
      if (flag == 0) 
      if (height_of_columns[i + 1] < height_of_columns[i]) {
          flag = 1; index = i;
      }     
      
      if (flag == 1) {
          if (height_of_columns[i + 1] < height_of_columns[index] && i != (number_of_columns - 2))
              k += height_of_columns[index] - height_of_columns[i + 1];
          else if (height_of_columns[i + 1] >= height_of_columns[index]){ 
              v += k;
              k = 0;
              flag = 0;             
          }
          
          else {
              k = 0;
              last_index = i + 1;
              for (int j = i; j > index; j--) {
                 if (height_of_columns[j] >= height_of_columns[last_index]) {
                     last_index = j;
                 }
              }
            
            difference_between_first_last = height_of_columns[index] - height_of_columns[last_index];
         
            for (int j = index; j < last_index - 1; j++)
            k += height_of_columns[index] - height_of_columns[j + 1] - difference_between_first_last;
            v += k;
          }        
      }
  }
  cout << v;
}
