#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <cstdlib>

class Node {
 public:
  int data;
  Node* before;
  Node(int data, Node* before) : data(data), before(before) {}
  Node() : data(0), before(NULL) {}
};

int main() {
  int n;
  scanf("%d", &n);
  Node nodes[(1 << (n + 1)) - 1];

  nodes[1].data = 0;
  nodes[1].before = NULL;
  nodes[2].data = 1;
  nodes[2].before = NULL;

  int curr = 2;
  while (curr < (1 << n)) {
    for (int j = 0; j < curr; j += 1) {
      nodes[j * 2 + curr * 2 - 1].data = 0;
      nodes[j * 2 + curr * 2 - 1].before = &nodes[j + curr - 1];
      nodes[j * 2 + curr * 2].data = 1;
      nodes[j * 2 + curr * 2].before = &nodes[j + curr - 1];
    }

    curr = curr * 2;
  }

  for (int i = 0; i < curr; i++) {
    Node* node = &nodes[curr - 1 + i];
    while (node != NULL) {
      printf("%d ", node->data);
      node = node->before;
    }
    printf("\n");
  }
}
