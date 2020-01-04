# create a time for the result's base directory
DATE=$(date +%Y-%m-%d-%H-%M)
echo "DATE: $DATE"

./build/dataset.out $DATE
