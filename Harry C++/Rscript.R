pedro <- 1:4
bella <- 5:8

lastOfUs <- list(pedro, bella, pedro * 2, bella * 3)
lastOfUs

cat("After finding the average of each element of the list", "\n")
sapply(lastOfUs, mean)

pedro <- 1:4
bella <- 5:8

lastOfUs <- list(pedro, bella, pedro * 2, bella * 3)
lastOfUs

cat("After finding the average of fourth element of the list", "\n")
mean(lastOfUs[[4]])

df <- data.frame(a1 = 1:3, a2 = 4:6, a3 = 7:9)
df
cat("The average of the a2 column is", "\n")
mean(df$a2)