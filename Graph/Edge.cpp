//reishaul1@gmail.com
#include "Edge.hpp"

// bubble sort for this section I'm asks chat gpt for the right implementaion beacuse we learn this in data structure course last year
void bubbleSort(Edge* edges, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // swap edges
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}