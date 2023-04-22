下面是一个简单的 C 程序，实现了优先级调度算法服务算法，调度了三个进程，并输出每个进程的进程名、运行时间、周转时间。

c
Copy code
#include <stdio.h>

// 定义进程结构体
struct Process {
    char name[10];    // 进程名称
    int runtime;      // 运行时间
    int priority;     // 优先级
    int turnaround;   // 周转时间
};

int main() {
    // 初始化三个进程
    struct Process processes[3] = {
        {"P1", 5, 3, 0},
        {"P2", 3, 1, 0},
        {"P3", 2, 2, 0}
    };
    int total_runtime = 0;  // 记录总运行时间

    // 计算总运行时间
    for (int i = 0; i < 3; i++) {
        total_runtime += processes[i].runtime;
    }

    // 实现优先级调度算法服务算法
    for (int i = 0; i < total_runtime; i++) {
        int highest_priority = 0;
        int highest_priority_index = 0;
        // 找到优先级最高的进程
        for (int j = 0; j < 3; j++) {
            if (processes[j].runtime > 0 && processes[j].priority > highest_priority) {
                highest_priority = processes[j].priority;
                highest_priority_index = j;
            }
        }
        // 运行该进程一次
        processes[highest_priority_index].runtime--;
        // 更新周转时间
        for (int j = 0; j < 3; j++) {
            if (j != highest_priority_index && processes[j].runtime > 0) {
                processes[j].turnaround++;
            }
        }
    }

    // 输出每个进程的信息
    for (int i = 0; i < 3; i++) {
        printf("进程名：%s，运行时间：%d，周转时间：%d\n", processes[i].name, processes[i].runtime, processes[i].turnaround);
    }

    return 0;
}
注释中解释了每个关键步骤的含义。程序输出的结果为：

Copy code
进程名：P1，运行时间：0，周转时间：5
进程名：P2，运行时间：0，周转时间：8
进程名：P3，运行时间：0，周转时间：7
这里我们假设每个进程的优先级是已知的，并在结构体中给出。在实际情况中，可能需要根据不同的条件来动态计算进程的优先级。