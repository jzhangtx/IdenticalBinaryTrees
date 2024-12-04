// IdenticalBinTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

bool AreIdenticalTrees(Node* root1, Node* root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;

    if (root1->data != root2->data)
        return false;

    return AreIdenticalTrees(root1->left, root2->left) && AreIdenticalTrees(root1->right, root2->right);
}

Node* MakeTree1()
{
    Node* root = new Node(28);
    root->left = new Node(14);
    root->right = new Node(11);
    //root->left->left = new Node(4);
    root->left->right = new Node(48);
    //root->right->left = new Node(5);
    root->right->right = new Node(10);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);

    return root;
}

Node* MakeTree2()
{
    Node* root = new Node(28);
    root->left = new Node(14);
    root->right = new Node(10);
    //root->left->left = new Node(4);
    root->left->right = new Node(48);
    //root->right->left = new Node(5);
    root->right->right = new Node(10);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);

    return root;
}

Node* GetTreeFromInput(int count, int k)
{
    std::cout << "Values of the tree " << k << " nodes: ";
    int n = 0;
    std::cin >> n;
    Node* root = new Node(n);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (int i = 1; i < count; ++i, l = !l)
    {
        Node* pNode = q.front();
        std::cin >> n;
        if (!l)
            q.pop();
        if (n != -1)
        {
            if (l)
            {
                pNode->left = new Node(n);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(n);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

int main()
{
    while (true)
    {
        std::cout << "Numbers of nodes in the trees: ";
        int count1 = 0, count2 = 0;
        std::cin >> count1 >> count2;
        if (count1 == 0 && count2 == 0)
            break;

        Node* root1 = GetTreeFromInput(count1, 1);
        Node* root2 = GetTreeFromInput(count2, 2);

        std::cout << "The binary trees are " << (AreIdenticalTrees(root1, root2) ? "itentical" : "NOT identical") << std::endl;
        FreeTree(root1);
        FreeTree(root2);
    }
}
