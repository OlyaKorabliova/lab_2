#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/// це для сортування, знайшла в неті
template <typename T1, typename T2>
struct decreasing_sort {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

int read_write_file(string filename) {
    vector<string> words1;
    vector<pair<string, int> > words2;
    ifstream f;
    string output;
    map<string, int> mp;

    f.open(filename.c_str());
    while (f >> output)
    {
    ///------ ЗАПИС В МАСИВ words1 -----///
        words1.push_back(output);
    }
    for (size_t i = 0; i < words1.size(); ++i) {
    ///------ ЗАПИС В MAP ------//
        ++mp[words1[i]];
    }

    //for (size_t i = 0; i < words1.size(); ++i) {
    //    cout << words1[i] << endl;
    //}

    for (map<string, int> :: iterator i = mp.begin(); i != mp.end(); ++i) {
    /// ---- ЗАПИС В МАСИВ words2 КОРТЕЖІВ ----//
        words2.push_back(make_pair(i->first, i->second));
    }

//    for (size_t i = 0; i < words2.size(); ++i) {
//        cout << words2[i].first << ": " << words2[i].second << endl;
//    }

    f.close();

    ofstream f_in_alph_order;
    ofstream f_in_numerical_order;
    vector<pair<string, int> > words3(mp.begin(), mp.end());
    sort(words3.begin(), words3.end(), decreasing_sort<string, int>());

    f_in_alph_order.open("alphabet.txt");
    for (size_t i = 0; i < words2.size(); ++i) {
        f_in_alph_order << words2[i].first + "\n";
    }
    f_in_alph_order.close();

    f_in_numerical_order.open("numerical.txt");
    for (size_t i = 0; i < words3.size(); ++i) {
//        cout << words3[i].first << ": " << words3[i].second << endl;
        f_in_numerical_order << words3[i].first + "\n";
    }
    f_in_numerical_order.close();

    return 0;
}

///----------------------------------------///
/// це його код з мудла
void print_if_present(const std::map<char,int> &m, char el)
{
    // Звертання m[...] заборонене!
    // Воно може модифікувати відображення.
    std::map<char,int>::const_iterator itr = m.find(el);
    if( itr != m.end() )
    {
        cout << "Element " << el << " is present, equal to "
             << itr->second << endl;
             // itr вказує на пару pair<char, int> -- ключ-значення.
    }else{
        cout << "Element " << el << " is not present" << endl;
    }
}

int main(int argc, char* argv[]) {
    read_write_file("data.txt");
    return 0;
}

