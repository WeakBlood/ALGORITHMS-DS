#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    unsigned freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct comp{
    bool operator()(MinHeapNode *l, MinHeapNode *r){ return (l->freq > r->freq); }
};

void printCode(struct MinHeapNode* root, string str)
{
    if(!root) return;

    if(root->data != '$') cout << root->data << ": " << str << "\n";

    printCode(root->left, str + "0");
    printCode(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*,vector<MinHeapNode*>,comp> q;

    for(int i = 0; i < size; i++) q.push(new MinHeapNode(data[i],freq[i]));

    while(q.size() != 1)
    {
        left = q.top(); q.pop();

        right = q.top(); q.pop();

        top = new MinHeapNode('$',left->freq + right->freq);
        q.push(top);
    }
    printCode(q.top(),"");
}

int main()
{
    //int size = 3;
    // char arr = {a,b,c};
    // int freq = {5,9,4};
    //HuffmanCodes(arr,freq,size);
    return 0;
}