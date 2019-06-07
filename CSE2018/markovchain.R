library(markovchain)

transMat <- rbind(c(0.1, 0.3, 0.6), c(0.3, 0.3, 0.4), c(0.4, 0.5, 0.1))
states <- c('playing', 'crying', 'sleeping')
rownames(transMat) <- colnames(transMat) <- states
print(transMat)

mcBaby <- new("markovchain", states = states, transitionMatrix = transMat, name = "Baby")
print(transitionProbability(mcBaby, 'crying', 'sleeping'))

show(mcBaby)

print('After 25 trials')
print(mcBaby ^ 25)

library(igraph)
plot(mcBaby)

initialState = c(1,0,0)
print(initialState * mcBaby ^ 25)

