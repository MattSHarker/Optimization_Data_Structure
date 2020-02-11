# exit on failure
set -e

# create the build directory and move to it
mkdir -p .build
cd .build

# build the project
cmake -DCMAKE_BUILD_TYPE=Release ../
make

echo Project has been sucessfully built
