A<-sample(c(letters, LETTERS), 20, F)
B<-lapply(A, toupper)


utwórz<-function(x,y) {
  wektor = c()
  for(i in 1:20) {
    if(x[i] == y[i]) {
      wektor = c(wektor,0)
    }
    if(x[i] != y[i]) {
      wektor = c(wektor,1)
    }
  }
  cat(sum(wektor))
}

C<-sapply(A, function(x) as.numeric(!x %in% B))

sum(C)

D = as.vector(C)