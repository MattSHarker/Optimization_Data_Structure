# create a name for the result's base directory based off
    # the time it was ran at
DATE=$(date +%Y-%m-%d-%H-%M)

# remove the directory if it exists to prevent writing to existant files
rm -rf results/$DATE

# create the data directories
mkdir -p results/$DATE/data
mkdir -p results/$DATE/fitness
mkdir -p results/$DATE/time
mkdir -p results/$DATE/function_calls


# run the optimization
./.build/dataset.out $DATE

# create a directory for the analysis
mkdir -p results/$DATE/analysis

# analyze the data
python3 ./src/analyze.py $DATE
