#define _CRT_SECURE_NO_WARNINGS
#include "std_lib_facilities.h"

using namespace std;

bool compare(string a, string b) {
    return a.size() < b.size();
}

void ManageList(vector<string>& vstr) {
    int option;
    while (true) {
        cout << "[ MANAGE LIST ]" << '\n';
        cout << "1. Print Words" << '\n';
        cout << "2. Add Word" << '\n';
        cout << "3. Return" << '\n' << '\n';
        cout << "Choose an option (1-3): ";
        cin >> option;
        cout << '\n';

        while (option < 1 || option>3) {
            cout << "Choose an option (1-3): ";
            cin >> option;
        }
        if (option == 1) {
            sort(vstr.begin(), vstr.end());
            cout << "A total of " << vstr.size() << " words are available: " << '\n';
            for (auto elem : vstr) {
                cout << elem << '\n';
            }
            cout << '\n';
            //ManageList(vstr);
        }
        else if (option == 2) {
            string word;
            cout << "Input a new word: "; cin >> word;
            cout << '\n';
            vstr.push_back(word);
            cout << "The word '" << word << "' has been successfully inserted in the list." << '\n';
            sort(vstr.begin(), vstr.end()); cout << '\n';
            //ManageList(vstr);
        }
        else if (option == 3) break;
    }
}

void SolvePuzzle(vector<string>& vstr) {
    int option, cnt_idx1 = 0, cnt_idx2 = 0;
    while (true) {
        cout << "[ SOLVE PUZZLE ]" << '\n';
        cout << "1. Easy Mode" << '\n';
        cout << "2. Hard Mode" << '\n';
        cout << "3. Return" << '\n' << '\n';
        cout << "Choose an option (1-3): ";
        cin >> option;
        cout << '\n';

        while (option < 1 || option>3) {
            cout << "Choose an option (1-3): ";
            cin >> option;
        }
        sort(vstr.begin(), vstr.end(), compare);

        for (int i = 0; i < vstr.size(); i++) {
            if (vstr[i].size() == 5) {
                cnt_idx1 = i;
                break;
            }
        }
        for(int i = 0; i < vstr.size();i++){
            if (vstr[i].size() == 6) {
                cnt_idx2 = i - 1;
                break;
            }
        }

        if (option == 1) {
            int idx = randint(cnt_idx2);
            int num1 = 0, num2 = 0;
            string str, temp;
            str = vstr[idx];
            temp = str;

            while (num1 == num2) {
                num1 = randint(temp.length());
                num2 = randint(temp.length());
            }

            swap(temp[num1], temp[num2]);

            cout << "I give you a jumbled word '" << temp << "'." << '\n';

            for (int i = 1; i <= 3; i++) {
                string test;
                cout << "[" << i << "/3] Guess the original word: "; cin >> test;
                if (test == str) {
                    cout << "Congratualation! You got the answer right!" << '\n';
                    break;
                }
                else if (i == 3 && test != str)
                    cout << "Oops! You failed to solve the puzzle...\nThe correct answer is '" << str << "'." << '\n';
                else {
                    cout << ">> [";
                    for (int j = 0; j < str.size(); j++) {
                        if (test[j] != str[j])
                            cout << "-";
                        else
                            cout << test[j];
                    }
                    cout << "]" << '\n';
                }
            }
            cout << '\n';
        }

        else if (option == 2) {
            int idx = randint(cnt_idx1, vstr.size() - 1);
            int num3 = 0, num4 = 0;
            int num1 = 0, num2 = 0;
            string str, temp;
            str = vstr[idx];
            temp = str;

            
            while (num3 == num4) {
                num3 = randint(temp.length());
                num4 = randint(temp.length());
            }
            swap(temp[num3], temp[num4]);

            while (num1 == num2) {
                num1 = randint(temp.length());
                num2 = randint(temp.length());
            }
            swap(temp[num1], temp[num2]);
            
            

            cout << "I give you a jumbled word '" << temp << "'." << '\n';

            for (int i = 1; i <= 5; i++) {
                string test;
                cout << "[" << i << "/5] Guess the original word: "; cin >> test;
                if (test == str) {
                    cout << "Congratualation! You got the answer right!" << '\n';
                    break;
                }
                else if(i==5 && test!=str)
                    cout << "Oops! You failed to solve the puzzle...\nThe correct answer is '" << str << "'." << '\n';
                else {
                    cout << "[";
                    for (int j = 0; j < str.size(); j++) {
                        if (test[j] != str[j])
                            cout << "-";
                        else
                            cout << test[j];
                    }
                    cout << "]" << '\n';
                }
            }
            cout << '\n';
        }
        else if (option == 3) break;
    }

}

int main(void) {
    vector<string> word_list = { "drift", "professional","midnight","scatter","relevance","visit","disaster","commerce","coincide","progress","shift","spell","veil","desk","gown","umbrella","gregarious","craftman","wriggle","score","deliver","vote","dirty","chain","road","charter","feign","duck","highway","add","van","mutual","bang","table","venture","deficiency","depend","dimension","holiday","scrap","unlike","coast","command","base","recommand","spit","corner","huge","economic","sigh" };
    int option;
    while (true) {
        cout << "<<< WORD JUMBLE >>>" << '\n';
        cout << "1. Manage List" << '\n';
        cout << "2. Solve Puzzle" << '\n';
        cout << "3. Exit" << '\n' << '\n';
        cout << "Choose an option (1-3): ";
        cin >> option;
        cout << '\n';

        while (option < 1 || option>3) {
            cout << "Choose an option (1-3): ";
            cin >> option;
        }

        if (option == 1) ManageList(word_list);
        else if (option == 2) SolvePuzzle(word_list);
        else if (option == 3) {
            cout << "Good bye!!!" << '\n';
            break;
        }
    }
    return 0;
}