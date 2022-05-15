import numpy as np
import pandas as pd
from plotly.subplots import make_subplots
from plotly import graph_objs as go
import math; 

algorithmTypes = ['linearSearch', 'binarySearch', 'bubbleSort', 'insertSort', 'quickSort']
arrayTypes = ['sorted', 'sortedInReverse', 'randomOrder'] 

df = pd.read_csv('results.csv')

slownik = {
  "sorted": "posortowane",
  "sortedInReverse": "odwrotnie posortowane", 
  "randomOrder": "losowy ciag"
}

count = {
    "linearSearch": 0, 
    "binarySearch": 0, 
    "bubbleSort": 0, 
    "insertSort": 0, 
    "quickSort": 0, 
  }

def algorytmZlozonosc(algorytm, currentSorted):
  switch = {
    "linearSearch": go.Scatter(x=currentSorted["n"], y=currentSorted["n"], name="f(x) = n", line_shape="linear"), 
    "binarySearch": go.Scatter(x=currentSorted["n"], y=np.log(currentSorted["n"]), name="f(x) = log n", line_shape="linear"), 
    "bubbleSort": go.Scatter(x=currentSorted["n"], y=currentSorted["n"]*currentSorted["n"], name="f(x) = n^2", line_shape="spline"), 
    "insertSort": go.Scatter(x=currentSorted["n"], y=currentSorted["n"]*currentSorted["n"], name="f(x) = n^2", line_shape="spline"), 
    "quickSort": go.Scatter(x=currentSorted["n"], y=currentSorted["n"]*np.log10(currentSorted["n"]), name="f(x) = n * log(n)", line_shape="spline"), 
  }
  count[algorytm] += 1 
  return switch.get(algorytm)

def algorytmEmpirycznie(algorytm, currentSorted):
  switch = {
    "linearSearch": go.Scatter(x=currentSorted["n"], y=currentSorted["dominantOps"], name=f"Dane: {slownik[arrayType]}", line_shape="linear"), 
    "binarySearch": go.Scatter(x=currentSorted["n"], y=currentSorted["dominantOps"], name=f"Dane: {slownik[arrayType]}", line_shape="linear"), 
    "bubbleSort": go.Scatter(x=currentSorted["n"], y=currentSorted["dominantOps"], name=f"Dane: {slownik[arrayType]}", line_shape="spline"),
    "insertSort": go.Scatter(x=currentSorted["n"], y=currentSorted["dominantOps"], name=f"Dane: {slownik[arrayType]}", line_shape="spline"), 
    "quickSort": go.Scatter(x=currentSorted["n"], y=currentSorted["dominantOps"], name=f"Dane: {slownik[arrayType]}", line_shape="spline")
  }
  return switch.get(algorytm) 

for algorithmType in algorithmTypes:
  current = df[df["algorithm"] == algorithmType]
  calosc = make_subplots(x_title="n - rozmiar zadania", y_title="Operacje dominujace dla danego rozmiaru zadania")
  for arrayType in arrayTypes: 
    currentSorted = current[current["arrType"] == arrayType]
    trace = algorytmEmpirycznie(algorithmType, currentSorted)
    calosc.add_trace(trace)
  if (count[algorithmType] == 0):
      trace2 = algorytmZlozonosc(algorithmType, currentSorted)
      calosc.add_trace(trace2)
      if(algorithmType == "insertSort"):
        trace3 = go.Scatter(x=currentSorted["n"], y=currentSorted["n"], name=f"f(x) = n", line_shape="spline")
        calosc.add_trace(trace3)
  if (algorithmType == "binarySearch" or algorithmType == "linearSearch"):
    calosc.update_layout(title_text=f"Algorytm {algorithmType}", yaxis_range=[0, 100])
  else:
    calosc.update_layout(title_text=f"Algorytm {algorithmType}")
  calosc.show()









