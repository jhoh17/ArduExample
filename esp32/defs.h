// defs.h
#define sbi(X, N)  (X |=  (1<<N))
#define cbi(X, N)  (X &= ~(1<<N))
#define tbi(X, N)  (X ^= (1<<N))
#define gbi(X, N)  (X >> i)&1 
