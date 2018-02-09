1. Assume we have two processes, P1 and P2, that have both been initialized, and let's assume that each process on this machine is initially allocated 32 KB of memory as its address space. What are the possible address space ranges each process could have? Write a short paragraph explaining your answer.

a. P1: 0 - 32,000; P2: 32,001 - 64,000

b. P1: 0 - 64,000; P2: 0 - 64,000

c. P1: 32,001 - 64,000; P2: 0 - 32,000


2^32 = 64,000. How those addresses are expressed, though, depends on the type of addressing. Flat would show it as incrementally increasing integers starting at 0. Segmented addressing are shown a separate segments separated by offsets.


2. List all of the possible states a process may be in at any point in time. Briefly explain what each of these states mean.

Start - initial state
Ready - waiting for allocation, could be initial allocation or reallocation after interrupt
Running - currently executing
Waiting - blocked pending return of info from i/o
Final - termination by os or exit upon successful completion of task

3. On your machine, how much faster does a printf call take compared to how long a write system call takes?
it varies, sometimes faster, sometimes slower. these are based on ticks, and a program I found while trying to research this, since the timer didn't work for me from the first sprint
fwrite over 1,000,000 writes averages .5625, .5312, .4531, .5312
fprintf over 1,000,000 writes averages .5312, .6406, .5938, .4688


4. printf is a C library function that calls the write system call under the hood. What are some possible reasons as to why printf runs faster than write?
printf uses a buffer, and only pushes out when the buffer is filled, allowing it call write less frequently
if the printf's buffer were 4kb, then the write calls for the test program would be reduced to 341 calls for printf vs. writes 1,000,000
  1,000,000 / (4096/12) == 341.33
write also takes two arguments, which compounds what must be written