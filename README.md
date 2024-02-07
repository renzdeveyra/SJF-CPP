# SJF-C++

**Introduction to SJF:** The code implements the Shortest Job First (SJF) CPU scheduling algorithm, which selects the process with the smallest execution time (burst time) to execute next, aiming to minimize the average waiting time.
**Code Structure:** The code uses vectors to store various process attributes such as process IDs, arrival times, burst times, completion times, turnaround times, and waiting times. It also uses a flag array to mark whether a process has finished executing.
**User Input:** The program prompts the user to enter the number of processes and their respective arrival and burst times. These inputs are crucial for simulating the SJF scheduling algorithm.
**Main Scheduling Loop:** The while loop is the heart of the SJF algorithm. It continuously checks for processes that are ready to execute based on their arrival time and remaining burst time. The loop terminates once all processes have been executed.
**Selection Logic:** Within the while loop, the code searches for the process with the shortest remaining burst time that has arrived but not yet started executing. This selection is made using a nested for loop that iterates over all processes.
**Execution or Time Advancement:** Depending on whether a suitable process is found, the code either updates the process's completion time, increments the system time, calculates waiting and turnaround times, marks the process as finished, and adds the process ID to the list of completed processes. If no process is found, the system time is simply incremented.
**Termination Condition:** The loop breaks when all processes have been executed, ensuring that the SJF algorithm has completed its task.
**Output:** Finally, the program prints a summary of each process's details, including their process IDs, arrival times, burst times, turnaround times, and waiting times. It also calculates and displays the average turnaround time and average waiting time for all processes.
