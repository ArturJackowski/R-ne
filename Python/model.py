import numpy as np
import matplotlib.pyplot as plt
import io


def zmienne(x, y):
    k = np.size(x)
    l_x, l_y = np.mean(x), np.mean(y)
    SS_xy = np.sum(y * x) - k * l_y * l_x
    SS_xx = np.sum(x * x) - k * l_x * l_x
    b_1 = SS_xy / SS_xx
    b_0 = l_y - b_1 * l_x
    return (b_0, b_1)


def linia_reg(x, y, b):
    plt.scatter(x, y, color="r",
                marker="o", s=30)

    y_pred = b[0] + b[1] * x
    plt.plot(x, y_pred, color="k")
    plt.xlabel('x')
    plt.ylabel('y')
    plt.savefig('static/images/Figure.jpg')


def rysuj():
    x = np.array([0, 1, 2, 2, 3, 5, 7,7, 8, 9])
    y = np.array([1,1 ,4, 6, 7,8 ,9 , 10, 11,13 ])
    b = zmienne(x, y)
    print("Zmienne:\nb_0 = {} \nb_1 = {}".format(b[0], b[1]))
    linia_reg(x, y, b)
    return plt.savefig('image.jpg')



if __name__ == '__main__':
    rysuj()
