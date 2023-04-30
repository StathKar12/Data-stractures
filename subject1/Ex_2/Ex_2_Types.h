typedef char AirportCode[10];
typedef int (*CompareType)(AirportCode a,AirportCode b);

typedef struct point* stp;
typedef struct point {
  AirportCode air;
  stp next ;
  stp previous;
}str ;
typedef struct fake{
  stp first;
  stp last;
} dms;
