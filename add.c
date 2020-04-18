// this function is defined in js!
void print_num(int num);

// also defined in js!
const unsigned long PAGE_SIZE = 65536;

// a very silly malloc
extern unsigned char __heap_base;
static unsigned long silly_heap = (unsigned long)&__heap_base;

void *malloc(unsigned long size) {
  unsigned int memory = silly_heap;
  // hack to get around initial heap size.
  __builtin_wasm_memory_grow(0, 10);

  silly_heap += size;
  return (void *)memory;
}

// lol
void free(void *p) {}

// tests calling basic functions from js
int add(int a, int b) {
  print_num(a);
  print_num(b);
  return a + b;
}

// tests out malloc by printing numbers up to N
void print_up_to(int n) {
  int *p = malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    print_num(p[i]);
  }
  free(p);
}
