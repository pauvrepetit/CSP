#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

using std::max;
using std::sort;

int main(void) {
    int len;
    scanf("%d", &len);
    int *heights = (int *)malloc(sizeof(int) * len);
    int *originHeights = (int *)malloc(sizeof(int) * len);
    int *tag = (int *)malloc(sizeof(int) * len);
    memset(tag, 0, sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        scanf("%d", &(heights[i]));
        originHeights[i] = heights[i];
    }
    if (len == 0) {
        printf("0\n");
    } else {
        sort(heights, heights + len);
        int maxArea = 0;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (originHeights[j] < heights[i]) {
                    tag[j] = 1;
                }
            }
            count = 0;
            maxCount = 0;
            for (int j = 0; j < len; j++) {
                if (tag[j] == 0) {
                    count++;
                } else {
                    maxCount = max(maxCount, count);
                    count = 0;
                }
            }
            maxCount = max(maxCount, count);
            maxArea = max(maxArea, maxCount * heights[i]);
        }
        printf("%d\n", maxArea);
    }
    return 0;
}