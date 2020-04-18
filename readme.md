# System setup notes:

1) `brew install llvm`
2) `alias cl=/usr/local/opt/llvm/bin/clang`

Now you can run: `cl -O3 -flto --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--lto-O3 -Wl,-allow-undefined-file wasm.syms -o add.wasm add.c`
which will make a wasm binary.

Test it out with `python -m SimpleHTTPServer 8080` and navigating to `localhost:8080/index.html` in your browser.

# Todo:
- Check out Doug Lea's malloc: http://gee.cs.oswego.edu/pub/misc/malloc.c

