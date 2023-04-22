#include <stdio.h>

// 定义一个进程结构体
struct process {
    char name[10];      // 进程名
    int priority;       // 优先级
    int burst_time;     // 运行时间
    int turnaround_time; // 周转时间
};

int main() {
    // 定义3个进程
    struct process processes[3] = {
        {"P1", 2, 5, 0},
        {"P2", 1, 4, 0},
        {"P3", 3, 3, 0}
    };
    
    // 定义一个简单的进程队列
    int queue[3] = {0, 1, 2};   // 进程队列的初始顺序
    
    // 按照进程的优先级排序队列
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (processes[queue[i]].priority < processes[queue[j]].priority) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    
    // 计算每个进程的周转时间和平均周转时间
    float total_turnaround_time = 0;
    for (int i = 0; i < 3; i++) {
        // 运行当前进程
        printf("Running process %s for %d seconds\n", processes[queue[i]].name, processes[queue[i]].burst_time);
        
        // 计算周转时间
        processes[queue[i]].turnaround_time = processes[queue[i]].burst_time;
        for (int j = 0; j < i; j++) {
            processes[queue[i]].turnaround_time += processes[queue[queue[j]]].burst_time;
        }
        
        // 输出进程信息
        printf("Process %s finished (Turnaround time: %d seconds)\n", processes[queue[i]].name, processes[queue[i]].turnaround_time);
        
        // 累计周转时间
        total_turnaround_time += processes[queue[i]].turnaround_time;
    }
    
    // 计算平均周转时间
    float avg_turnaround_time = total_turnaround_time / 3;
    printf("Average turnaround time: %.2f seconds\n", avg_turnaround_time);
    
    return 0;
}
