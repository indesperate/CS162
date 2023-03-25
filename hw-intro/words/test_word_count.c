#include "word_count.h"
#include <stdbool.h>
#include <stdio.h>
static bool wordcount_less(const WordCount *wc1, const WordCount *wc2) {
  if (!wc1) {
    return false;
  }
  if (!wc2) {
    return true;
  }
  if (wc1->count == wc2->count) {
    return strcmp(wc1->word, wc2->word) < 0;
  } else {
    return wc1->count < wc2->count;
  }
}
int main() {
    WordCount *head = NULL;
    init_words(&head);
    add_word(&head, "some");
    add_word(&head, "test");
    add_word(&head, "string");
    add_word(&head, "string");
    add_word(&head, "string");
    fprint_words(head, stdout);
    printf("%lu\n",len_words(head));
    wordcount_sort(&(head), wordcount_less);
    fprint_words(head, stdout);
    printf("%lu\n",len_words(head));
}