#include <iostream>
#include <set>
#include <map>

using namespace std;

class Synonyms{
public:
    void ADD(const string& word1, const string& word2);
    int COUNT(const string& word) const;
    bool CHECK(const string& word1, const string& word2) const;
private:
    map<string, set<string>> _synonyms;
};

void Synonyms::ADD(const string& word1, const string& word2) {
    _synonyms[word1].insert(word2);
    _synonyms[word2].insert(word1);
}
int Synonyms::COUNT(const string &word) const {
    try{
        return _synonyms.at(word).size();
    } catch (out_of_range&) {return 0;}
}
bool Synonyms::CHECK(const string &word1, const string &word2) const {
    try{
        return _synonyms.at(word1).find(word2) != _synonyms.at(word1).end();
    } catch (out_of_range&) {return false;}
}

int main(){
    int Q = 0;
    string command, word1, word2;
    Synonyms synonyms;
    cin>>Q;
    for(;Q;--Q){
        cin>>command>>word1;
        if(command == "COUNT")
            cout<<synonyms.COUNT(word1)<<endl;
        else{
            cin>>word2;
            if(command == "ADD")
                synonyms.ADD(word1, word2);
            else if(command == "CHECK")
                cout<<(synonyms.CHECK(word1, word2)?"YES":"NO")<<endl;
        }
    }
    return 0;
}