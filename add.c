// this function is defined in js!
void print_num(int num);

// this constant is from the webassembly spec
const unsigned long PAGE_SIZE = 65536;

// a very silly malloc
extern unsigned char __heap_base;
static unsigned long silly_heap = (unsigned long)&__heap_base;

void *malloc(unsigned long size) {
  // get the current size of the heap.
  unsigned int heap_size = __builtin_wasm_memory_size(0) * PAGE_SIZE;
  unsigned int remaining_heap = heap_size - silly_heap;

  // grow if heap is too small.
  if (remaining_heap < size) {
    unsigned int allocate_size = (size - remaining_heap) / PAGE_SIZE + 1;
    __builtin_wasm_memory_grow(0, allocate_size);
  }

  // dish out the remaining memory
  unsigned int memory = silly_heap;
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
