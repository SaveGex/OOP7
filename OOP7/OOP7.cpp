#include <iostream>
#include <stack>
#include <vector>
#include <ctime>

using namespace std;


void clear(stack<int>& stonks) {
    while (!stonks.empty()) {
        stonks.pop();
    }
}

void reverse(stack<int>& stonks) {
    stack<int> buffer_stack1, buffer_stack2;
    while (!stonks.empty()) {
        buffer_stack1.push(stonks.top());
        stonks.pop();
    }
    while (!buffer_stack1.empty()) {
        buffer_stack2.push(buffer_stack1.top());
        buffer_stack1.pop();
    }
    while (!buffer_stack2.empty()) {
        stonks.push(buffer_stack2.top());
        buffer_stack2.pop();
    }
}

int main() {
    srand(time(nullptr));

    stack<int> stonks, buffer_stack;
    int choice = 0;
    vector<int> beautifull_not_stack;

    cout << "green this is indexs \n";
    for (int i = 0; i < 10; i++) {
        stonks.push(rand() %10);
        cout << "\033[32m" << i << "\033[0m" << ' ';
    }

    cout << endl;

    while (!stonks.empty()) {
        int val = stonks.top();
        cout << val << ' ';
        buffer_stack.push(stonks.top());
        beautifull_not_stack.push_back(buffer_stack.top());
        stonks.pop();
    }
    
    while (!buffer_stack.empty()) {


        buffer_stack.pop();
    }

    while (choice != -1) {

        cout << "\nDo your choice of index: ";
        cin >> choice;

        while(choice > 9 || choice < 0) {

            cout << "\n\033[31mDo your choice of index from 0 to 9: \033[0m";
            cin >> choice;
        }

        int build_of_heigth = 0;
        
        for (int i = (choice-1); i >= 0; i--) {


            if (beautifull_not_stack[choice] < beautifull_not_stack[i]) {
                break;
            }
            else if (beautifull_not_stack[choice] == beautifull_not_stack[i]) {

                buffer_stack.push(beautifull_not_stack[i]);
                break;
            }
            else if (beautifull_not_stack[choice] > beautifull_not_stack[i] && beautifull_not_stack[i] > build_of_heigth) {
                buffer_stack.push(beautifull_not_stack[i]);
            }
            (build_of_heigth < beautifull_not_stack[i]) ? build_of_heigth = beautifull_not_stack[i] : build_of_heigth = build_of_heigth;

        }

        clear(stonks);

        build_of_heigth = 0;
        for (int i = (choice + 1); i < beautifull_not_stack.size(); i++) {
            

            if (beautifull_not_stack[choice] < beautifull_not_stack[i]) {
                break;
            }
            else if (beautifull_not_stack[choice] == beautifull_not_stack[i]) {
                stonks.push(beautifull_not_stack[i]);
                break;
            }
            else if (beautifull_not_stack[choice] > beautifull_not_stack[i] && beautifull_not_stack[i] > build_of_heigth) {
                stonks.push(beautifull_not_stack[i]);
            }
            (build_of_heigth < beautifull_not_stack[i]) ? build_of_heigth = beautifull_not_stack[i] : build_of_heigth = build_of_heigth;

        }

        reverse(stonks);

        while (!buffer_stack.empty()) {
            cout << buffer_stack.top() << ' ';
            buffer_stack.pop();
        }
        cout << beautifull_not_stack[choice] << ' ';
        while (!stonks.empty()) {
            cout << stonks.top() << ' ';
            stonks.pop();
        }

    }


    return 0;
}
