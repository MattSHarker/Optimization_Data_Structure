import csv          # for csv files
import statistics   # for statistical functions
import sys          # for argv
import os
from decimal import Decimal

# get the current path and move it to the results directory
os.chdir(os.path.dirname(__file__))
path = os.getcwd() + "/../results/"

# add the specific subdirectory to the path
if len(sys.argv) == 1:
    path += "default"
else:
    path += sys.argv[1]


# open dataset parameter file to get dimensions
dims = 0
with open("../parameters/dataset.txt") as file:
    dims    = int(file.readline().strip())  # strip() to remove the newline
    popSize = int(file.readline().strip())


# analyze the iteration time file
# stats: min, max, range, total(sum), mean, median, stdev
# rows: 1

# create list for data
iter_stats = [[] for i in range(2)]
iter_stats[0].extend(["minimum", "maximum", "range", "total", "mean", "median", "stdev"])

# open the data file
print("Writing iteration_time.csv")
with open(path + "/time/iteration_time.csv") as csvfile:
    timeCSV = csv.reader(csvfile, delimiter=',')
    
    # read in the iteration times
    times = []
    for row in timeCSV:
        times.append(Decimal(row[1].strip())) # add times to a temp list
    
    # analyze the iteration times
    iter_stats[1].append(min(times))
    iter_stats[1].append(max(times))
    iter_stats[1].append(max(times) - min(times))
    iter_stats[1].append(sum(times))
    iter_stats[1].append(statistics.mean(times))
    iter_stats[1].append(statistics.median(times))
    iter_stats[1].append(statistics.stdev(times))

# create time stats file and write to it
with open(path + "/analysis/iteration_time_stats.csv", 'w', newline='') as csvfile:
    filewriter = csv.writer(csvfile, delimiter=',')
    filewriter.writerows(iter_stats)
print("iteration_time_stats.csv has been written\n")



# analyze the fitness file
# stats: min, max, range, mean, median, stdev
# rows: iterations
print("Writing fitness_stats.csv")


with open(path + "/fitness/fitness.csv", "r") as csvfile:
    fitnessCSV = csv.reader(csvfile, delimiter=',')

    # list of lists to hold all information
    fitness_stats = [[]]
    fitness_stats[0].extend(["iteration", "minimum", "maximum", "range", "mean", "median", "stdev"])

    # for each row in the file
    for row in fitnessCSV:
        # create lists to hold data
        fitness = []
        stats = []

        # record the data (skip the first one)
        for fit in row[1:]:
            fitness.append(Decimal(fit))
        
        # add the stats to the stats list
        stats.append(row[0])    # iteration
        stats.append(min(fitness))
        stats.append(max(fitness))
        stats.append(max(fitness) - min(fitness))
        stats.append(statistics.mean(fitness))
        stats.append(statistics.median(fitness))
        stats.append(statistics.stdev(fitness))

        # append the stats list to the proper list of lists
        fitness_stats.append(stats)

# write the fitness stats
with open(path + "/analysis/fitness_stats.csv", 'w', newline='') as csvfile:
    filewriter = csv.writer(csvfile, delimiter=',')
    filewriter.writerows(fitness_stats)
print("fitness_stats.csv has been written\n")



# analyze the raw data
# stdev per column
# rows: iterations
# cols: dimensions

print("Writing raw_data_stdev.csv")

# for each file in results/bla/data
iterations = 30
# for each file

for i in range(iterations):

    # list to hold standard deviations
    stdev = []

    #open the file
    with open(path + "/data/raw_data-" + str(i+1) + ".csv", "r") as csvfile:
        dataCSV = csv.reader(csvfile, delimiter=',')

        fullData = []
        # for each row in the file
        for row in dataCSV:
            # for each value in the row
            data = []

            for val in row:
                data.append(Decimal(val))
            
            fullData.append(data)

        # analyze each column (zip transposes cols to rows)
        stdev.append(str(i+1))
        for row in zip(*fullData):
            stdev.append(statistics.stdev(row))
        
    # append to raw_data_stdev.csv
    with open(path + "/analysis/raw_data_stdev.csv", "a+") as csvfile:
        writer = csv.writer(csvfile)
        # create the header if it's the first line
        if i == 0:
            header = "iteration"
            for j in range(dims):
                header += ",dim-" + str(j+1)
            
            csvfile.write(header+'\n')

        # write the data 
        writer.writerow(stdev)

print("raw_data_stdev.csv have been written\n")


# analyze the raw data standard deviations
# stats: min, max, range, mean, median, stdev
# rows: dimensions

# open the new stdev file to analyze it
print("Writing rd_stdev_stats.csv")
with open(path + "/analysis/raw_data_stdev.csv", "r") as csvfile:
    stdevStatsCSV = csv.reader(csvfile, delimiter=',')

    # read the file into lists
    stdev = []
    stats = []

    csvfile.readline()  # skip first line
    for row in stdevStatsCSV:
        temp = []

        # add each stdev
        for val in row[1:]:
            temp.append(Decimal(val))

        stdev.append(temp)
    

    # analyze each column (transposed into rows)
    ctr=1   
    for row in zip(*stdev):
        temp = [ctr] # iterations
        temp.append(min(row))
        temp.append(max(row))
        temp.append(max(row) - min(row))
        temp.append(statistics.mean(row))
        temp.append(statistics.median(row))
        temp.append(statistics.stdev(row))
        
        # add temp stats list to full stats list 
        stats.append(temp)

        # incriment counter
        ctr+=1

    # create the stdev stats file
    with open(path + "/analysis/rd_stdev_stats.csv", "w") as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        csvfile.write("dimension,minimum,maximum,range,mean,median,stdev\n")
        writer.writerows(stats)

print("rd_stdev_stats.csv has been written")
