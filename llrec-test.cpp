#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);


/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);
bool compare(int n)
{
    if(n%2!=0) return true;
    else return false;
}

Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }
    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    Node* smaller = NULL;
    Node* larger = NULL;
    // Test out your linked list code
    int pivot = 10;
    llpivot(head,smaller, larger, pivot);
    cout<<"Pivot "<<pivot<<" List:"<<endl;
    cout<<"Smaller List"<<endl;
    print(smaller);
    cout<<"Larger List"<<endl;
    print(larger);
    dealloc(smaller);
    dealloc(larger);
    head = readList(argv[1]);
    cout<<endl;
    cout<<"List ";
    print(head);
    cout<<head->val<<" "<<head->next->val<<endl;
    head = llfilter(head, compare);
    cout<<"Filtered List:"<<endl;
    cout<<head->val<<" "<<head->next->val<<endl;
    print(head);
    dealloc(head);
    return 0;
}
