import numpy as np
import pandas as pd
import numpy as np
from scipy.stats import rankdata
from tabulate import tabulate


def main():
    import sys
    import pandas as pd
   
    dataset = pd.read_csv(sys.argv[1]).values  # importing the dataset
    datasetwithheaing = pd.read_csv(sys.argv[1],index_col=False)
    decisionMatrix = dataset[:, 1:]  # dropping first column
    weights = [int(i) for i in sys.argv[2].split(',')]  # initalizing weights array
    impacts = sys.argv[3].split(',')  # initalizing impacts array
    name = sys.argv[4]
    topsis(datasetwithheaing,dataset,decisionMatrix, weights, impacts,name)


def topsis(datasetwithheaing,dataset,decisionMatrix, weights, impacts,name):
    def topsis(datasetwithheaing, dataset, decisionMatrix, weights, impacts, name):
        """
        it will take dataset from the main function perform necessary actions to calculate
        rank as well as TOPOSIS score.
        parameters : datasetwithheading from CSV file input,
                     dataset : CSV input with column indexing
                     decisionMatrix: Only values from the CSV input file
                     weights : the input weights fom CMD
                     impacts : the input impacts from CMD
                     name : the result as csv file
        return :    The CSV file containg the desired output
        """
    r, c = decisionMatrix.shape
    if len(weights) != c:
        return print("ERROR! length of 'weights' is not equal to number of columns")
    if len(impacts) != c:
        return print("ERROR! length of 'impacts' is not equal to number of columns")
    if not all(i > 0 for i in weights):
        return print("ERROR! weights must be positive numbers")
    if not all(i == "+" or i == "-" for i in impacts):
        return print("ERROR! impacts must be a character vector of '+' and '-' signs")

    data = np.zeros([r + 2, c + 4])
    s = sum(weights)

    for i in range(c):
        for j in range(r):
            data[j, i] = (decisionMatrix[j, i] / np.sqrt(sum(decisionMatrix[:, i] ** 2))) * weights[i] / s

    for i in range(c):
        data[r, i] = max(data[:r, i])
        data[r + 1, i] = min(data[:r, i])
        if impacts[i] == "-":
            data[r, i], data[r + 1, i] = data[r + 1, i], data[r, i]

    for i in range(r):
        data[i, c] = np.sqrt(sum((data[r, :c] - data[i, :c]) ** 2))
        data[i, c + 1] = np.sqrt(sum((data[r + 1, :c] - data[i, :c]) ** 2))
        data[i, c + 2] = data[i, c + 1] / (data[i, c] + data[i, c + 1])

    data[:r, c + 3] = len(data[:r, c + 2]) - rankdata(data[:r, c + 2]).astype(int) + 1
    import pandas as pd
    l = data[:5, c + 2]
    m = data[:5, c + 3]
    df = pd.DataFrame(datasetwithheaing)
    df['Topsis Score']=l
    df['Rank']=m
    df.to_csv(name)


    print(df)


if __name__ == "__main__":
    main()
