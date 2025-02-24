#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node() {
            data = 0;
            next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
        Node * head;
    public:
        LinkedList() {
            head = NULL;
        }

        void insertAtHead(int data) {

        Node *newNode = new Node(data);

        if(head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head = newNode;

        }

        void print() {
            Node *temp = head;

            if(head == NULL) {
                cout << "List empty" << endl;
                return;
            }

            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp -> next;
            }
        }
};

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    LinkedList A;
    A.insertAtHead(1);
    A.insertAtHead(2);
    A.insertAtHead(3);
    A.insertAtHead(4);
    A.insertAtHead(5);
    A.insertAtHead(6);
    A.insertAtHead(100000);

	A.print();
	cout << endl;

	return 0;
}
