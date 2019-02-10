swap <- function(vec, a, b) {
    d <- vec[a]
    vec[a] <- vec[b]
    vec[b] <- d
    return(vec)
}

partition <- function(vec, l, h) {
    pivot <- l
    vec <- swap(vec, pivot, h)
    for(i in seq(l, h)) {
        if(vec[i] <= vec[h]) {
            vec <- swap(vec, i, l)
            l <- l + 1
        }
    }
    vec <- swap(vec, l, h)
    return(list(l, vec))
}

quicksort <- function(vec, l, h) {
    if(l < h) {
        out <- partition(vec, l, h)
        pivot <- out[[1]]

        vec <- out[[2]]
        vec <- quicksort(vec, l, pivot - 1)
        vec <- quicksort(vec, pivot + 1, h)
    }
    return(vec)
}