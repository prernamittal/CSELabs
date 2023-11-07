#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct DSA {
    int request_id;
    int arrival_timestamp;
    int cylinder;
    int address;
    int process_id;
};

// Function to simulate FCFS disk scheduling
void FCFS(struct DSA *requests, int n) {
    int current_cylinder = 0;
    int total_movement = 0;

    printf("FCFS Disk Scheduling Order:\n");

    for (int i = 0; i < n; i++) {
        printf("Request ID: %d, Process ID: %d, Cylinder: %d\n", requests[i].request_id, requests[i].process_id, requests[i].cylinder);
        total_movement += abs(current_cylinder - requests[i].cylinder);
        current_cylinder = requests[i].cylinder;
    }

    printf("Total head movement: %d\n", total_movement);
}

// Function to simulate SSTF disk scheduling
void SSTF(struct DSA *requests, int n) {
    int current_cylinder = 0;
    int total_movement = 0;

    printf("SSTF Disk Scheduling Order:\n");

    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int min_distance = 1000000; // A large initial value
        int next_request = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(current_cylinder - requests[j].cylinder);
                if (distance < min_distance) {
                    min_distance = distance;
                    next_request = j;
                }
            }
        }

        visited[next_request] = 1;
        printf("Request ID: %d, Process ID: %d, Cylinder: %d\n", requests[next_request].request_id, requests[next_request].process_id, requests[next_request].cylinder);
        total_movement += min_distance;
        current_cylinder = requests[next_request].cylinder;
    }

    printf("Total head movement: %d\n", total_movement);

    free(visited);
}

int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    struct DSA *requests = (struct DSA *)malloc(n * sizeof(struct DSA));

    printf("Enter disk requests in the format: RequestID ArrivalTimestamp Cylinder Address ProcessID\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &requests[i].request_id, &requests[i].arrival_timestamp, &requests[i].cylinder, &requests[i].address, &requests[i].process_id);
    }

    FCFS(requests, n);
    SSTF(requests, n);

    free(requests);

    return 0;
}
