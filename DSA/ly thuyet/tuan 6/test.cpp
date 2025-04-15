#include <iostream> // Added for cout in PrintList and potential use in main
#include <string>   // Added for string type
#include <cstdlib>  // Added for exit()

using namespace std; // Added for convenience

typedef struct tagNode
{
    string text;
    struct tagNode *pNext;
} Node;

typedef struct tagList
{
    Node *pHead;
    Node *pTail;
} LIST;

// Initializes an empty list (stack)
void CreateList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

// Creates a new node with the given string data
Node* CreateNode(string x)
{
    Node *p;
    p = new Node; // Allocate memory for a new Node
    if(p == NULL) // Check if memory allocation failed
    {
        cerr << "Memory allocation failed!" << endl; // Use cerr for errors
        exit(1); // Exit if allocation fails
    }
    p->text = x;      // Set the node's data
    p->pNext = NULL; // Initialize the next pointer to NULL
    return p;         // Return the pointer to the new node
}

// Checks if the list (stack) is empty
// Returns 1 (true) if empty, 0 (false) otherwise
int IsEmpty(LIST &s)
{
    // The stack is empty if the head pointer is NULL
    if(s.pHead == NULL) {
        return 1;
    }
    else
        return 0;
}

// Pushes a new node onto the top of the stack (adds to the beginning of the list)
void Push(LIST &s, Node *Tam)
{
    if(Tam == NULL) return; // Don't push a NULL node

    if(s.pHead == NULL) // If the stack is currently empty
    {
        s.pHead = Tam; // The new node is both the head and the tail
        s.pTail = Tam;
    }
    else // If the stack is not empty
    {
        Tam->pNext = s.pHead; // Point the new node's next to the current head
        s.pHead = Tam;        // Update the stack's head to be the new node
    }
}

// **--- Top Function ---**
// Gets the value at the top of the stack without removing the node.
// Returns 1 if successful (stack not empty) and copies the value to 'topValue'.
// Returns 0 if the stack is empty.
int Top(LIST &s, string &topValue) // Pass string by reference to return the value
{
    // Check if the stack is empty
    if (IsEmpty(s) == 1) // or equivalently: if (s.pHead == NULL)
    {
        // Cannot get the top element from an empty stack
        return 0; // Indicate failure (stack is empty)
    }
    else
    {
        // Stack is not empty, the top element is the one pointed to by pHead
        topValue = s.pHead->text; // Copy the text from the head node
        return 1; // Indicate success
    }
}
// **--- End of Top Function ---**


// Pops (removes) the top element from the stack.
// Returns 1 if successful and copies the value to 'value'.
// Returns 0 if the stack is empty.
// NOTE: Your original Pop had issues:
//      1. 'trave' was passed by value, so the caller wouldn't get the popped value.
//      2. The 'delete p;' was after 'return 1;', making it unreachable (memory leak).
//      Here is a corrected version:
int Pop(LIST &s, string &value) // Pass string by reference to return the value
{
    Node *p;
    // Check if the stack is empty BEFORE trying to access pHead
    if (IsEmpty(s) == 1) // or if (s.pHead == NULL)
    {
        return 0; // Indicate failure (stack is empty)
    }

    // Stack is not empty
    p = s.pHead;             // Point p to the node to be removed
    value = p->text;         // Get the value from the node
    s.pHead = s.pHead->pNext; // Move the head pointer to the next node

    // If the list becomes empty after popping
    if (s.pHead == NULL)
    {
        s.pTail = NULL; // Also update the tail pointer
    }

    delete p; // Now delete the old head node (memory management)
    return 1; // Indicate success
}


// Prints the contents of the list (stack) from top to bottom
void PrintList(LIST l)
{
    Node *p;
    p = l.pHead; // Start from the head (top of the stack)
    cout << "Stack (Top to Bottom): ";
    while(p != NULL) {
        cout << p->text << " "; // Print the text of the current node
        p = p->pNext;         // Move to the next node
    }
    cout << endl;
}

// Example Usage (Optional)
int main() {
    LIST myStack;
    CreateList(myStack);

    Node* n1 = CreateNode("World");
    Push(myStack, n1);
    Node* n2 = CreateNode("Hello");
    Push(myStack, n2);

    PrintList(myStack); // Output: Stack (Top to Bottom): Hello World

    string top_element;
    if (Top(myStack, top_element) == 1) {
        cout << "Top element is: " << top_element << endl; // Output: Top element is: Hello
    } else {
        cout << "Stack is empty, cannot get top element." << endl;
    }

    PrintList(myStack); // Output: Stack (Top to Bottom): Hello World (Stack unchanged by Top)

    string popped_element;
    if (Pop(myStack, popped_element) == 1) {
        cout << "Popped element: " << popped_element << endl; // Output: Popped element: Hello
    } else {
         cout << "Stack is empty, cannot pop." << endl;
    }

    PrintList(myStack); // Output: Stack (Top to Bottom): World

    return 0;
}
