#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <algorithm>

using namespace std;


string BigIntAdd(string num1, string num2) { try { long long res = stoll(num1) + stoll(num2); return to_string(res); } catch (...) { return "[Error: Add failed]"; } }
string BigIntSubtract(string num1, string num2) { try { long long res = stoll(num1) - stoll(num2); return to_string(res); } catch (...) { return "[Error: Subtract failed]"; } }
string BigIntMultiply(string num1, string num2) { try { long long res = stoll(num1) * stoll(num2); return to_string(res); } catch (...) { return "[Error: Multiply failed]"; } }
string BigIntDivide(string num1, string num2) { if (num2 == "0" || num2 == "-0") return "[Error: Division by zero]"; try { long long res = stoll(num1) / stoll(num2); return to_string(res); } catch (...) { return "[Error: Divide failed]"; } }
int BigIntCompare(string num1, string num2) { if (num1.length() > num2.length()) return 1; if (num1.length() < num2.length()) return -1; return num1.compare(num2); }



typedef struct tagNode
{
    string num_str;
    struct tagNode *pNext;
} Node;

typedef struct tagList
{
    Node *pHead;
    Node *pTail;
} LIST;


void CreateList(LIST &l) { l.pHead = l.pTail = NULL; }
Node* CreateNode(string x) { Node *p = new Node; if(!p) exit(1); p->num_str = x; p->pNext = NULL; return p; }
int IsEmpty(LIST &s) { return (s.pHead == NULL); }
void Push(LIST &s, Node *newNode) { if(!newNode) return; newNode->pNext = s.pHead; s.pHead = newNode; if(!s.pTail) s.pTail = newNode;}
void Pop(LIST &s) { if(IsEmpty(s)) return; Node* p = s.pHead; s.pHead = p->pNext; if(!s.pHead) s.pTail = NULL; delete p;}
string Top(LIST &s) { if(IsEmpty(s)) { cerr << "Error: Top() on empty operand stack." << endl; exit(1); } return s.pHead->num_str; }



int pri(char a) { if(a=='+'||a=='-') return 1; if(a=='*'||a=='/') return 2; if(a=='^') return 3; return 0; }


string convert(string infix)
{
    int i = 0;
    string postfix = "";
    stack<char> s_operator;

    while (infix[i] != '\0')
    {
        if (isdigit(infix[i]))
        {
            string curNum;
            while (i < infix.length() && isdigit(infix[i]))
            {
                curNum += infix[i++];
            }
            postfix += curNum;
            postfix += ' ';
            continue;
        }
        else if (isspace(infix[i]))
        {
            i++;
            continue;
        }
        else if (infix[i] == '(')
        {
            s_operator.push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!s_operator.empty() && s_operator.top() != '(')
            {
                postfix += s_operator.top();
                postfix += ' ';
                s_operator.pop();
            }
            if (s_operator.empty()) { return "[Error: Mismatched )]"; }
            s_operator.pop();
            i++;
        }
        else if (pri(infix[i]) > 0)
        {
            while (!s_operator.empty() && s_operator.top() != '(' && pri(infix[i]) <= pri(s_operator.top()))
            {
                postfix += s_operator.top();
                postfix += ' ';
                s_operator.pop();
            }
            s_operator.push(infix[i]);
            i++;
        }
        else
        {
            cerr << "Warning: Invalid character '" << infix[i] << "' skipped." << endl;
            i++;
        }
    }

    while (!s_operator.empty())
    {
        if (s_operator.top() == '(') { return "[Error: Mismatched (]"; }
        postfix += s_operator.top();
        postfix += ' ';
        s_operator.pop();
    }

    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();
    }
    return postfix;
}



string calculate(string postfix)
{
    LIST s_operand;
    CreateList(s_operand);
    int len = postfix.length();
    string curItem;

    for (int i = 0; i < len; i++)
    {
        if (isspace(postfix[i])) continue;

        curItem = "";
        while (i < len && !isspace(postfix[i])) {
            curItem += postfix[i];
            i++;
        }
        i--;

        if (isdigit(curItem[0]) || (curItem[0] == '-' && curItem.length() > 1 && isdigit(curItem[1])))
        {
            try {
                stoll(curItem);
                Push(s_operand, CreateNode(curItem));
            } catch (const std::exception& e) {
                cerr << "Error: Invalid number format '" << curItem << "'" << endl;
                return "[Error: Invalid Number Format]";
            }
        }
        else if (curItem.length() == 1 && pri(curItem[0]) > 0)
        {
            if (IsEmpty(s_operand)) { return "[Error: Invalid Postfix (Operand missing for " + curItem + ")]"; }
            string operand2_str = Top(s_operand); Pop(s_operand);

            if (IsEmpty(s_operand)) { return "[Error: Invalid Postfix (Operand missing for " + curItem + ")]"; }
            string operand1_str = Top(s_operand); Pop(s_operand);

            string result_str = "";
            switch (curItem[0])
            {
                case '+': result_str = BigIntAdd(operand1_str, operand2_str); break;
                case '-': result_str = BigIntSubtract(operand1_str, operand2_str); break;
                case '*': result_str = BigIntMultiply(operand1_str, operand2_str); break;
                case '/': result_str = BigIntDivide(operand1_str, operand2_str); break;
                default: return "[Error: Unknown Operator '" + curItem + "']";
            }

            if (result_str.find("[Error:") != string::npos || result_str == "Error") {
                 cerr << "Error during calculation: " << result_str << endl;
                 return result_str;
            }

            Push(s_operand, CreateNode(result_str));
        }
        else {
            return "[Error: Invalid item in Postfix '" + curItem + "']";
        }
    }

    if (IsEmpty(s_operand)) return "[Error: Invalid Postfix (No result)]";
    string finalResult = Top(s_operand);
    Pop(s_operand);
    if (!IsEmpty(s_operand)) return "[Error: Invalid Postfix (Extra items left)]";

    return finalResult;
}


string memoryValue = "0";
string lastResult = "0";
void MemoryClear() { memoryValue = "0"; cout << "Memory Cleared." << endl; }
void MemoryAdd() { memoryValue = BigIntAdd(memoryValue, lastResult); cout << "Added to Memory. Memory = " << memoryValue << endl; }
void MemorySubtract() { memoryValue = BigIntSubtract(memoryValue, lastResult); cout << "Subtracted from Memory. Memory = " << memoryValue << endl; }
string MemoryRecall() { cout << "Memory Recalled: " << memoryValue << endl; return memoryValue; }



int main() {
    string input_line;
    cout << "Simple BigInt Calculator with Memory" << endl;
    cout << "Enter expression (e.g., 123 + 456), or M+, M-, MC, MR, quit:" << endl;

    while (true) {
        cout << "> ";
        if (!getline(cin, input_line)) break;

        input_line.erase(0, input_line.find_first_not_of(" \t\n\r\f\v"));
        input_line.erase(input_line.find_last_not_of(" \t\n\r\f\v") + 1);

        if (input_line == "quit") {
            break;
        } else if (input_line == "MC") {
            MemoryClear();
        } else if (input_line == "M+") {
            MemoryAdd();
        } else if (input_line == "M-") {
            MemorySubtract();
        } else if (input_line == "MR") {
            MemoryRecall();
        } else if (input_line.empty()) {
             continue;
        }
        else {

            size_t pos = input_line.find("MR");
            while (pos != string::npos) {
                input_line.replace(pos, 2, memoryValue);
                pos = input_line.find("MR", pos);
            }

            cout << "  Processing: " << input_line << endl;
            string postfix = convert(input_line);
            cout << "  Postfix: " << postfix << endl;

            if (postfix.find("[Error:") == string::npos) {
                string result = calculate(postfix);
                cout << "  Result: " << result << endl;
                if (result.find("[Error:") == string::npos && result != "Error") {
                    lastResult = result;
                } else {
                    cout << "  Calculation failed." << endl;
                }
            } else {
                cout << "  Conversion failed." << endl;
            }
        }
    }

    cout << "Exiting calculator." << endl;
    return 0;
}
