/usr/local/opt/llvm/bin/clang -O3 -flto --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--lto-O3 -Wl,-allow-undefined-file wasm.syms -o add.wasm add.c
