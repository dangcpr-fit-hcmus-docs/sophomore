#Bai1
x <- c(1,2,5,7,-3,0,5,1,5,6)
y <- c(2,2,0,-5,7,8,11,9,3,2)
x+y
x-y
x*y
x[x%%2==0]
y[y%%2==1]
g <- c(x,y)
g[g>0]
mean(x)
mean(y)
sd(x)
sd(y)
min(x)
min(y)
max(x)
max(y)
sort(x,FALSE)
sort(y,TRUE)
save(x,file='varx.rda');save(y,file='vary.rda')

#Bai2
data1 <- read.csv('data01.csv',header=TRUE)
attach(data1); names(data1)
data1
#a.
#TB
mean(FPSA); mean(TPSA);
#Phuong sai
var(FPSA); var(TPSA)
#Trung vi
median(FPSA); median(TPSA)

#b.
#Bieu do dang duong
plot(FPSA,type='l')
plot(TPSA,type='l')
#Bieu do dang boxplot
boxplot(FPSA)
boxplot(TPSA)

#c. Tach nhung gia tri cua FPSA có k=0 và k-1
fpsa0 <- subset(FPSA,K==0);fpsa0
fpsa1 <- subset(FPSA,K==1);fpsa1
#Doc du lieu tu file "data02.csv" vao R va gan vao bien data2
data2 <- read.csv('data02.csv',header=T)
names(data2)
data2
#Ghep 2 data lai theo k
data <- data.frame(data1[1:3],data2);data
#Tao bien tPSA theo yeu cau de bai
tPSA <- Age
tPSA[Age<=60] <- 0
tPSA[Age > 60 & Age <=70] <- 1
tPSA[Age > 70] <-2
#Gan tPSA vao data
d <- data.frame(tPSA,Age);d
data <- data.frame(data,tPSA);data

#Bai 3
#a. Nhap cac so lieu va gan vao bien tuong ung, 3 cach
sv <- 1:10
q1 <- c(3,3,3,4,3,4,3,4,3,4)
q2 <- c(5,3,5,5,2,2,5,5,4,2)
q3 <- c(1,3,1,1,1,3,1,1,1,1)
dat1 <- data.frame(sv,q1,q2,q3);dat1
#b. Tao bang ket qua rieng cho cau hoi 1,2
tab1 <- table(q1);tab1
tab2 <- table(q2);tab2
tab3 <- table(q3);tab3
par(mfrow=c(1,3))
#c. Ve bieu do bar cho 3 cau hoi
barplot(tab1); barplot(tab2); barplot(tab3)

par(mfrow=c(2,1))
#d. Ve bieu do bar dang nham ngang cho cau hoi 2,3
barplot(tab2,horiz=T)
barplot(tab3,horiz=T)
