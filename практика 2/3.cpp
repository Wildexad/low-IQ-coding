#include <iostream>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct node {

    int key;
    unsigned char height;
    node* left;
    node* right;
    bool colour;
    explicit node(int k) { key = k; left = right = 0; height = 1; colour = 0; }

};

unsigned char height(node* p) {

    return p ? p->height : 0;

};

int bfactor(node* p) {

    return height(p->right) - height(p->left);

}

void fixheight(node* p) {

    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;

}

node* rotateright(node* p) {

    node* q = p->left;
    p->left = q->right;
    q->right = p;

    fixheight(p);
    fixheight(q);

    return q;

}

node* rotateleft(node* q) {

    node* p = q->right;
    q->right = p->left;
    p->left = q;

    fixheight(q);
    fixheight(p);

    return p;
}

node* balance(node* p) {

    fixheight(p);

    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0) p->right = rotateright(p->right);
        return rotateleft(p);
    }

    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0) p->left = rotateleft(p->left);
        return rotateright(p);
    }

    return p;
}

node* insert(node* p, int k) {

    if (!p) return new node(k);

    if (k < p->key) p->left = insert(p->left, k);

    else p->right = insert(p->right, k);

    return balance(p);

}

node* findmin(node* p) {

    return p->left ? findmin(p->left) : p;

}

node* removemin(node* p) {

    if (p->left == 0) return p->right;

    p->left = removemin(p->left);

    return balance(p);

}

node* remove(node* p, int k) {

    if (!p) return 0;

    if (k < p->key) p->left = remove(p->left, k);

    else if (k > p->key) p->right = remove(p->right, k);

    else {

        node* q = p->left;
        node* r = p->right;

        delete p;

        if (!r) return q;

        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;

        return balance(min);

    }

    return balance(p);

}

struct node* generator(struct node* root, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        root = insert(root, rand() % 100);
    }
    return root;
}

void TreePrint(node* tree, int padding = 0) {//Функция вывода данных узла
    if (tree != NULL) {
        //корень дерева
        std::cout << std::setw(padding) << std::setfill('|') << '-' << tree->key << "" << " [" << tree->colour << "] " << endl;
        padding += 1;
        TreePrint(tree->left, padding); //левое поддерево
        TreePrint(tree->right, padding); //правое поддерево
    }
}

bool painter(node* p) {
    p->left&& p->right ? p->colour = true : p->colour = false;
    p->left ? painter(p->left) : 0;
    p->right ? painter(p->right) : 0;
    return p->colour;
}

void spainter(node* p) {
    painter(p);
    p->colour = false;
}


int main() {

    struct node* p = nullptr;
    p = generator(p, 20);
    spainter(p);
    TreePrint(p, 1);

};