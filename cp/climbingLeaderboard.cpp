#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> ranks(player.size());
    vector<int> unique_ranks = {ranked.at(0)};
    {
       // O(n)
        int rank{ranked.at(0)};
        for(const int &val: ranked) {
            if(val < rank) {
                unique_ranks.push_back(val);
                rank = val;
            }
        }
    }
    vector<int> sortedUniqueRank(unique_ranks.size());
    reverse_copy(unique_ranks.begin(), unique_ranks.end(),sortedUniqueRank.begin());
    
    std::size_t uniqueRankSize = unique_ranks.size();
    // O(m * log(n))
    for(std::size_t i{0}; i < player.size(); ++i) {
        int rank{0};
        if(player.at(i) <= unique_ranks.at(uniqueRankSize - 1)) {
            if(player.at(i) == unique_ranks.at(uniqueRankSize - 1)) {
                rank = uniqueRankSize;
            } else
                rank = uniqueRankSize + 1;
        } else if(player.at(i) >= unique_ranks.at(0)) {
            rank = 1;
        } else {
            vector<int>::iterator it = lower_bound(sortedUniqueRank.begin(), sortedUniqueRank.end(), player.at(i));
            rank = abs(distance(sortedUniqueRank.end(), it));
            if(*it > player.at(i)) {
                ++rank;
            }
        }
        // cerr << "rank is: " << rank;
        ranks.at(i) = rank;
    }
    return ranks;
}

int main() {
    freopen ("output.txt","w",stdout);
    freopen ("input.txt","r",stdin);
    int rankedSize{}, playerSize{};
    
    cin >> rankedSize;
    vector<int>ranked(rankedSize);
    for(int i{}, v{}; i < rankedSize; ++i) {
        cin >> v;
        ranked.at(i) = v;
    }
    cin >> playerSize;
    vector<int>player(playerSize);
    for(int i{}, v{}; i < playerSize; ++i) {
        cin >> v;
        player.at(i) = v;
    }
    
    auto start = high_resolution_clock::now();
    vector<int> result = climbingLeaderboard(ranked, player);
    auto stop = high_resolution_clock::now();

    for(const int& value: result) {
        cout << value << "\n";
    }

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time: " << duration.count();

}