import numpy as np
from typeguard import typechecked

@typechecked
def kmeans(X: np.ndarray, k: int, n_iter: int=10) -> (np.ndarray, np.ndarray):
    """Performs k-Means clustering algorithm on a set of input data.
    The clustering algorithm is run for a total of `n_iter` number of iterations
    and the `k` centroids are initially randomly selected from the input 
    data points `X`.

    Args:
        X: A `numpy.ndarray` automatically casted to dtype `np.float32`
            that should necessarily be a 2D array of shape (m, nd).
        k: The number of clusters.
        n_iter: The number of iterations that the algorithm will be run for.

    Returns:
        centroids, clusters: A tuple of two `numpy.ndarray`(s) one containing
            centroids after clustering is performed and the predicted cluster
            for each data point in `X`.

    """
    assert X.ndim == 2, "Training data X must be represented as 2D array only"

    X = np.array(X, dtype=np.float32)
    m = X.shape[0]

    random_select = np.random.permutation(m)[:k]
    init_centroids = X[random_select]

    centroids = init_centroids
    for _ in range(n_iter):
        squared_diffs = np.square(X[None, :, :] - centroids[:, None, :])
        euclidean_dists = np.sum(squared_diffs, axis=-1) ** 0.5
        clusters = np.argmin(euclidean_dists, axis=0)

        selector = np.arange(k)[:, None] == clusters[None, :]
        centroids = np.zeros_like(centroids, dtype=np.float32)
        for c in range(k):
            select = selector[c]
            points = X[select]
            mean_points = np.mean(points, axis=0)
            centroids[c] = mean_points

    return centroids, clusters
