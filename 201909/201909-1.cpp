#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int N, M;
    cin >> N >> M;
    int temp;
    int originNumSum = 0;
    int *lossNum = new int[N];
    int lossNumSum = 0;
    int lossMax = 0;
    int loss = 0;
    memset(lossNum, 0, sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        cin >> temp;
        originNumSum += temp;
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp < 0) {
                temp = -temp;
            }
            lossNum[i] += temp;
            lossNumSum += temp;
        }
        if (lossMax < lossNum[i]) {
            lossMax = lossNum[i];
            loss = i;
        }
    }
    cout << originNumSum - lossNumSum << " " << loss + 1 << " " << lossMax << endl;

    return 0;
}
