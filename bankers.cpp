/*
 * Bankers Algorithm Project (OS)
 * Ali Emad 1610052 - Aya Hany 1610139 - Salmeen Essam 1610102
 */

#include <iostream>
using namespace std;

struct process
{
    int allocResources[10];
    int maxNeed[10];
    bool finished;
};

int main()
{
    freopen("input.txt", "r", stdin);

    struct process processes[10];

    int completedProcesses[10];

    int m; // Number of processes
    int n; // Number of resource types
    int availableResources[10];

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> availableResources[i];
    }

    for (int i = 0; i < m; i++)
    {
        processes[i].finished = false;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            processes[i].allocResources[j] = temp;
            availableResources[j] -= temp;
        }
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            processes[i].maxNeed[j] = temp;
        }
    }

    bool finished = false;
    int processTurn = 0;

    while (!finished)
    {
        bool unsafeState = true;
        int completedCount = 0;
        for (int i = 0; i < m; i++)
        {
            if (processes[i].finished)
            {
                completedCount++;
                continue;
            }

            int possibleAlloc = 0;

            for (int j = 0; j < n; j++)
            {
                if (availableResources[j] >= (processes[i].maxNeed[j] - processes[i].allocResources[j]))
                {
                    possibleAlloc++;
                }
            }
            if (possibleAlloc == n)
            {
                for (int j = 0; j < n; j++)
                {
                    availableResources[j] += processes[i].allocResources[j];
                    processes[i].allocResources[j] = 0;
                }
                processes[i].finished = true;
                completedProcesses[processTurn] = i + 1;
                processTurn++;
                unsafeState = false;
            }
        }

        if (completedCount == m)
        {
            finished = true;
            break;
        }
        if (unsafeState)
        {
            cout << "false" << endl;
            break;
        }
    }

    if (finished)
    {
        cout << "true" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << completedProcesses[i] << " ";
        }
    }
    return 0;
}