# create a time for the result's base directory
DATE=$(date +%Y-%m-%d-%H-%M)
echo "DATE: $DATE"

mkdir -p results/$DATE/data
mkdir -p results/$DATE/fitness
mkdir -p results/$DATE/time

./.build/dataset.out $DATE
