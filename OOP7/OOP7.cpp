#include <iostream>
#include <stack>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));

    stack<int> stack, buffer_stack;
    int choice = 0;
    vector<int> beautifull_not_stack;

    for (int i = 0; i < 10; i++) {
        stack.push(rand() %10);
    }

    cout << "What build do you see?\n";

    while (!stack.empty()) {
        int val = stack.top();
        cout << val << ' ';
        buffer_stack.push(stack.top());
        stack.pop();
    }
    
    while (!buffer_stack.empty()) {
        stack.push(buffer_stack.top());
        beautifull_not_stack.push_back(buffer_stack.top());
        buffer_stack.pop();
    }

    while (choice != -1) {
        cout << "\nDo your choice: ";
        cin >> choice;

        for (int i = 0; i < beautifull_not_stack.size(); i++) {
            if (choice == beautifull_not_stack[i]) {
                buffer_stack.push(i);
            }
        }

        int index = buffer_stack.top()-1;

        while (true) {

            if (choice < beautifull_not_stack[index]) {
                break;
            }
            else if (choice == beautifull_not_stack[index]) {
                cout << beautifull_not_stack[index] << endl;
                break;
            }
            else if (choice > beautifull_not_stack[index]) {
                cout << beautifull_not_stack[index] << ' ';
            }
            if (index == 0) {
                break;
            }
            index--;
        }

        index = buffer_stack.top()+1;

        while (true) {
            
            if (choice < beautifull_not_stack[index]) {
                break;
            }
            else if (choice == beautifull_not_stack[index]) {
                cout << beautifull_not_stack[index] << endl;
                break;
            }
            else if (choice > beautifull_not_stack[index]) {
                cout << beautifull_not_stack[index] << ' ';
            }
            if (index > beautifull_not_stack.size()) {
                break;
            }
            index++;
        }

        //buffer_stack
    }


    return 0;
}
