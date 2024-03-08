clear all; clc;

syms x;
n = 4;p = 2; q = 1;
P = Legendre(n,x)

% Doi da thuc Chebyshev da cho thanh: T(n,x)=2*x*T(n-1,x)-T(n-2,x)
T = Chebyshev(n,x)

% Doi day so Lucas da cho thanh: L(n) = p*L(n-1)-q*L(n-2)
L = Lucas(n,p,q)

