# TH XSTK Bai 3: Bien ngau nhien (Tuan 3-4)

# Vi du 1 a
# Tao vec to k có gia tri tu 0 den 8
k = 0:8
# Viet ham xac suat
p <- function(k) choose(8,k) * 0.3^k * 0.7^(8-k)
# Tinh gia tri xac suat P(X = k), k = 0,1,...,8
p(k)

# Kiem tra tong cac xac suat bang 1
sum(p(k))


# Vi du 1 b
# Viet ham mat do cua bien ngau nhien X ~ N(mu = 0,sigma^2 = 1)
f <- function(x, mu=0, sigma=1){
  1/sqrt(2*pi*sigma^2) * exp(-(x-mu)^2/(2*sigma^2))
}

# Kiem tra tich phan bang 1
integrate(function(x) f(x,0,1),lower=-Inf,upper=Inf)

# Tinh f(0)
f(0)


# Vi du 2 a
# Ve ham xac suat o vi du 1a
plot(k, p(k), type = "h", xlab = "k", ylab = "P(X = k)", main = "Ham xac suat cua bnn X")

# Vi du 2 b
# Ve ham mat do xac suat o vi du 1b
curve(f(x,0,1),from=-3,to=3, xlab = "x", ylab = "fX(x)", main = "Ham mat do cua bnn X")

#vi du 3 a
#Viet ham pp xac suat cua bien nn x
F <- function(x) sum(p(0:x))
F(4)
#Vector hoa ham vua viet
F <- Vectorize(F)
F(0:2)
F(k)

#vi du 3 b
# Viet ham pp xac suat
F2 <- function(a, mu = 0, sigma = 1) {
  integrate(function(x) f(x, mu, sigma), lower = -Inf,  upper = a)$value
}
#Vector hoa ham
F2 = Vectorize(F2)
F2(1.96)
plot(stepfun(k, c(0, F(k))), ylab = "FX(x)", main = "cdf of X")
curve(F2(x), from = -3, to = 3, ylab = "FX(x)", main = "cdf of X")
K <- k[F(k) >= 0.25]
K[1]

#Bai 1

f1 <- function(x) {0.07*x^(-0.93)}
F1 <- integrate(function(x) f1(x), lower = 0, upper = 0.2)$value
F2 <- integrate(function(x) f1(x), lower = 0, upper = 1)$value
F1
F2

#Bai 2
x <- sample(1:5,100,TRUE,c(0.1,0.2,0.4,0.2,0.1))
x

#Thong ke du lieu
table(x)/length(x)
hist(x, main = "Histogram")