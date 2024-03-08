#Nguyen Hai Dang - 20120049 - Chieu T3 - Ca 1
#Bai0.1.1
x=sample(0:10 , 40, replace = TRUE);x

Kyvong <- function(x) {
 Tong = 0;n=length(x)
 for (i in 1:length(x)) {
  Tong = Tong + (1/n)*x[i]
 }
 return (Tong)
}


Phuongsai <- function(x,TB) {
 Tong = 0;n=length(x)
 for (i in 1:length(x)) {
  Tong = Tong + (1/(n-1))*((x[i] - TB)^2)
 }
 return (Tong)
}
k <- Kyvong(x); k
p <- Phuongsai(x,k);p

#Bai0.1.2

sixes <- function(n) {
 x = sample(1:6,n,replace=TRUE)
 d <- which(x == 6)
 if(length(d)>0)
  result <-"TRUE"
 else
  result <- "FALSE"
 return(result)
}

play <- function(n,N) {
 dem = 0
 for(i in 1:N)
  if(sixes(n) == "TRUE")
   dem = dem + 1
  p = dem/N
 return(p)
}
sixes(5)
play(5,20)
n=5
x <- sample(1:6,n,replace=TRUE)
x

#Tinh xac suat roi rac P(X=k)

k <- 0:8
p <- function(k) choose(8,k)*0.3^k*0.7^(8-k)
p(k)
sum(p(k))

#Tinh xac suat lien tuc

f <- function(x, mu=0, sigma = 1) {
 1/sqrt(2*pi*sigma^2)*exp(-(x - mu)^2/(2*sigma^2))
}
integrate(function(x) f(x,0,1), lower = -Inf, upper = Inf)
f(0)
plot(k, p(k), type = "h", xlab="k", ylab = "P(X=k)", main = "Ham xac suat cua bnn X")
curve(f(x,0,1), from = -3, to = 3, xlab = "x", ylab = "f(x)", main = "Ham mat doc cua bnn X")