# hours in leap year
leapYearHours <- 24 * 366
print(leapYearHours)

# hours in a year
yearHours <- 24 * 365
print(yearHours)

# volume of rod
radius = 20
height = 30
volume = pi * radius * radius * height
print(volume)

# value of light year
secondsInAYear = yearHours * 3600
speedOfLight = 3e8
lightYear = speedOfLight * secondsInAYear
print(paste(as.character(lightYear),  "m"))

# km to m
km <- 8.198
print(km * 1000)

# square root of 81
sqrt(81)

# vector of unicode values
vec <- utf8ToInt("HELLO")

# approx time since Unix epoch
# assuming all years have 365 days
yearsSinceEpoch = 2019 - 1970
print(yearsSinceEpoch * secondsInAYear * 1000)
