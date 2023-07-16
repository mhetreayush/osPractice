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

    vector<int> blockSize = {100,500,200,300,600};
    vector<int> processSize = {212,417,112,426};
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
        int current=INT_MIN;
        int ind=0;
        for (int j = 0; j < blockSize.size(); j++)
        {
            if(blockSize[j]>current && blockSize[j]>=processSize[i]){
                ind=j;
                current=blockSize[j];
            }
        }
        if(blockSize[ind]>=processSize[i]){
            blockSize[ind]-=processSize[i];
            processes[i].blockIndex=ind+1;
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