#ifndef _COMPLEXO_
#define _COMPLEXO_

typedef struct cmp Complexo;
Complexo* cria_complexo(float a, float b);
void libera_complexo(Complexo* cmp);
float pega_valores(Complexo* cmp, float *a, float *b);
float seta_valores(Complexo* cmp, float a, float b);
Complexo* soma_complexos(Complexo* cmp, Complexo* cmp2);
Complexo* sub_complexos(Complexo* cmp, Complexo* cmp2);
Complexo* mult_complexos(Complexo* cmp, Complexo* cmp2);
Complexo* div_complexos(Complexo* cmp, Complexo* cmp2);
#endif // _COMPLEXO_
