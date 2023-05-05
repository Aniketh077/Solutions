/*

h)
Random crashes-you are given a source code to test and it randomly crashes and it never
crashes in the same place (you have attached a debugger and you find this) Explain what all you would suspect and how would you go about with isolating the cause.
The deeper you go into computer architecture and explain, better.

*/

/*

h) 
We should suspect the following things: 
Memory issues: Memory management is a crucial aspect of computer architecture. The CPU interacts with memory to read and write data, and if there are issues with memory allocation 
or deallocation, it can cause problems like memory leaks, segmentation faults, or other types of crashes. Memory issues can also be related to the cache hierarchy in the system, 
which is used to optimize data access and reduce the amount of time the CPU spends waiting for data from main memory.

Thread-related issues: multi-threading is an important aspect of modern computer architecture, as it allows for parallel execution of code on multiple CPU cores. However, 
this also introduces the potential for race conditions, deadlocks, and other issues related to thread synchronization. To address these issues, modern CPUs 
include hardware support for synchronization primitives like locks and semaphores.

External dependencies: Modern computer systems are complex and rely on a variety of external dependencies, including libraries, drivers, and system services. 
If these dependencies are not installed or configured correctly, it can cause issues with the code you are testing. Additionally, 
different architectures and operating systems may require different versions or configurations of these dependencies, which can make debugging more difficult.

Debugging tools: Debugging tools like debuggers and profilers rely on the architecture of the system to operate effectively. For example, 
a debugger needs to be able to interact with the CPU and memory to set breakpoints, examine variables, and step through code. Different architectures may require different
debugging tools, or the tools may need to be configured differently to work effectively on a particular system.


*/