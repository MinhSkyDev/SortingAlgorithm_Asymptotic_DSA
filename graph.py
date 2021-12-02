import numpy as np
import pandas as pd
from matplotlib import pyplot as plt



randomData = pd.read_csv("RandomData.csv",delimiter=",")
print(randomData)
plt.figure()
plt.title("Dữ liệu phân tán tăng dần")
##selectionSort = randomData['selectionSort']
##insertionSort = randomData['insertionSort']
##bubbleSort = randomData['bubbleSort']
quickSort = randomData['quickSort']
mergeSort = randomData['mergeSort']
heapSort = randomData['heapSort']
dataSize = randomData['Dataset']
##plt.plot(dataSize,selectionSort,'r',label ="selectionSort")
##plt.plot(dataSize,insertionSort,'b',label ="insertionSort")
plt.plot(dataSize,quickSort,'g',label = "quickSort")
plt.plot(dataSize,mergeSort,'c',label = "mergeSort")
##plt.plot(dataSize,bubbleSort,'m',label = "bubbleSort")
plt.plot(dataSize,heapSort,'k',label = "heapSort")
plt.legend(loc="upper left")
plt.show()
