#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void reverse(int*);
void sort_rev(int*);
void sort(int*);
void (*check(int*))(int*);

int main()
{
    int* a = new int[10];
    cout << "Source array: [";          
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int temp = 1 + rand() % 15;
        a[i] = temp;
        if (i == 9) {
            cout << temp;
        }
        else {
            cout << temp << ",";
        }
    }
    cout << "]" << endl;

    void(*call)(int*);
    call = check(a);
    call(a);
    cout << "Finish array: [";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9) {
            cout << a[i];
        }
        else {
            cout << a[i] << ",";
        }
    }
    cout << ']';
    return 0;
}


void (*check(int* list))(int*)
{
    void (*pattern)(int*);
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        temp += list[i];
    }
    if (temp == list[0]) {
        pattern = reverse;
    }
    else if (temp > list[0]) {
        pattern = sort_rev;
    }
    else {
        pattern = sort;
    }
    return pattern;
}

void reverse(int* list) {
    int temp[10];
    for (int i = 0; i < 10; i++) { temp[i] = list[i]; }
    for (int i = 0; i < 10; i++) { list[i] = temp[4 - i]; }
}

void sort(int* list) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (list[j] < list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void sort_rev(int* list) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}