#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> indexes;
    vector<int> seq = {1,2,3,4,5,1,3,1,6,3,2,3};
    int frames = 4;
    int pageFaults = 0, pageHits = 0;
    vector<vector<int>> pages;
    int toReplace = 0;

    for (int i = 0; i < seq.size(); i++) {
        bool isPresent = false;
        for (int j = 0; j < pages.size(); j++) {
            if (find(pages[j].begin(), pages[j].end(), seq[i]) != pages[j].end()) {
                isPresent = true;
                pageHits++;
                break;
            }
        }

        if (!isPresent) {
            pageFaults++;
            if (pages.size() < frames) {
                pages.push_back(vector<int>({seq[i]}));
            } else {
                pages[toReplace] = vector<int>({seq[i]});
                toReplace = (toReplace + 1) % frames;
            }
        }

        for (auto page : pages) {
            for (auto val : page) {
                cout << val << "\t";
            }
        }
            cout << "\n";
    }

    cout << "Page faults: " << pageFaults << "\n";
    cout << "Page hits: " << pageHits << "\n";
    return 0;
}
