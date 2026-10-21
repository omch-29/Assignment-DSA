#include <iostream>
#include <unordered_map>
using namespace std;

class LRU{
    struct Node{
        int key,val;
        Node* prev;
        Node* next;

        Node(int k,int v) : key(k),val(v), prev(NULL), next(NULL) {}
    };
Node* head;
Node* tail;
unordered_map<int,Node*>mp;
int capacity;

    void delNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node* node){
        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;
    }

public:
    LRU(int cap){
        this->capacity=cap; //initializing capacity

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    int get(int key){
        if(mp.find(key) == mp.end()){   // Key doesn't exist
            return -1;
        }
        Node* node=mp[key];

        delNode(node);
        addNode(node);

        return node->val;
    }
    void put(int key, int val){
        if (mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val=val;

            delNode(node);
            addNode(node);

            return;
        }
        if (mp.size() == capacity){
            Node* node=tail->prev;

            delNode(node);
            mp.erase(node->key);

            delete node;
        }
        Node* node = new Node(key,val);

        addNode(node);
        mp[key]=node;
    }
};