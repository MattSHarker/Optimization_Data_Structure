# remove the test directory if it exists (removes existing files)
rm -rf results/test

# recreate the test directory
mkdir -p results/test/data
mkdir -p results/test/fitness
mkdir -p results/test/time
mkdir -p results/test/function_calls

# run the optimization
./.build/dataset.out "test"

# make a directory for the analysis files
mkdir -p results/test/analysis

# analyze the data
python3 ./src/analyze.py "test"
