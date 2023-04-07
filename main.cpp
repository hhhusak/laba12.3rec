#include <iostream>

using namespace std;

typedef int Info;
struct Elem{
    Elem *next,
         *prev;
    Info info;
};

void enqueue(Elem* &first, Elem* &last, Info value)
{
    Elem *tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if(last != NULL){
        last->next = tmp;
    }
    tmp->prev = last;
    last = tmp;
    if(first == NULL){
        first = tmp;
    }
}

void Print(Elem* L){
    if(L != NULL){
        cout << L->info << "; ";
        Print(L = L->next);
    }
}

void Task(Elem* L, Info v1, Info v2) {
    if(L != NULL && L->next != NULL){
        if(L->next->info == v1){
            Elem *tmp = new Elem;
            tmp->info = v2;
            tmp->next = L->next;
            tmp->prev = L;
            tmp->next->prev = tmp;
            L->next = tmp;
            L = L->next;
        }
        Task(L = L->next, v1, v2);
    }
}

int main() {
    srand((unsigned) time(nullptr));

    Elem *first = NULL,
         *last  = NULL;

    for (int i = 0; i < 10; i++) {
        int random = (rand() % 13) - 6;
        enqueue(first, last, random);
    }

    cout << "Spisok: ";
    Print(first);
    cout << endl;
    Info v1, v2;
    cout << "Enter the value which before you want to put the value: "; cin >> v1;
    cout << "Enter the value you want to put: "; cin >> v2;
    Task(first, v1, v2);
    cout << endl;
    cout << "Spisok: ";
    Print(first);

    return 0;
}
