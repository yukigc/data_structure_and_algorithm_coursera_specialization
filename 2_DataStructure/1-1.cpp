#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
    
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            if (position+1 < text.length()){
                Bracket b = Bracket(next, position);
                opening_brackets_stack.push(b);
            }
            else{
                std::cout << position+1 << std::endl;
                return 0;
            }
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            Bracket b = Bracket(next, position);
            //std::cout << "stack " << opening_brackets_stack.top().type << std::endl;
            if (opening_brackets_stack.empty()){
                std::cout << position+1 << std::endl;
                return 0;
            }

            Bracket before = opening_brackets_stack.top();
            if (before.Matchc(next)){
                opening_brackets_stack.pop();
            }
            else{
                std::cout << position+1 << std::endl;
                return 0;
            }
        }
        
    }

    if (opening_brackets_stack.empty()){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << opening_brackets_stack.top().position+1 << std::endl;
    }
    return 0;
}
