Dem <- function(x) {
dem = 0
n <- length(x)
for(i in 1:n)
	if(x[i] > 3) dem = dem + 1
return (dem)
}
x <- sort(sample(1:50,5))

#Bai 2
TongTichLuy <- function(x,i) {
Tong = 0
n <- 40

for (k in 1:i)
	Tong = Tong + x[k]
return (Tong)
}
n<-40
x <- round(runif(n,0,10),2)
x
TongTichLuy(x,3)
rm(list=ls(all=TRUE)) #Xoa bien cua bai truoc
#Bai 3
cal.vol<-function() {
 r <- 3:20
 v <- round(4*pi*r^3/3,3)
 d <- data.frame(Radius = r, Volume = v)
}
ans <- cal.vol(); ans

#Bai 4
data01<-read.csv("data01.csv", header = TRUE)
attach(data01)
names(data01)
data01
#Tao bien va gan gia tri
n <- length(Age)
Index <- numeric(n)
for(i in 1:n) {
 if (Age[i] <= 60) {Index[i] <- 0}
 else{
  if (Age[i] <= 70) {Index[i] <-1}
  else {
   if (Age[i] <= 80) {Index[i] <-2}
   else {
    Index[i]<-3
   }
  }
 }
}
ans <- data.frame(Age,Index);ans

#Bai5
data11<-read.csv("data11.csv",header=T)
names(data11)
attach(data11)
data11
inf.plant <- function(d){
 y <- (a+b)/2
 x <- rep(y,n)
 m <- min(x)
 M <- max(x)
 x.bar = mean(x)
 x <- var(x)
 dat <- data.frame(Min = m, Max = M, Mean = x.bar, Var=s)
 rownames(data)=c(" ")
 return(dat)
}
inf.plant(data)
