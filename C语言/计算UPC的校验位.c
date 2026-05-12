#include <stdio.h>
#include <string.h>
int main() {
    char line[100];
    int num;
    int sec[5], third[5];
    
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);
    fgets(line, sizeof(line), stdin);
    for (int i = 0; i < 5; i++) {
        sec[i] = line[i] - '0';  
    }
    fgets(line, sizeof(line), stdin);
    for (int i = 0; i < 5; i++) {
        third[i] = line[i] - '0';
    }

    int temp1 = num + sec[1] + sec[3] + third[0] + third[2] + third[4];
    int temp2 = sec[0] + sec[2] + sec[4] + third[1] + third[3];
    int ans = 9 - (temp1 * 3 + temp2 - 1) % 10;
    printf("%d\n", ans);
    return 0;
}