#include "mergeplot.C"
void runall(){
    //iseta, isbk, iseff, isppsub

mergeplot(0,0,0,0);
mergeplot(0,1,0,0);
mergeplot(0,0,1,0);
mergeplot(0,1,1,0);

mergeplot(1,0,0,0);
mergeplot(1,1,0,0);
mergeplot(1,0,1,0);
mergeplot(1,1,1,0);

mergeplot(0,0,0,1);
mergeplot(0,1,0,1);
mergeplot(0,0,1,1);
mergeplot(0,1,1,1);

mergeplot(1,0,0,1);
mergeplot(1,1,0,1);
mergeplot(1,0,1,1);
mergeplot(1,1,1,1);

}