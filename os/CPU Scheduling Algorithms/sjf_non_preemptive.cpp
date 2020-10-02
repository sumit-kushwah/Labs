#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int burst_time;
    int arrival_time;
    int start_time;
    int finish_time;
    int wait_time;
};

bool compare(Process x, Process y)
{
    if (x.arrival_time == y.arrival_time)
    {
        return x.burst_time < y.burst_time;
    }

    return x.arrival_time < y.arrival_time;
}

void about()
{
    cout << endl;
    cout << "\t"
         << "SJF NON PREEMPTIVE CPU SCHEDULING ALGORITHM SIMULATION" << endl;
    cout << endl;
}

void PrintProcessData(Process process)
{
    cout << process.id << "\t" << process.arrival_time << "\t" << process.start_time << "\t" 
    << process.burst_time << "\t" << process.finish_time << "\t" << process.wait_time << endl;
}

int main()
{
    about();

    int pcount;
    cout << "ENTER NO OF PROCESSES: ";
    cin >> pcount;
    Process processes[pcount];
    cout << "BURST TIME AND ARRIVAL TIME ARE GENERATED USING RANDOM FUNCTION FOR EACH PROCESS." << endl;
    cout << endl;

    for (int i = 0; i < pcount; i++)
    {
        int id = i + 1;
        int burst_time = rand() % 20;
        int arrival_time = rand() % 15;
        processes[i].id = id;
        processes[i].arrival_time = arrival_time;
        processes[i].burst_time = burst_time;
    }
    sort(processes, processes + pcount, compare);

    cout << endl;
    cout << "ID" << "\t" << "ARRIVAL" << "\t" << "START" << "\t"
         << "BURST" << "\t" << "FINISH" << "\t" << "WAIT" << endl;

    processes[0].start_time = processes[0].arrival_time;
    processes[0].finish_time = processes[0].start_time + processes[0].burst_time;
    processes[0].wait_time = processes[0].start_time - processes[0].arrival_time;

    for (int i = 1; i < pcount; i++)
    {
        int best_burst_index = i;
        for (int j = i; j < pcount; j++)
        {
            if (processes[j].arrival_time >= processes[i - 1].finish_time)
            {
                break;
            }
            else
            {
                if (processes[j].burst_time < processes[best_burst_index].burst_time)
                {
                    best_burst_index = j;
                }
            }
        }
        // shifting
        Process best_burst_process = processes[best_burst_index];
        for (int k = best_burst_index; k > i; k--)
        {
            processes[k] = processes[k - 1];
        }
        processes[i] = best_burst_process;

        processes[i].start_time = max(processes[i].arrival_time, processes[i - 1].finish_time);
        processes[i].finish_time = processes[i].start_time + processes[i].burst_time;
        processes[i].wait_time = processes[i].start_time - processes[i].arrival_time;
    }

    float totalWaitTime = 0;
    for (int i = 0; i < pcount; i++)
    {
        PrintProcessData(processes[i]);
        totalWaitTime += processes[i].wait_time;
    }

    cout << endl;
    cout << "AVERAGE WAITING TIME PER PROCESS:" << endl;
    cout << fixed << setprecision(2) << totalWaitTime / float(pcount) << " units" << endl;
    return 0;
}