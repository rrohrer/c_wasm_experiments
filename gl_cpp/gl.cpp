#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000

extern "C" {
void glViewport(int x, int y, int width, int height);
void glClearColor(float r, float g, float b, float a);
void glClear(unsigned int);
}

void init_engine() { glViewport(0, 0, 280, 210); }

void update_game() {
  // do things
}

void update_renderer() {
  glClearColor(0.f, 1.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT);
}
