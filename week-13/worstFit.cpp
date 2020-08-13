#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pId;
    int mSizeRequired;
    int allocatedBlockNumber = -1;
};

struct MBlock
{
    int blockNumber;
    int size;
    bool isAllocated = false;
};

// sorting Memory block
bool comparison(MBlock first, MBlock second)
{
    return first.size > second.size;
}

int getAllocatedBlockIndex(MBlock blocks[], int blockNumber, int blockLen)
{
    for (int i = 0; i < blockLen; i++)
    {
        if (blocks[i].blockNumber == blockNumber)
        {
            return i;
        }
    }
    // never gonna happen
    return -1;
}

void printResult(Process processes[], MBlock blocks[], int blockLen, int processLen)
{
    cout << "\nProcess ID  "
         << "Process Size  "
         << "Allocated Block Number  "
         << "Allocated Block Size  " << endl;
    for (int i = 0; i < processLen; i++)
    {
        cout << processes[i].pId << "\t\t"
             << processes[i].mSizeRequired << "\t\t";
        if (processes[i].allocatedBlockNumber == -1)
        {
            cout << "Not Allocated\t\t"
                 << "Not Allocated" << endl;
        }
        else
        {
            int blockIndex = getAllocatedBlockIndex(blocks, processes[i].allocatedBlockNumber, blockLen);
            cout
                << processes[i].allocatedBlockNumber << "\t\t\t"
                << blocks[blockIndex].size << endl;
        }
    }
}

void bestFit(Process processes[], MBlock blocks[], int blockLen, int processLen)
{
    for (int i = 0; i < processLen; i++)
    {
        for (int j = 0; j < blockLen; j++)
        {
            if ((processes[i].mSizeRequired <= blocks[j].size) && !blocks[j].isAllocated)
            {
                processes[i].allocatedBlockNumber = blocks[j].blockNumber;
                blocks[j].isAllocated = true;
                break;
            }
        }
    }
}

int main()
{
    Process processes[] = {{0, 10}, {1, 5}, {2, 8}, {3, 12}, {4, 9}};

    MBlock blocks[] = {{0, 12}, {1, 8}, {2, 5}, {3, 10}, {4, 6}};

    int blockLen = sizeof(blocks) / sizeof(blocks[0]);
    int processLen = sizeof(processes) / sizeof(processes[0]);

    sort(blocks, blocks + blockLen, comparison);

    bestFit(processes, blocks, blockLen, processLen);

    printResult(processes, blocks, blockLen, processLen);

    return 0;
}