/usr/local/opt/llvm/bin/clang++ -std=c++17 \
  -nostdinc++ -nostdlib++ -nostdlib \
  -O3 \
  -flto \
  --target=wasm32 \
  -Wl,--no-entry \
  -Wl,--export-all \
  -Wl,--lto-O3 \
  -Wl,-allow-undefined-file wasm.syms \
  -o gl.wasm \
  gl.cpp
