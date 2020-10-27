#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int burst_time;
    int arrival_time;
    int finish_time;
    int priority;
    int rem_burst_time;
    int wait_time;
};

bool compare(Process x, Process y)
{
    if (x.arrival_time == y.arrival_time)
    {
        // 2 is more prior than 4 or more
        return x.priority < y.priority;
    }
    return x.arrival_time < y.arrival_time;
}

void about()
{
    cout << "******************************************************************" << endl;
    cout << "\t"
         << "PRIORITY PREEMPTIVE CPU SCHEDULING ALGORITHM SIMULATION" << endl;
    cout << "******************************************************************" << endl;
}

void PrintProcessData(Process process)
{
    cout << process.id << "\t" << process.priority << "\t" << process.arrival_time << "\t" << process.burst_time << "\t" << process.finish_time << "\t" << process.wait_time << endl;
}

int main()
{
    srand(time(0));
    about();

    int pcount;
    cout << "ENTER NO OF PROCESSES: ";
    cin >> pcount;
    Process processes[pcount];
    cout << "PRIORITY, BURST TIME AND ARRIVAL TIME ARE GENERATED USING RANDOM FUNCTION FOR EACH PROCESS." << endl;
    cout << endl;

    for (int i = 0; i < pcount; i++)
    {
        int id = i + 1;
        int priority, burst_time, arrival_time;
        burst_time  = rand() % 20 + 1;
        arrival_time  = rand() % 15;
        priority = rand() % 20;
        // cin >> priority >> burst_time >> arrival_time;
        processes[i].id = id;
        processes[i].priority = priority;
        processes[i].arrival_time = arrival_time;
        processes[i].burst_time = burst_time;
        processes[i].rem_burst_time = burst_time;
    }

    sort(processes, processes + pcount, compare);
    int current_time = 0;
    while (1)
    {
        // we are checking for shortest burst_time after each second
        int short_burst_index = 0;
        int temp_priority = INT_MAX;
        for (int i = 0; i < pcount; i++)
        {   
            if (
                processes[i].rem_burst_time && 
                (processes[i].priority < temp_priority) && 
                (processes[i].arrival_time <= current_time)
            ) {
                short_burst_index = i;
                temp_priority = processes[i].priority;
            }
        }
        
        current_time++;
        if (processes[short_burst_index].rem_burst_time)
        {
            processes[short_burst_index].rem_burst_time -= 1;
            if (processes[short_burst_index].rem_burst_time == 0)
            {
                processes[short_burst_index].finish_time = current_time;
                processes[short_burst_index].wait_time = processes[short_burst_index].finish_time - processes[short_burst_index].burst_time - processes[short_burst_index].arrival_time;
            }
        } 

        bool poss = true;
        for (int i = 0; i < pcount; i++) {
            if (processes[i].rem_burst_time) {
                poss = false;
            }
        }
        if (poss) {
            break;
        }
        // cout << current_time << " " <<  processes[short_burst_index].id << endl;
    }

    cout << "PID" << "\t" << "PRIOR" << "\t" << "ARRIVAL" << "\t" << "BURST" << "\t" 
         << "FINISH" << "\t" << "WAIT" << endl;

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