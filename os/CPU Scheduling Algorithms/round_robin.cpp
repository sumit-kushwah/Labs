#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int burst_time;
    int finish_time;
    int rem_burst_time;
    int wait_time;
};

void about()
{
    cout << "*******************************************************************" << endl;
    cout << "\t"
         << "ROUND ROBIN CPU SCHEDULING ALGORITHM SIMULATION" << endl;
    cout << "*******************************************************************" << endl;
}

void PrintProcessData(Process process)
{
    cout << process.id << "\t"
         << process.burst_time << "\t" << process.finish_time << "\t" << process.wait_time << endl;
}

int main()
{
    srand(time(0));
    about();

    int pcount, time_slice;
    cout << "ENTER NO OF PROCESSES: ";
    cin >> pcount;
    cout << "ENTER TIME SLICE: ";
    cin >> time_slice;
    if (time_slice <= 0)
    {
        cout << "Time slice must be greater than zero.";
        return 0;
    }
    vector<Process> processes(pcount);
    cout << "BURST TIME IS GENERATED USING RANDOM FUNCTION FOR EACH PROCESS." << endl;
    cout << endl;

    for (int i = 0; i < pcount; i++)
    {
        int id = i + 1;
        int burst_time;
        burst_time  = rand() % 20 + 1;
        // cin >> burst_time;
        processes[i].id = id;
        processes[i].burst_time = burst_time;
        processes[i].rem_burst_time = burst_time;
    }

    cout << "Round robin sequence for processes:" << endl;
    int current_time = 0;
    while (1)
    {
        bool poss = true;
        for (int i = 0; i < pcount; i++)
        {
            if (processes[i].rem_burst_time)
            {
                if (processes[i].rem_burst_time > time_slice)
                {
                    processes[i].rem_burst_time -= time_slice;
                    current_time += time_slice;
                }
                else
                {
                    current_time += processes[i].rem_burst_time;
                    processes[i].rem_burst_time = 0;
                    processes[i].finish_time = current_time;
                    processes[i].wait_time = processes[i].finish_time - processes[i].burst_time;
                }
                cout << "P" << processes[i].id << " ";
            }

            if (processes[i].rem_burst_time) {
                poss = false;
            }
        }
        if (poss)
        {
            break;
        }
    }
    cout << "\n" << endl;
    cout << "PID" << "\t" << "BURST" << "\t" << "FINISH" << "\t" << "WAIT" << endl;
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