wek=sample(1:50,10)
wek2=sample(1:30,2)
wek3=sample(1:30,15)
naj3<-function(x){
  if(3>length(x)){
     sprintf("Argument jest za krótki")}
  else{
  print(sort(unique(x), decreasing = FALSE)[1:3])
  print(sort(unique(x), decreasing = TRUE)[1:3])}
}

naj3(wek)
naj3(wek2)
naj3(wek3)