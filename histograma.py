import pandas as pd
import matplotlib.pyplot as plt

for i in ("10", "50", "100", "500", "1000"):
    df2 = pd.read_csv(i + ".txt", sep=",", header=None)

    dim10 = df2.T.squeeze()

    # Graficar un histograma
    plt.hist(dim10, bins=25, color="#607c8e", rwidth=0.9)
    plt.title("Distancia entre puntos con dimensión " + i)
    plt.xlabel("Distancia")
    plt.ylabel("Frecuencia")
    plt.grid(True)

    plt.show()

