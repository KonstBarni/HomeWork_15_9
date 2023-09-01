#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"
#include "Trie.h"

using namespace std;
const string& choiceWord(vector<string> words)        //выбор слова из вектора
{
    int messIndex = 0;
    
    cin >> messIndex;
    if(cin.bad())
    {
        cin.clear();
        cout << "Its not a number!" << endl;
    }

    if(messIndex < 0 || messIndex > words.size())
    {
        cout << "Incorrect number of word!" << endl;
        cin.clear();
    }
    return words[messIndex];
}

bool inputMess(TrieNode* dict)
{
    string message;     //  конечное сообщение
    string inpWord;     // вводимое слово
    bool inpMessWork = true;    

    cout << "Use only 'a -z' lower case symbols (input '/' to quit, ore '*' to show available words)" << endl;
    cout << "to send a message use '!' '.' '?' symbols" <<endl;

    while(inpMessWork)      //пока вводится сообщение
    {
        cin >> inpWord;
        if (inpWord.find('.') != string::npos || 
        inpWord.find('!') != string::npos || 
        inpWord.find('?') != string::npos)     //условие завершения ввода сообщения
        {
            if(inpWord.size() > 1)
            {
                message += " ";
                message += inpWord;
                break;
            }

            message += inpWord;
            inpMessWork = false;
            break;
        }    

        if (!inpWord.empty()) 
            cout << message;

        if (inpWord.find('/') != std::string::npos)     // условие выхода
        {
            return false;
        }

        if (inpWord.find('*') != std::string::npos)     //  условие запуска вывода автозаполнения
        {
            inpWord.pop_back();
            cout << "Choose the right word and press the corresponding number" << endl;
        
            int resOfFunc = printAutoFillWords(dict, inpWord);      //резельтат возврата функции

            if (resOfFunc == -1)        //если других слов нет 
            {
                cout << "No other strings found with this prefix" << endl;
                message += inpWord;
                inpWord.clear();
                cout << message;
            }
            else if (resOfFunc == 0)    //если слово по префиксу не найдено 
            {
                cout << "No string found with this prefix" << endl;
                inpWord.clear();
                cout << message;
            }

        //формирование вектор аслов для выбора слова для автозаполнения
            TrieNode* pNode = dict;
            for (char s : inpWord) 
            {
                int ind = ((int) s) - (int)'a';
                pNode = pNode->children[ind];
            }

            vector<string> vtr;
            vector<string> words = findWords(pNode, inpWord, vtr);
            inpWord.clear();
            inpWord = choiceWord(words);
            message += " ";
            message += inpWord;
            cout<< message;
        }
    }

    cout <<"Yuor message: "<< message <<endl;
    return true;
}