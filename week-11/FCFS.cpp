#include<iostream> 
using namespace std;

// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n,
    int bt[], int wt[])
{
    // waiting time for first process is 0 
    wt[0] = 0;

    // calculating waiting time 
    for (int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];
}

// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n,
    int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time 
void calculateMetrics(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    //finding waiting time
    findWaitingTime(processes, n, bt, wt);

    //finding turn around time
    findTurnAroundTime(processes, n, bt, wt, tat);


    cout << "Processes "<< " Burst time "
        << " Waiting time " << " Turn around time\n";

    // calculating total_wt and total_tat
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl<<endl;
    }

    cout << "Average waiting time = "
        << (float)total_wt / (float)n<<endl;

    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n<<endl;
}

int main()
{
    //processes 
    int processes[] ={ 1, 2, 3 };
    int no_of_processes = sizeof processes / sizeof processes[0];

    //Burst times
    int burst_time[] ={ 10, 5, 8 };

    calculateMetrics(processes, no_of_processes, burst_time);
    return 0;
}
