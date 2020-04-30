#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <class T>
std::vector<T> extract(string str)
{
    stringstream ss;
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    T found;
    std::vector<T> list;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found) {
            list.push_back(found);
        }
        temp = "";
    }
    return list;
}

int main() {

    int inp; cin >> inp;
    std::vector<std::vector<int>> perms;
    std::vector<std::vector<double>> xss;
    cin.get(); cin.ignore();

    for (auto i = 0; i < inp; ++i) {
        stringstream ss;
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        perms.push_back(extract<int>(line1));
        xss.push_back(extract<double>(line2));

        if (i != inp - 1)
            cin.get();
    }

    for (int i = 0; i < inp; ++i) {
        std::vector<double> temp(perms[i].size());
        for (int j = 0; j < perms[i].size(); ++j)
            temp[perms[i][j] - 1] = xss[i][j];

        for (auto item : temp)
            std::cout << item << std::endl;
        std::cout << std::endl;
    }

}