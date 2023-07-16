#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct process
{
    int processNo;
    int processSize;
    int blockIndex = -1;
    process(int p)
    {
        this->processNo = p;
    };
};

int main()
{

    vector<int> blockSize = {200, 300, 400, 500};
    vector<int> processSize = {150, 350, 450, 500};
    vector<process> processes;

    for (int i = 0; i < processSize.size(); i++)
    {
        processes.push_back(process(i + 1));
        processes[i].processSize = processSize[i];
    }
    cout << "\nInitial block Sizes\n";
    for (auto i : blockSize)
    {
        cout << i << "\t";
    }
    cout << "\n";
    for (int i = 0; i < processSize.size(); i++)
    {
        for (int j = 0; j < blockSize.size(); j++)
        {
            if (processSize[i] <= blockSize[j])
            {
                processes[i].blockIndex = j + 1;
                blockSize[j] = blockSize[j] - processSize[i];
                break;
            }
        }
    }

    cout << "\n";
    for (process p : processes)
    {
        cout << p.processNo << " : " << p.blockIndex << endl;
    }
    cout << "\nFinal block Sizes\n";
    for (auto i : blockSize)
    {
        cout << i << "\t";
    }
    return 0;
}