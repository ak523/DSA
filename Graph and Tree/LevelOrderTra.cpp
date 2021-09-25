#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void levelOrder(Node *root)
{
    if(root == NULL) return;

    queue<Node *> q;

    q.push(root);
    Node *curr;
    while(!q.empty())
    {
        curr = q.front();
        cout<<curr->data<<" ";
        q.pop();

        if(curr->left)
        {
            q.push(curr->left);
        }
        if(curr->right)
        {
            q.push(curr->right);
        }
    }
}

Node* newNode(int val)
{
    Node *Temp = new Node;
    Temp->data = val;
    Temp->left = Temp->right = NULL;
    return Temp;
}


int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);

    //Output: 1,2,3,4,5
    return 0;
}