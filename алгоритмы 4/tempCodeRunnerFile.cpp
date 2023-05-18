#include <iostream>
#include <vector>


int hash_function(int key, int size) {
    return key % size;
}

void insert(std::vector<int>& table, int key) {
    int index = hash_function(key, table.size());
    if (table[index] == 0) { 
        table[index] = key;
    }
    else { // коллизия
        int i = index;
        do {
            i = (i + 1) % table.size();
        } while (table[i] != 0);
        table[i] = key;
    }
}

int main() {
    std::vector<int> table(7, 0); 
    std::vector<int> input = { 86, 90, 27, 29, 38, 30, 40 };
    int size = input.size();
    for (int i = 0; i < size; i++) {
        insert(table, input[i]);
    }

    for (int i = 0; i < table.size(); i++) {
        std::cout << "table[" << i << "] = " << table[i] <<std::endl;
    }
    return 0;
}