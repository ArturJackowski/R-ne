wektor1 = c(seq(1, 20, by=3))
wektor2 = c(seq(19, 1, by=-3))
wektor3 = c(seq(10, 22, by=2))
wektor4 = c(wektor1[1]*2-8,wektor1[2]*2-8,wektor1[3]*2-8,1:4)
macierz = matrix(0,7,4)
macierz = cbind(wektor1,wektor2,wektor3,wektor4)
wiersze = c()

Max = function(macierz){
  a = 1
  for(i in 1:4){
    for(j in a:28){
      if((apply(macierz,2,max)[i]) == (macierz[j])){
        while(j>7) j = j-7
        wiersze = c(wiersze,c(j))
        a = j+1
        break;
      }
    }
  }
  
  cat('Wiersze z maksymalna wartością to: ')
  cat(wiersze)
}

Max(macierz)

