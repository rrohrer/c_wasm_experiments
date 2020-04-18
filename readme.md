# System setup notes:

1) `brew install llvm`
2) `alias cl=/usr/local/opt/llvm/bin/clang`

Now you can run: `cl --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -o add.wasm add.c`
which will make a wasm binary.

Test it out with `python -m SimpleHTTPServer 8080` and navigating to `localhost:8080/index.html` in your browser.
