#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>

#include <algorithm>
using namespace std;

int main() {
    int N;
    int total_W;
    scanf("%d %d", &total_W, &N); fflush(stdin);

    int *weight = new int[N + 1];
    int *benefit = new int[N + 1];

    memset(weight, 0, sizeof(int) * (N + 1));
    memset(benefit, 0, sizeof(int) * (N + 1));

    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &weight[i], &benefit[i]);
        fflush(stdin);
    }

    int k[N + 1][total_W + 1];
    memset(k, 0, sizeof(int) * (N + 1) * (total_W + 1));

    for(int row = 1; row <= N; row++) {
        for(int col = 1; col <= total_W; col++) {
            if(weight[row] > col) {
                k[row][col] = k[row - 1][col];
            } else {
                //temp = profit + previous condition profit
                int temp = benefit[row] + k[row - 1][col - weight[row]];

                //compare with previous item
                if(temp <= k[row - 1][col]) {
                    k[row][col] = k[row - 1][col];
                } else {
                    k[row][col] = temp;
                }
            }
            fprintf(stderr, "%3d ", k[row][col]);
        }
        fprintf(stderr, "\n");
    }
    printf("%d", k[N][total_W]);
}
