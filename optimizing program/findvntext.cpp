#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include<map>
#include<set>
#include<time.h>

using namespace std;


map<wchar_t, int> bangchucai; // 89 ký tự


struct Node
{
    Node* child[89];
    bool isEnd;

    Node()
    {
        isEnd = false;
        for(int i=0; i< 89; i++)
        {
            child[i] = nullptr;
        }
    }
};

void addkey(Node* root, wstring key)
{
    Node* cur = root;
    int t;
    for (auto x: key)
    {
        t = bangchucai[x] - 1;
        if(t==-1)
        {
            cout << "Error 1" << endl;
            exit(1);
        }
        if(cur->child[t]==nullptr)
        {
            cur->child[t] = new Node;
        }
        cur = cur->child[t];
    }
    cur->isEnd = true;
    return;
}

bool searchkey(Node* root, wstring key)
{
    Node* cur = root;
    int t;
    for (auto x: key)
    {
        t = bangchucai[x] - 1;
        if(t==-1)
        {
            cout << "Error 2" << endl;
            exit(2);
        }
        if(cur->child[t]==nullptr)
        {
            return false;
        }
        cur = cur->child[t];
    }
    return cur->isEnd;
}

void setup()
{
    bangchucai[L'a'] = 89; bangchucai[L'A'] = 89; //giá trị không tồn tại bằng 0
    bangchucai[L'á'] = 1; bangchucai[L'Á'] = 1;
    bangchucai[L'à'] = 2; bangchucai[L'À'] = 2;
    bangchucai[L'ả'] = 3; bangchucai[L'Ả'] = 3;
    bangchucai[L'ã'] = 4; bangchucai[L'Ã'] = 4;
    bangchucai[L'ạ'] = 5; bangchucai[L'Ạ'] = 5;
    bangchucai[L'â'] = 6; bangchucai[L'Â'] = 6;
    bangchucai[L'ấ'] = 7; bangchucai[L'Ấ'] = 7;
    bangchucai[L'ầ'] = 8; bangchucai[L'Ầ'] = 8;
    bangchucai[L'ẩ'] = 9; bangchucai[L'Ẩ'] = 9;
    bangchucai[L'ẫ'] = 10; bangchucai[L'Ẫ'] = 10;
    bangchucai[L'ậ'] = 11; bangchucai[L'Ậ'] = 11;
    bangchucai[L'ă'] = 12; bangchucai[L'Ă'] = 12;
    bangchucai[L'ắ'] = 13; bangchucai[L'Ắ'] = 13;
    bangchucai[L'ằ'] = 14; bangchucai[L'Ằ'] = 14;
    bangchucai[L'ẳ'] = 15; bangchucai[L'Ẳ'] = 15;
    bangchucai[L'ẵ'] = 16; bangchucai[L'Ẵ'] = 16;
    bangchucai[L'ặ'] = 17; bangchucai[L'Ặ'] = 17;
    bangchucai[L'b'] = 18; bangchucai[L'B'] = 18;
    bangchucai[L'c'] = 19; bangchucai[L'C'] = 19;
    bangchucai[L'd'] = 20; bangchucai[L'D'] = 20;
    bangchucai[L'đ'] = 21; bangchucai[L'Đ'] = 21;
    bangchucai[L'e'] = 22; bangchucai[L'E'] = 22;
    bangchucai[L'é'] = 23; bangchucai[L'É'] = 23;
    bangchucai[L'è'] = 24; bangchucai[L'È'] = 24;
    bangchucai[L'ẻ'] = 25; bangchucai[L'Ẻ'] = 25;
    bangchucai[L'ẽ'] = 26; bangchucai[L'Ẽ'] = 26;
    bangchucai[L'ẹ'] = 27; bangchucai[L'Ẹ'] = 27;
    bangchucai[L'ê'] = 28; bangchucai[L'Ê'] = 28;
    bangchucai[L'ế'] = 29; bangchucai[L'Ế'] = 29;
    bangchucai[L'ề'] = 30; bangchucai[L'Ề'] = 30;
    bangchucai[L'ể'] = 31; bangchucai[L'Ể'] = 31;
    bangchucai[L'ễ'] = 32; bangchucai[L'Ễ'] = 32;
    bangchucai[L'ệ'] = 33; bangchucai[L'Ệ'] = 33;
    bangchucai[L'g'] = 34; bangchucai[L'G'] = 34;
    bangchucai[L'h'] = 35; bangchucai[L'H'] = 35;
    bangchucai[L'i'] = 36; bangchucai[L'I'] = 36;
    bangchucai[L'í'] = 37; bangchucai[L'Í'] = 37;
    bangchucai[L'ì'] = 38; bangchucai[L'Ì'] = 38;
    bangchucai[L'ỉ'] = 39; bangchucai[L'Ỉ'] = 39;
    bangchucai[L'ĩ'] = 40; bangchucai[L'Ĩ'] = 40;
    bangchucai[L'ị'] = 41; bangchucai[L'Ị'] = 41;
    bangchucai[L'k'] = 42; bangchucai[L'K'] = 42;
    bangchucai[L'l'] = 43; bangchucai[L'L'] = 43;
    bangchucai[L'm'] = 44; bangchucai[L'M'] = 44;
    bangchucai[L'n'] = 45; bangchucai[L'N'] = 45;
    bangchucai[L'o'] = 46; bangchucai[L'O'] = 46;
    bangchucai[L'ó'] = 47; bangchucai[L'Ó'] = 47;
    bangchucai[L'ò'] = 48; bangchucai[L'Ò'] = 48;
    bangchucai[L'ỏ'] = 49; bangchucai[L'Ỏ'] = 49;
    bangchucai[L'õ'] = 50; bangchucai[L'Õ'] = 50;
    bangchucai[L'ọ'] = 51; bangchucai[L'Ọ'] = 51;
    bangchucai[L'ô'] = 52; bangchucai[L'Ô'] = 52;
    bangchucai[L'ố'] = 53; bangchucai[L'Ố'] = 53;
    bangchucai[L'ồ'] = 54; bangchucai[L'Ồ'] = 54;
    bangchucai[L'ổ'] = 55; bangchucai[L'Ổ'] = 55;
    bangchucai[L'ỗ'] = 56; bangchucai[L'Ỗ'] = 56;
    bangchucai[L'ộ'] = 57; bangchucai[L'Ộ'] = 57;
    bangchucai[L'ơ'] = 58; bangchucai[L'Ơ'] = 58;
    bangchucai[L'ớ'] = 59; bangchucai[L'Ớ'] = 59;
    bangchucai[L'ờ'] = 60; bangchucai[L'Ờ'] = 60;
    bangchucai[L'ở'] = 61; bangchucai[L'Ở'] = 61;
    bangchucai[L'ỡ'] = 62; bangchucai[L'Ỡ'] = 62;
    bangchucai[L'ợ'] = 63; bangchucai[L'Ợ'] = 63;
    bangchucai[L'p'] = 64; bangchucai[L'P'] = 64;
    bangchucai[L'q'] = 65; bangchucai[L'Q'] = 65;
    bangchucai[L'r'] = 66; bangchucai[L'R'] = 66;
    bangchucai[L's'] = 67; bangchucai[L'S'] = 67;
    bangchucai[L't'] = 68; bangchucai[L'T'] = 68;
    bangchucai[L'u'] = 69; bangchucai[L'U'] = 69;
    bangchucai[L'ú'] = 70; bangchucai[L'Ú'] = 70;
    bangchucai[L'ù'] = 71; bangchucai[L'Ù'] = 71;
    bangchucai[L'ủ'] = 72; bangchucai[L'Ủ'] = 72;
    bangchucai[L'ũ'] = 73; bangchucai[L'Ũ'] = 73;
    bangchucai[L'ụ'] = 74; bangchucai[L'Ụ'] = 74;
    bangchucai[L'ư'] = 75; bangchucai[L'Ư'] = 75;
    bangchucai[L'ứ'] = 76; bangchucai[L'Ứ'] = 76;
    bangchucai[L'ừ'] = 77; bangchucai[L'Ừ'] = 77;
    bangchucai[L'ử'] = 78; bangchucai[L'Ử'] = 78;
    bangchucai[L'ữ'] = 79; bangchucai[L'Ữ'] = 79;
    bangchucai[L'ự'] = 80; bangchucai[L'Ự'] = 80;
    bangchucai[L'v'] = 81; bangchucai[L'V'] = 81;
    bangchucai[L'x'] = 82; bangchucai[L'X'] = 82;
    bangchucai[L'y'] = 83; bangchucai[L'Y'] = 83;
    bangchucai[L'ý'] = 84; bangchucai[L'Ý'] = 84;
    bangchucai[L'ỳ'] = 85; bangchucai[L'Ỳ'] = 85;
    bangchucai[L'ỷ'] = 86; bangchucai[L'Ỷ'] = 86;
    bangchucai[L'ỹ'] = 87; bangchucai[L'Ỹ'] = 87;
    bangchucai[L'ỵ'] = 88; bangchucai[L'Ỵ'] = 88;
    return;
}

set<wstring> process_text(wstring str)
{
    wstring word = L"";
    set<wstring> word_list;

    for (auto x: str)
    {
        if (bangchucai[x]==0)
        {
            if(word.length()!=0)
            {
                word_list.insert(word);
            }
            word = L"";
        }
        else
        {
            word += x;
        }
    }
    if(word.length()!=0)
    {
        word_list.insert(word);
    }
    return word_list;
}

int main()
{
    clock_t start, End;
    start = clock();
    // setup bảng chữ cái
    setup();

    Node *allwords = new Node;

    locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);

	wstring word;
	wifstream A("fileA.txt");
	A.imbue(loc);
    while(getline(A,word))
    {
        addkey(allwords,word);
    }
    A.close();
    End = clock();
    double time1 = (double)(End-start)/CLOCKS_PER_SEC;
    start = clock();
    set<wstring> foundword;
    wifstream B("fileB.txt");
    B.imbue(loc);
    while(getline(B,word))
    {
        set<wstring> wordlist = process_text(word);
        for (auto x: wordlist)
        {
            if(searchkey(allwords,x)==true)
            {
                foundword.insert(x);
            }
        }
    }
    B.close();
    End = clock();
    double time2 = (double)(End-start)/CLOCKS_PER_SEC;
    start = clock();
    cout << foundword.size() << endl;
    cout << (double(foundword.size()) / 7000) * 100 << "%" << endl;
    End = clock();
    double time3 = (double)(End-start)/CLOCKS_PER_SEC;
    cout << time1 << ' ' << time2 << ' ' << time3 << ' ' << time1 + time2 + time3 << endl;
    // time1 + time2 + time3 arround 0.1
    return 0;
}

