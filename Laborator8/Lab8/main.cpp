#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    vector<string> cuv;
    string delimiters = " ,?!.";
    int startcuv, pos = 0;
    while ((startcuv = s.find_first_not_of(delimiters, pos)) > -1) 
    {
        pos = s.find_first_of(delimiters, startcuv + 1);
        cuv.push_back(s.substr(startcuv, pos - startcuv));
    }
    map<string, int> freq;
    for (string word : cuv) 
    {
        string news = "";
        for (auto c : word) 
            news += tolower(c);
        freq[news]++;
    }
    auto compara = [&](const string& a, const string& b) -> bool 
    {
        if (freq[a] == freq[b]) {
            return a > b;
        }
        else {
            return freq[a] < freq[b];
        }
    };
    auto complength = [&](const string& a, const string& b) -> bool
    {
        return a.size() < b.size();
    };
    priority_queue<string, vector<string>, decltype(compara)> queue(compara);
    for (auto const& p : freq) {
        queue.push(p.first);
    }
    while (!queue.empty()) {
        cout << queue.top() << " => " << freq[queue.top()] << '\n';
        queue.pop();
    }
    priority_queue<string, vector<string>, decltype(complength)> queuelength(complength);
    for (auto const& p : freq) {
        queuelength.push(p.first);
    }
    while (!queuelength.empty()) {
        cout << queuelength.top()  << '\n';
        queuelength.pop();
    }
    return 0;
}