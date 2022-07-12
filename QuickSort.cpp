#include <stdio.h>
#include <vector>
 
//main sort function
std::vector<int> quick_sort(std::vector <int> &vector__);
 
//connection of greater, lower and middle arrays
std::vector<int> connect(std::vector <int> start__, std::vector <int> end__, int number__); 
 
void print(std::vector <int> vector__);
 
int main(){ 
    std::vector <int> array {9, 8, 17, 22, 1};
    std::vector <int> sorted_array;
    sorted_array = quick_sort(array);
    print(sorted_array);
}
 
std::vector<int> quick_sort(std::vector <int> &vector__){
    int length = vector__.size(); 
    int id_of_element = length/2;
    int number__ = vector__[id_of_element];
 
    std::vector <int> less__;
    std::vector <int> greater__;
 
    if (length < 2){
        return vector__;
    }else{
        for (int i = 0; i<=length-1; i++){
            if (vector__[i] <= vector__[id_of_element] && i != id_of_element){
                less__.push_back(vector__[i]);
            }else if(vector__[i] > vector__[id_of_element]){
                greater__.push_back(vector__[i]);
            }
        }
        return connect(quick_sort(less__), quick_sort(greater__), number__);
    }
}
 
std::vector<int> connect(std::vector <int> start__, std::vector <int> end__, int number__){
    std::vector <int> middle__ {number__};
    std::vector <int> output__;
 
    output__.insert(output__.begin(), start__.begin(), start__.end());
    output__.insert(output__.end(), middle__.begin(), middle__.end());
    output__.insert(output__.end(), end__.begin(), end__.end());   
    return output__; 
}
 
void print(std::vector <int> vector__){
    for (int i=0; i<=vector__.size()-1; i++){
        printf("%d ", vector__[i]);
    }
}