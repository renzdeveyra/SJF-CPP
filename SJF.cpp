#include <iostream>
#include <vector>     // for dynamic arrays or 'vectors' in C++
#include <climits>    // to apply limits of integral types

using namespace std;

int main() {
  int numProcess;
  cout << "Number of processes: ";
  cin >> numProcess;

  // Vectors to hold process attributes
  vector<int> processId(numProcess);
  vector<int> at(numProcess);
  vector<int> bt(numProcess);
  vector<int> ct(numProcess);
  vector<int> tat(numProcess);
  vector<int> wt(numProcess);
  vector<int> terminated(numProcess);  // flag to indicate if a process has finished executing

  // System time and counters
  int sysTime = 0, total = 0;
  float avgWT = 0, avgTAT = 0;

  // Input arrival and burst times for each process
  for (int i = 0; i < numProcess; i++) {
    cout << "Enter P" << (i) << " arrival time: ";
    cin >> at[i];
    cout << "Enter P" << (i) << " burst time: ";
    cin >> bt[i];
    processId[i] = i;
    terminated[i] = 0;  // set process as unfinished
  }

  // Main scheduling loop
  while (true) {
    // keeping track of the next process to execute
    int nextProcessIndex = numProcess;
    int min = INT_MAX;

    // Break condition: all processes are finished
    if (total == numProcess)
      break;

    // Find the next process to execute based on arrival time and remaining burst time
    for (int i = 0; i < numProcess; i++) {
      if (at[i] <= sysTime && terminated[i] == 0 && bt[i] < min) {
        min = bt[i];
        nextProcessIndex = i;
      }
    }

    // Execute the selected process or increment system time if no process is available
    if (nextProcessIndex == numProcess)
      sysTime++;
    else {
      ct[nextProcessIndex] = sysTime + bt[nextProcessIndex];
      sysTime += bt[nextProcessIndex];
      tat[nextProcessIndex] = ct[nextProcessIndex] - at[nextProcessIndex];
      wt[nextProcessIndex] = tat[nextProcessIndex] - bt[nextProcessIndex];
      terminated[nextProcessIndex] = 1;
      processId[total] = nextProcessIndex + 1;
      total++;
    }
  }

  // Headers for process details
  cout << "\npid          arrival          burst         turnaround       waiting\n";

  // Calculate and output process details along with averages
  for (int i = 0; i < numProcess; i++) {
    avgWT += wt[i];
    avgTAT += tat[i];
    cout << processId[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << "\n";
  }
  cout << "\nAverage Turnaround Time: " << (avgTAT / numProcess) << " ms" << endl;
  cout << "Average Waiting Time: " << (avgWT / numProcess) << " ms" << endl;

  return 0;
}
