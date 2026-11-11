rm -rf wasm-bin
#!/bin/bash

git submodule init
git submodule update
mkdir -p plot
cp fcpp/src/extras/plotter/plot.asy plot/
fcpp/src/make.sh "$@"

# emscripten
echo "Emscripten Build configuration"
emcmake cmake -S ./ -B ./wasm-bin -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DFCPP_BUILD_GL=ON
echo "Emscripten compilation"
cmake --build ./wasm-bin/ -j 12 --target spreading_collection_gui

# to run it in a browser (temporary solution): 
emrun --browser iexplore wasm-bin/run/spreading_collection_gui.html