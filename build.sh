# exit on failure
set -e

# create the results directories
mkdir -p results
mkdir -p results/data
mkdir -p results/fitness

# create the build directory and move to it
mkdir -p build
cd build

# build the project
cmake -DCMAKE_BUILD_TYPE=Release ../
make


echo Project has been sucessfully built
