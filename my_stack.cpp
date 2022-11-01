#include <iostream>
#include <vector>
#include <string>
using namespace std;

//The Stack class is implemented using the vector class
template <class T>
class Stack {
    public:
        //reuires: stack
        //effects: returns true if stack is empty 
        //         false otherwise
        bool empty() const { return mystack.size() == 0; }

        //reuires: stack and a generic item
        //effects: pushes the item to the stack
        void push(const T &item) { mystack.push_back(item); }

        //reuires: stack
        //effects: returns a reference to the most-recently-added item if exists   
        //         throws exception "STACK IS EMPTY" otherwise
        T &top() { 
            if (!mystack.empty()) return mystack.back(); 
            else printf("STACK IS EMPTY\n");
        }

        //reuires: stack
        //effects: removes the most-recently-added item from the stack if exists
        //         throws exception "STACK IS EMPTY" otherwise
        void pop() { 
            if (!mystack.empty()) mystack.pop_back();
            else printf("STACK IS EMPTY\n");
        }
        
    private:
        vector<T> mystack;

    //requires: write a + b { a and b are stacks }
    //effects: returns a new stack containing a’s items followed by b’s items in their original order.
    //         if the first stack is empty, new stack = second stack
    //         else if the second stack is empty, new stack = first stack
    //         else throws exception "both stacks are empty" otherwise
    friend Stack<T> operator+(const Stack<T> &a, const Stack<T> &b) {
        Stack<T> c;
        if (!a.empty()) for (int i = 0; i < a.mystack.size(); i++) c.push(a.mystack[i]); // if b is empty, c = a

        if (!b.empty()) for (int i = 0; i < b.mystack.size(); i++) c.push(b.mystack[i]);// if a is empty, c = b

        if (!c.empty()) return c; 
        printf("STACK IS EMPTY\n");
    }
};






int main(){
    //test for stack of integers
    Stack<int> stack_of_int;

    //stack is empty
    stack_of_int.empty();//true
    stack_of_int.pop();//nothing happens
    stack_of_int.top();//nothing happens

    //stack is not empty
    stack_of_int.push(10);
    stack_of_int.push(20);
    stack_of_int.push(30);
    stack_of_int.push(30);
    stack_of_int.push(30);

    //while uses 3 out of 4 functions 
    while(!stack_of_int.empty()) {
        cout << stack_of_int.top() << endl;
        stack_of_int.pop();
    }

    //test for stack of strings
    Stack<string> stack_of_string;

    //stack is empty
    stack_of_string.empty();//true
    stack_of_string.pop();//throw exception
    stack_of_string.top();//throw exception

    //stack is not empty
    stack_of_string.push("Abbas");
    stack_of_string.push("Rida");
    stack_of_string.push("Jameel");
    stack_of_string.push("Faisal");

    while(!stack_of_string.empty()) {
        cout << stack_of_string.top() << endl;
        stack_of_string.pop();
    }

    //test for stack of characters
    Stack<char> stack_of_char;

    //stack is empty
    stack_of_char.empty();//true
    stack_of_char.pop();//throw exception
    stack_of_char.top();//throw exception

    //stack is not empty
    stack_of_char.push('a');
    stack_of_char.push('b');
    stack_of_char.push('c');
    stack_of_char.push('c');
    while(!stack_of_char.empty()) {
        cout << stack_of_char.top() << endl;
        stack_of_char.pop();
    }

        //friend function test
        Stack <int > a;

        Stack <int > b;

        Stack<int> c = a + b;

        //stack is empty
        c.empty();//true
        c.pop();//throw exception
        c.top();//throw exception

        a.push(1);
        a.push(2);

        b.push(3);
        b.push(4);
        b.push(4);
        
        //both a and b are nonempty stacks
        c = a + b;
        while(!c.empty()){
            cout << c.top() << endl;
            c.pop();
        }

        // b is empty
        stack_of_string.push("Abbas");
        stack_of_string.push("Rida");
        stack_of_string.push("Jameel");
        stack_of_string.push("Faisal");
        Stack<string> stack_of_string2;
        Stack<string> d = stack_of_string + stack_of_string2;
        while(!d.empty()){
            cout << d.top() << endl;
            d.pop();
        }
        
        // a is empty
        Stack<char> stack_of_char2;
        stack_of_char.push('a');
        stack_of_char.push('b');
        stack_of_char.push('c');
        stack_of_char.push('c');

        Stack<char> e = stack_of_char2 + stack_of_char;
        while(!e.empty()){
            cout << e.top() << endl;
            e.pop();
        }
    return 0;

    
}
