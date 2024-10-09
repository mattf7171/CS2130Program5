#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
// CS 2130
// Program5

bool AND(bool p, bool q) {
    return p && q;
}

bool OR(bool p, bool q) {
    return p || q;
}

bool neg(bool value, char choice) {
    return (choice == '1') ? !value : value;
}

void printPoly(char con, char NP, char NQ) {
    if (NP == '2' && NQ == '2' && con == '1') {
        cout << "p | q | p A q\n";
    }
    else if (NP == '2' && NQ == '2' && con == '2'){
        cout << "p | q | p V q\n";
    }
    else if (NP == '1' && NQ == '2' && con == '1'){
        cout << "p | q | ~p A q\n";
    }
    else if(NP == '1' && NQ == '1' && con == '1'){
        cout << "p | q | ~p A ~q\n";
    }
    else if(NP == '1' && NQ == '2' && con == '2'){
        cout << "p | q | ~p V q\n";
    }
    else if(NP == '1' && NQ == '1' && con == '2'){
        cout << "p | q | ~p V ~q\n";
    }
    else if(NP == '2' && NQ == '1' && con == '1'){
        cout << "p | q | p A ~q\n";
    }
    else if(NP == '2' && NQ == '1' && con == '2'){
        cout << "p | q | p V ~q\n";
    }
}

int main() {
    char condition, notP, notQ;

    cout << "Do you want to use And(1) or Or(2)? \n";
    cin >> condition;
    cout << "Do you want to NOT p? Yes(1) or No(2) \n";
    cin >> notP;
    cout << "Do you want to NOT q? Yes(1) or No(2) \n";
    cin >> notQ;

    printPoly(condition, notP, notQ);
    cout << "---------------\n";

    for (int i = 0; i < 4; ++i) {
        bool p = i < 2;
        bool q = (i % 2 == 0);

        bool modifiedP = neg(p, notP);
        bool modifiedQ = neg(q, notQ);

        bool result;
        if (condition == '1') {
            result = AND(modifiedP, modifiedQ);
        }
        else {
            result = OR(modifiedP, modifiedQ);
        }

        cout << (p ? "1" : "0") << " | " << (q ? "1" : "0") << " | " << (result ? "1" : "0") << "\n";
    }


    return 0;
}
