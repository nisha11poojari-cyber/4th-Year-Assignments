#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    struct Item items[20], temp;
    int n, capacity, i, j;
    float totalProfit = 0, fraction;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);

        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items in descending order of profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Select items using Greedy method
    for (i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            fraction = (float)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}