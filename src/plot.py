import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    noise_data = np.loadtxt("../data/noise_cosine.txt")
    gt_data = np.loadtxt("../data/cosine.txt")
    fit_data = np.loadtxt("./fit.txt")
    x = np.linspace(-3 * np.pi, 3 * np.pi, 200)
    plt.plot(x, fit_data, "x", label="fit")
    plt.plot(x, gt_data, label="solution")
    plt.scatter(x, noise_data, label="input")
    plt.legend()
    plt.savefig("./denoise_cos.png", dpi=600, bbox_inches="tight")
    plt.close()