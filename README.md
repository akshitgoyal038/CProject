# CProject
This repository contains implementations and explanations of three popular CPU scheduling algorithms: Round Robin, Shortest Job First (SJF), and Priority Scheduling. Each algorithm plays a crucial role in managing the execution of processes in a multi-tasking operating system. This README file provides an overview of each algorithm, along with instructions on how to use and understand the code provided in this repository.

Table of Contents
Round Robin (RR)
Shortest Job First (SJF)
Priority Scheduling


Round Robin (RR)
Round Robin is a simple, preemptive scheduling algorithm that assigns a fixed time quantum to each process in a circular manner. When a process's time quantum expires, it is moved to the back of the queue, allowing other processes to execute. RR is particularly useful in time-sharing systems.


Shortest Job First (SJF)
Shortest Job First is a non-preemptive scheduling algorithm that selects the process with the shortest burst time to execute next. This algorithm aims to minimize the average waiting time and turnaround time, making it suitable for batch processing.


Priority Scheduling
Priority Scheduling assigns a priority level to each process, and the process with the highest priority is executed first. In this implementation, a lower numeric value indicates a higher priority. Priority Scheduling can be either preemptive or non-preemptive.
