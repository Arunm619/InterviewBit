#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printMeetings(const vector<pair<int, int>> &meetings) {
    for (auto &each : meetings) {
        cout << each.first << "-" << each.second << "\n";
    }
}
bool hotel(vector<int> arrive, vector<int> depart, int K) {
    vector<pair<int, int>> times;
    times.reserve(arrive.size());
    for (size_t i = 0; i < arrive.size(); i++) {
        times.emplace_back(arrive[i], depart[i]);
    }

    sort(begin(times), end(times));

    printMeetings(times);

    K--; //for first room.
    for (size_t i = 1; i < times.size(); i++) {
        if (times[i].first >=times[i - 1].second  ) {
            continue;
            //non overlapping times.
        } else if(K>0){
            //overlapping
           // we have more rooms
            K--;
        } else{
            //we dont have rooms
            return false;
        }
    }
    return true;
}


int main() {


    cout << hotel({ 1, 2, 3, 4 },
                  {10, 2, 6, 14},
                  2);
    return 0;
}