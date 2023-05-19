#include <iostream>
#include <locale>

struct Node
{
public:
	int key;
	Node* left;
	Node* right;
	Node* parent;
    int count;
	int balans;
};

/*// Добавление нового узла в дерево с рассчётом баланса
Node* addNode(int key, Node* root)
{
    if (!root)
    {
        root = new Node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        root->count = 1;
        root->balans = 0;
    }
    else if (key == root->key) {
        root->count++;
    }
    else if (key < root->key)
    {
        root->left = addNode(key, root->left);
        root->left->parent = root;
    }
    else if (key > root->key)
    {
        root->right = addNode(key, root->right);
        root->right->parent = root;
    }

    if (root->left)
        root->balans -= root->left->count;
    if (root->right)
        root->balans += root->right->count;

    return root;
}*/

int height(Node* node) {
    if (node == nullptr) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

Node* addNode(int key, Node* root)
{
    if (!root)
    {
        root = new Node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        root->count = 1;
        root->balans = 0;
    }
    else if (key == root->key)
    {
        root->count++;
    }
    else if (key < root->key)
    {
        root->left = addNode(key, root->left);
        root->left->parent = root;
    }
    else if (key > root->key)
    {
        root->right = addNode(key, root->right);
        root->right->parent = root;
    }

    root->balans = height(root->right) - height(root->left);

    return root;
}

//void update_balance(Node* node) {
//    if (node == nullptr) return;
//    node->balans = height(node->right) - height(node->left);
//    update_balance(node->parent);
//}
//
//void update_balances(Node* node) {
//    if (node == nullptr) return;
//    update_balances(node->left);
//    update_balances(node->right);
//    update_balance(node);
//}

void printTree(Node* root)
{
    if (root != nullptr)
    {
        printTree(root->left);
        std::cout << root->key << " (count = " << root->count << ")" << ", Balans: " << root->balans << std::endl;
        printTree(root->right);
    }
}


// Обход и печать данных дерева (Обратный)
void print(Node* root, int level = 0)
{
    if (root != nullptr) {
        print(root->left, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "     ";
        }
        std::cout << root->key << " (balans = " << root->balans << ")" << std::endl;
        print(root->right, level + 1);
    }
}



// Генератор случайных чисел
int random(int min = -100, int max = 100)
{
    return min + rand() % (max - min + 1);
}


int main1()
{
    setlocale(LC_ALL, "");
    srand(time(nullptr));

    int n = random(5, 15);
    std::cout << "n = " << n << std::endl;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value = random(1, 15);
        root = addNode(value, root);
    }

    std::cout << std::endl;
    printTree(root);
    std::cout << std::endl;
    print(root);
    std::cout << std::endl;

    return 0;
}



int main() {
    /*
    ctrl+k+u
    ctrl+k+c
    */
    setlocale(LC_ALL, "");
    srand(time(nullptr));

    int n = 5;
    std::cout << "n = " << n << std::endl;

    Node* root = nullptr;

    root = addNode(2, root);
    root = addNode(1, root);
    root = addNode(4, root);
    root = addNode(3, root);
    root = addNode(6, root);
    root = addNode(15, root);
    root = addNode(7, root);
    root = addNode(11, root);
    root = addNode(5, root);

    std::cout << std::endl;
    printTree(root);
    std::cout << std::endl;
    print(root);
    std::cout << std::endl;
    main1();
}