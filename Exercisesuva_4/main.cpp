#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;



int getInvCount(std::string str)
{
    static unordered_map<char, int> comp{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    static unordered_map<string, int> inversions{};

    if (inversions.count(str) > 0)
        return inversions[str];

    int inv_count = 0;
    for (int i = 0; i < str.size() - 1; i++)
        for (int j = i + 1; j < str.size(); j++)
            if (comp[str[i]] > comp[str[j]])
                inv_count++;

    inversions.emplace(str, inv_count);
    return inv_count;
}

int main() {

    int inp; cin >> inp;

    auto compare = [&](auto a, auto b) {
        return getInvCount(a) > getInvCount(b);
    };

    using vector_of_queues =  vector <priority_queue <string, vector<string>, decltype(compare)>>;
    vector_of_queues queues(inp, std::priority_queue<string, std::vector<string>, decltype(compare)>(compare));

    cin.get(); cin.ignore();

    for (auto i = 0; i < inp; ++i) {
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < m; ++j)
        {
            string chain;
            chain.reserve(n);
            cin >> chain;
            queues[i].emplace(chain);
        }

    }

    for (auto& queue : queues)
    {
        while (! queue.empty())
        {
            auto temp = queue.top();
            std::cout << temp << '\n';
            queue.pop();
        }
        std::cout << std::endl;
    }
}