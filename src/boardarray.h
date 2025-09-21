#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            int pos = 0;

            while(pos < index && !entry->compare(&array[pos])){
                pos++;
            }

            if(index == SIZE && pos == SIZE){
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }

            if(index < SIZE){
                index++;
            }

            for(int i = index - 1; i > pos; i--){
                array[i] = array[i - 1];
            }
            array[pos] = *entry;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};